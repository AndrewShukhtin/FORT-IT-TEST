#ifndef PROJECT_SIMPLEDB_ISIMPLEDB_HPP_
#define PROJECT_SIMPLEDB_ISIMPLEDB_HPP_

#include <string>

/**
 * @class ISimpleDB
 * 
 * Абстрактный класс определяющий интерфейс БД
 */
class ISimpleDB {
 public:
/**
  * @brief AddValue
  * 
  * Добавление нового значения в БД
  * 
  * @param value Новое значение
  * 
  * @return  Успех/неуспех вставки нового значения
  */
  virtual bool AddValue(std::string&& value) = 0;

/**
  * @brief DeleteValue
  * 
  * Удаление значения из БД. Если значения не существует,
  * то результат вернет false.
  * 
  * @param value значение
  * 
  * @return  Успех/неуспех удаления значения
  */
  virtual bool DeleteValue(const std::string& value) = 0;

/**
  * @brief HasValue
  * 
  * Проверка существования передаваемого значения в БД.
  * Если значения не существует, то вернет false.
  * 
  * @param value значение
  * 
  * @return Есть ли значение в БД
  */
  virtual bool HasValue(const std::string& value) = 0;
  virtual ~ISimpleDB() = default;
};

#endif  // PROJECT_SIMPLEDB_ISIMPLEDB_HPP_
