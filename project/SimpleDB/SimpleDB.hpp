#ifndef PROJECT_SIMPLEDB_SIMPLEDB_HPP_
#define PROJECT_SIMPLEDB_SIMPLEDB_HPP_

#include "ISimpleDB.hpp"
#include "SimpleJsonTypes.hpp"

#include <memory>

class ISimpleJsonParser;
class SimpleDbIterator;

/**
 * @class SimpleDB
 * 
 * Класс реализующий интерфейс класса ISimpleDB.
 * @see Ref ISimpleDB
 */

class SimpleDB : public ISimpleDB {
 public:
  SimpleDB();
  explicit SimpleDB(const std::string& pathToJsonFile);


/**
  * @brief AddValue
  * 
  * @see ISimpleDB::AddValue
  */
  bool AddValue(std::string&& value) override;

/**
  * @brief DeleteValue
  * 
  * @see ISimpleDB::DeleteValue
  */
  bool DeleteValue(const std::string& value) override;

/**
  * @brief HasValue
  * 
  * @see ISimpleDB::HasValue
  */
  bool HasValue(const std::string& value) override;

  class IteratorAdapter;
  friend class IteratorAdapter;

/**
 * @class IteratorAdapter
 * 
 * Класс адаптер для обращения к внутреннимему устройсву БД 
 * и итерирования по данным.
 * 
 * @see Ref ISimpleDB
 */
  class IteratorAdapter {
   public:
    using const_iterator = SimpeJsonContainer::const_iterator;
    using const_iterator_reference = SimpeJsonContainer::const_iterator&;

/**
  * @brief Begin
  * 
  * Вычисление итератора на начало данных в БД
  * 
  * @param dataBase БД
  * 
  * @return  Итератор на первую запись в БД
  */
    static const_iterator Begin(const SimpleDB& dataBase);

/**
  * @brief Next
  * 
  * Инкримент итератора
  * 
  * @param dataBase Итератор на текущую запись в БД
  * 
  * @return  Итератор на следующую запись в БД
  */
    static const_iterator Next(const_iterator_reference kIterator);

/**
  * @brief End
  * 
  * Вычисление итератора на итератор после последеней записи в БД
  * 
  * @param dataBase БД
  * 
  * @return  Итератор после последеней записи в БД
  */
    static const_iterator End(const SimpleDB& dataBase);
  };

  ~SimpleDB();

 private:
 /**
  * @brief _loadDataIfExist
  * @private
  * 
  * Загрузка данныз БД из файла
  * 
  */
  void _loadDataIfExist();

 private:
  const std::string _pathToJsonFile;
  SimpeJsonContainer _jsonContainer;
  std::unique_ptr<ISimpleJsonParser> _jsonParser;
};

#endif  // PROJECT_SIMPLEDB_SIMPLEDB_HPP_
