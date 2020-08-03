#ifndef PROJECT_SIMPLEDBCLI_SIMPLEDBCOMMANDLINEINTERFACE_HPP_
#define PROJECT_SIMPLEDBCLI_SIMPLEDBCOMMANDLINEINTERFACE_HPP_

#include "SimpleDB.hpp"

#include <memory>

/**
 * @class SimpleDbCommandLineInterface
 * 
 * Класс определяющий CLI для взаимодействия 
 * конечного польщователя и БД
 * 
 */
class SimpleDbCommandLineInterface {
 public:
  explicit SimpleDbCommandLineInterface(const std::shared_ptr<SimpleDB>& dbInterface);

/**
 * @brief Run
 * 
 * Запуск интерфейса взаимодействия с пользователем.
 * 
 */
  void Run();

 private:
  std::shared_ptr<SimpleDB> _dbInterface;

 private:
 /**
 * @brief parseInput
 * 
 * Парсинг введенной пользователем комманд.
 * 
 * @param inputString Введенный текст пользователем
 * 
 * @return Пара: первый аргумент -- текствое предстваление комманды
 *               второй аргумент -- текстовое представление значение 
 */
  std::pair<std::string, std::string> _parseInput(const std::string& inputString);

/**
 * @brief switchToACtion
 * 
 * Выполнение комманды введенной пользователем,
 * за исключением комманды "exit". Взаимодействие происходит только с БД.
 * 
 * @param command Введенная комманда пользователем
 * @param value   Введенное значение пользователем
 * 
 * @return Пара: первый аргумент -- текствое предстваление комманды
 *               второй аргумент -- текстовое представление значение 
 */
  void _switchToACtion(const std::string& command, std::string&& value);

/**
 * @brief _istAllValues
 * 
 * Вывод всех значений в БД.
 * 
 */
  void _listAllValues();
};

#endif  // PROJECT_SIMPLEDBCLI_SIMPLEDBCOMMANDLINEINTERFACE_HPP_
