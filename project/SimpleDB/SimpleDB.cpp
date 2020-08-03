#include "SimpleDbConfig.hpp"
#include "SimpleJsonParser.hpp"
#include "SimpleDB.hpp"

#include <filesystem>

SimpleDB::SimpleDB() : SimpleDB(kDefaultPathToJsonFile) {}

SimpleDB::SimpleDB(const std::string& pathToJsonFile) :
        _pathToJsonFile(pathToJsonFile),
        _jsonContainer{},
        _jsonParser{std::make_unique<SimpleJsonParser>()} {
  _loadDataIfExist();
}

bool SimpleDB::AddValue(std::string&& value) {
  return _jsonContainer.insert(std::move(value)).second;
}

bool SimpleDB::DeleteValue(const std::string& value) {
  if (_jsonContainer.count(value) == 0) {
    return false;
  }

  _jsonContainer.erase(value);

  return true;
}

bool SimpleDB::HasValue(const std::string& value) {
  return _jsonContainer.count(value) == 1 ? true : false;
}

SimpleDB::IteratorAdapter::const_iterator SimpleDB::IteratorAdapter::Begin(const SimpleDB& dataBase) {
  return dataBase._jsonContainer.begin();
}

SimpleDB::IteratorAdapter::const_iterator SimpleDB::IteratorAdapter::Next(const_iterator_reference kIterator) {
  return ++kIterator;
}

SimpleDB::IteratorAdapter::const_iterator SimpleDB::IteratorAdapter::End(const SimpleDB& dataBase) {
  return dataBase._jsonContainer.end();
}

SimpleDB::~SimpleDB() {
  if (!_jsonContainer.empty()) {
    _jsonParser->ParseToFile(_pathToJsonFile, _jsonContainer);
  }
}

void SimpleDB::_loadDataIfExist() {
  std::filesystem::path fsPath(_pathToJsonFile);
  if (!std::filesystem::exists(fsPath)) {
    return;
  }

  _jsonContainer = _jsonParser->ParseFromFile(_pathToJsonFile);
}
