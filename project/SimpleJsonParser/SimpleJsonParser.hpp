#ifndef PROJECT_SIMPLE_JSON_SIMPLE_JSON_PARSER_HPP_
#define PROJECT_SIMPLE_JSON_SIMPLE_JSON_PARSER_HPP_

#include "ISimpleJsonParser.hpp"

class SimpleJsonParser : public ISimpleJsonParser {
 public:
  SimpeJsonContainer ParseFromFile(const std::string& pathToFile) override;
  void ParseToFile(const std::string& pathToFile, const SimpeJsonContainer& jsonContainer) override;

 private:
  // TODO(vendroid): Добавить приватные методы
  std::string _getFileContent(const std::string& pathToFile);
  void _validateFileContent(const std::string& fileContent);
};

#endif  // PROJECT_SIMPLE_JSON_SIMPLE_JSON_PARSER_HPP_
