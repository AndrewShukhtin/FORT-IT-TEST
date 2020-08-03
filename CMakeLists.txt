cmake_minimum_required(VERSION 3.12)
project(SimpleDB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic")

set(SIMPLE_JSON_TYPES_DIR project/SimpleJsonTypes/)
set(SIMPLE_JSON_TYPES_HEADER project/SimpleJsonTypes/SimpleJsonTypes.hpp)


# SimpleJsonParser
set(SIMPLE_SJON_PARSER_DIR project/SimpleJsonParser/)

set(SIMPLE_SJON_PARSER_HEADERS project/SimpleJsonParser/ISimpleJsonParser.hpp
                               project/SimpleJsonParser/ParserExceptions.hpp
                               project/SimpleJsonParser/SimpleJsonParser.hpp)

set(SIMPLE_SJON_PARSER_SRC project/SimpleJsonParser/ParserExceptions.cpp
                           project/SimpleJsonParser/SimpleJsonParser.cpp)

add_library(SimpleJsonParserLib STATIC ${SIMPLE_SJON_PARSER_HEADERS} ${SIMPLE_JSON_TYPES_HEADER} ${SIMPLE_SJON_PARSER_SRC})

target_include_directories(SimpleJsonParserLib PUBLIC ${SIMPLE_JSON_TYPES_DIR} ${SIMPLE_SJON_PARSER_DIR})


# SimpleDb
set(SIMPLE_DB_DIR project/SimpleDB)

set(SIMPLE_DB_HEADERS project/SimpleDB/ISimpleDB.hpp
                      project/SimpleDB/SimpleDB.hpp
                      project/SimpleDB/SimpleDbConfig.hpp)

set(SIMPLE_DB_SRC project/SimpleDB/SimpleDB.cpp)

add_library(SimpleDBLib STATIC ${SIMPLE_DB_HEADERS} ${SIMPLE_JSON_TYPES_HEADER} ${SIMPLE_DB_SRC})

target_include_directories(SimpleDBLib PUBLIC ${SIMPLE_JSON_TYPES_DIR} ${SIMPLE_DB_DIR})

target_link_libraries(SimpleDBLib PRIVATE SimpleJsonParserLib)


# SimDbCLI
set(SIMPLE_DB_CLI_DIR project/SimpleDbCLI)

set(SIMPLE_DB_CLI_HEADERS project/SimpleDbCLI/SimpleDbCommandLineInterface.hpp)

set(SIMPLE_DB_CLI_SRC project/SimpleDbCLI/SimpleDbCommandLineInterface.cpp)

add_library(SimpleDbCliLib STATIC ${SIMPLE_DB_CLI_HEADERS} ${SIMPLE_DB_CLI_SRC})

target_include_directories(SimpleDBLib PUBLIC ${SIMPLE_JSON_TYPES_DIR} ${SIMPLE_DB_CLI_DIR})

target_link_libraries(SimpleDbCliLib PUBLIC SimpleDBLib SimpleJsonParserLib)


add_executable(simpledb project/main.cpp)

target_link_libraries(simpledb PUBLIC SimpleDbCliLib)
