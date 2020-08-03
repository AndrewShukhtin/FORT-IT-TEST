#include "SimpleDbCommandLineInterface.hpp"
#include "ParserExceptions.hpp"

#include <regex>
#include <iostream>

const char kWelcomeMessage[] = "Welcome to SimpleDb CLI!";
const char kUsageMessage[]   =  "Usage:\n"
                                " * add <value> -- add value in SimpleDB\n"
                                " * has  <value> -- check if value in SimpleDB\n"
                                " * delete <value> -- delete value in SimpleDB\n"
                                " * listall -- list all values in SimpleDB\n"
                                " * exit -- exit from CLI\n\n"
                                "SimpleDb@CLI>";


SimpleDbCommandLineInterface::SimpleDbCommandLineInterface(const std::shared_ptr<SimpleDB>& dbInterface)
  : _dbInterface{dbInterface} {}

void SimpleDbCommandLineInterface::Run() {
  std::cout << kWelcomeMessage << std::endl;
  std::cout << kUsageMessage;

  const std::string kExitCmd = "exit";
  while (true) {
    std::string inputString;
    std::getline(std::cin, inputString);
    auto[command, value] = _parseInput(inputString);
    _switchToACtion(command, std::move(value));
    if (command == kExitCmd) {
      break;
    }
    std::cout << kUsageMessage;
  }
}

std::pair<std::string, std::string> SimpleDbCommandLineInterface::_parseInput(const std::string& inputString) {
  std::regex firstPattern("^\\b(add|has|delete|listall|exit)\\b");
  std::smatch firstMatch;
  std::pair<std::string, std::string> result;

  if (std::regex_search(inputString, firstMatch, firstPattern) && firstMatch.size() > 1) {
    result.first = firstMatch.str(1);
  }

  std::regex secondPattern("^\\b(add|has|delete|listall|exit)\\b\\s(.*)");
  std::smatch secondMatch;
  if (std::regex_search(inputString, secondMatch, secondPattern) && secondMatch.size() > 1) {
    result.second = secondMatch.str(2);
  }

  return result;
}

void SimpleDbCommandLineInterface::_switchToACtion(const std::string& command, std::string&& value) {
  const std::string kAddCmd      = "add";
  const std::string kHasCmd      = "has";
  const std::string kDeleteCmd   = "delete";
  const std::string kListaAllCmd = "listall";

  if (command == kAddCmd) {
    if (!_dbInterface->AddValue(std::move(value))) {
      std::cout << "Inserted value already exists" << std::endl;
    }
    std::cout << "Value inserted" <<std::endl;
  } else if (command == kHasCmd) {
    if (!_dbInterface->HasValue(value)) {
      std::cout << "Value exists" << std::endl;
    }
    std::cout << "Value does not exist" <<std::endl;
  } else if (command == kDeleteCmd) {
    if (!_dbInterface->DeleteValue(value)) {
      std::cout << "Deleted value does not exist" << std::endl;
    }
    std::cout << "Value successfully deleted" <<std::endl;
  } else if (command == kListaAllCmd) {
    _listAllValues();
  }
}

void SimpleDbCommandLineInterface::_listAllValues() {
  auto begin = SimpleDB::IteratorAdapter::Begin(*_dbInterface);
  auto end = SimpleDB::IteratorAdapter::End(*_dbInterface);

  std::size_t idx = 0;
  for (auto iter = begin; iter != end; SimpleDB::IteratorAdapter::Next(iter)) {
    std::cout << "{ \"idx\" : " << ++idx << ", " << "\"value\": " <<  *iter << "}" <<std::endl;
  }
}
