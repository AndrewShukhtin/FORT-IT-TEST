#ifndef PROJECT_SIMPLE_JSON_ISIMPLE_JSON_PARSER_HPP_
#define PROJECT_SIMPLE_JSON_ISIMPLE_JSON_PARSER_HPP_

#include "SimpleJsonTypes.hpp"

/**
 * @class ISimpleJsonParser
 * 
 * Класс определяющий интерфейс взаимодействие с парсером.
 *
 */

class ISimpleJsonParser {
 public:
/**
 * @brief ParseFromFile
 * 
 * Загрузка в контейнер записей, которые содержались в файле
 * с момента предыдущей сесси взаимодействия с БД.
 * 
 * @param pathToFile Путь к файлу с данными БД.
 * 
 * @return Контейнер содержащий записи БД.
*/
  virtual SimpeJsonContainer ParseFromFile(const std::string& pathToFile) = 0;

/**
 * @brief ParseToFile
 * 
 * Сериализация данных из контейнера, хранящего записи из БД.
 * 
 * @param pathToFile Путь к файлу с данными БД.
 * @param jsonContainer Контейнер с днными из БД.
*/
  virtual void ParseToFile(const std::string& pathToFile, const SimpeJsonContainer& jsonContainer) = 0;
  virtual ~ISimpleJsonParser() = default;
};

#endif  // PROJECT_SIMPLE_JSON_ISIMPLE_JSON_PARSER_HPP_
