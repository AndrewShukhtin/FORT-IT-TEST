#ifndef PROJECT_SIMPLEDB_SIMPLEDB_HPP_
#define PROJECT_SIMPLEDB_SIMPLEDB_HPP_

#include "ISimpleDB.hpp"
#include "SimpleJsonTypes.hpp"

#include <memory>

class ISimpleJsonParser;
class SimpleDbIterator;

class SimpleDB : public ISimpleDB {
 public:
  SimpleDB();
  explicit SimpleDB(const std::string& pathToJsonFile);

  bool AddValue(std::string&& value) override;
  bool DeleteValue(const std::string& value) override;
  bool HasValue(const std::string& value) override;

  class IteratorAdapter;
  friend class IteratorAdapter;

  class IteratorAdapter {
   public:
    using const_iterator = SimpeJsonContainer::const_iterator;
    using const_iterator_reference = SimpeJsonContainer::const_iterator&;

    static const_iterator Begin(const SimpleDB& dataBase);
    static const_iterator Next(const_iterator_reference kIterator);
    static const_iterator End(const SimpleDB& dataBase);
  };

  ~SimpleDB();

 private:
  void _loadDataIfExist();

 private:
  const std::string _pathToJsonFile;
  SimpeJsonContainer _jsonContainer;
  std::unique_ptr<ISimpleJsonParser> _jsonParser;
};

#endif  // PROJECT_SIMPLEDB_SIMPLEDB_HPP_
