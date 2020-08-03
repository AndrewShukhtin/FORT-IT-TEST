#ifndef PROJECT_SIMPLE_JSON_SIMPLE_JSON_PARSER_HPP_
#define PROJECT_SIMPLE_JSON_SIMPLE_JSON_PARSER_HPP_

#include "ISimpleJsonParser.hpp"

/**
 * @class SimpleJsonParser
 * 
 * Класс реализующий интерфейс взаимодействие с парсером.
 *
 */

class SimpleJsonParser : public ISimpleJsonParser {
 public:
/**
 * @brief ParseFromFile
 * 
 * @see ISimpleJsonParser::ParseFromFile
 */
  SimpeJsonContainer ParseFromFile(const std::string& pathToFile) override;

/**
 * @brief ParseToFile
 * 
 * @see ISimpleJsonParser::ParseToFile
 */
  void ParseToFile(const std::string& pathToFile, const SimpeJsonContainer& jsonContainer) override;

 private:
 /**
 * @brief getFileContent
 * 
 * Получения сожержания файла.
 * 
 * @param pathToFile Путь к файлу.
 * 
 * @return Содержание файла.
 */
  std::string _getFileContent(const std::string& pathToFile);

/**
 * @brief validateFileContent
 * 
 * Валидирование сериализованных данных.
 * 
 * @param fileContent Содержание файла.
 * 
 * @exception InvalidFileContent
 * 
 * @see ParserExceprion
 */
  void _validateFileContent(const std::string& fileContent);
};

#endif  // PROJECT_SIMPLE_JSON_SIMPLE_JSON_PARSER_HPP_
