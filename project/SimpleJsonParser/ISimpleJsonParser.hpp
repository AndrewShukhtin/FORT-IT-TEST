#ifndef PROJECT_SIMPLE_JSON_ISIMPLE_JSON_PARSER_HPP_
#define PROJECT_SIMPLE_JSON_ISIMPLE_JSON_PARSER_HPP_

#include "SimpleJsonTypes.hpp"

class ISimpleJsonParser {
 public:
  virtual SimpeJsonContainer ParseFromFile(const std::string& pathToFile) = 0;
  virtual void ParseToFile(const std::string& pathToFile, const SimpeJsonContainer& jsonContainer) = 0;
};

#endif  // PROJECT_SIMPLE_JSON_ISIMPLE_JSON_PARSER_HPP_
