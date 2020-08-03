#ifndef PROJECT_SIMPLEJSONPARSER_PARSEREXCEPTIONS_HPP_
#define PROJECT_SIMPLEJSONPARSER_PARSEREXCEPTIONS_HPP_

#include <exception>
#include <string>

/**
 * @class ParserExceptionBase
 * 
 * Базовый класс исключений парсера.
 */

class ParserExceptionBase : public std::exception {
 public:
  explicit ParserExceptionBase(std::string msg);

  const char* what() const noexcept override;

 protected:
  std::string _msg;
};

/**
 * @class InvalidFileContent
 * 
 * Исключение связанное плохо сериализованным файлом,
 * невалинными данными или неправильным форматом.
 */

class InvalidFileContent : public ParserExceptionBase {
 public:
  InvalidFileContent();
};

#endif  // PROJECT_SIMPLEJSONPARSER_PARSEREXCEPTIONS_HPP_
