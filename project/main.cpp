#include "SimpleDbCommandLineInterface.hpp"
#include "ParserExceptions.hpp"

#include <iostream>
#include <string>

int main( ) {
  std::shared_ptr<SimpleDB> Db;
  try {
    Db = std::make_shared<SimpleDB>();
  } catch (InvalidFileContent& e) {
    std::cout << e.what() << std::endl;
    return EXIT_FAILURE;
  }

  SimpleDbCommandLineInterface interface(Db);
  interface.Run();
  
  return EXIT_SUCCESS;
}