#ifndef PROJECT_SIMPLEDBCLI_SIMPLEDBCOMMANDLINEINTERFACE_HPP_
#define PROJECT_SIMPLEDBCLI_SIMPLEDBCOMMANDLINEINTERFACE_HPP_

#include "SimpleDB.hpp"

#include <memory>

class SimpleDbCommandLineInterface {
 public:
  explicit SimpleDbCommandLineInterface(const std::shared_ptr<SimpleDB>& dbInterface);
  void Run();

 private:
  std::shared_ptr<SimpleDB> _dbInterface;

 private:
  std::pair<std::string, std::string> _parseInput(const std::string& inputString);
  void _switchToACtion(const std::string& command, std::string&& value);
  void _listAllValues();
};

#endif  // PROJECT_SIMPLEDBCLI_SIMPLEDBCOMMANDLINEINTERFACE_HPP_
