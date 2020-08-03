#ifndef PROJECT_SIMPLEDB_ISIMPLEDB_HPP_
#define PROJECT_SIMPLEDB_ISIMPLEDB_HPP_

#include <string>

class ISimpleDB {
 public:
  virtual bool AddValue(std::string&& value) = 0;
  virtual bool DeleteValue(const std::string& value) = 0;
  virtual bool HasValue(const std::string& value) = 0;
  virtual ~ISimpleDB() = default;
};

#endif  // PROJECT_SIMPLEDB_ISIMPLEDB_HPP_
