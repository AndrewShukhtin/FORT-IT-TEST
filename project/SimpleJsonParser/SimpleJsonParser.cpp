#include "SimpleJsonParser.hpp"
#include "ParserExceptions.hpp"

#include <regex>
#include <fstream>
#include <streambuf>

const char kDataFiled[] = "\"data\"";
const char kIdFiled[] = "\"_id\"";

const char kLeftStraightBracket  = '[';
const char kRightStraightBracket = ']';
const char kLeftCurlyBracket     = '{';
const char kRightCurlyBracket    = '}';
const char kComma                = ',';
const char kColon                = ':';
const char kSpace                = ' ';
const char kQuote                = '\"';


SimpeJsonContainer SimpleJsonParser::ParseFromFile(const std::string& pathToFile) {
  std::string fileContent = _getFileContent(pathToFile);
  _validateFileContent(fileContent);

  std::regex pattern("\"data\"\\s:\\s\"(\\w+)\"");
  auto words_begin = std::sregex_iterator(fileContent.begin(), fileContent.end(), pattern);
  auto words_end = std::sregex_iterator();

  SimpeJsonContainer jsonDataContainer;
  for (auto reg_iter = words_begin; reg_iter != words_end; ++reg_iter) {
    std::smatch math = *reg_iter;
    std::string value = math.str(1);
    jsonDataContainer.insert(value);
  }

  return jsonDataContainer;
}

void SimpleJsonParser::ParseToFile(const std::string& pathToFile, const SimpeJsonContainer& jsonContainer) {
  std::ofstream file(pathToFile);

  file << kLeftStraightBracket << kLeftCurlyBracket << std::endl;
  std::uint64_t id = 0;
  for (const auto& value : jsonContainer) {
    file << kLeftCurlyBracket << std::endl;
    file << kIdFiled << kSpace << kColon << kSpace << kQuote << ++id << kQuote << kComma << std::endl;
    file << kDataFiled << kSpace << kColon << kSpace << kQuote << value << kQuote << std::endl;
    file << kRightCurlyBracket;

    if (id != jsonContainer.size()) {
      file << kComma;
    }
    file << std::endl;
  }
  file << kRightCurlyBracket << kRightStraightBracket << std::endl;
}

std::string SimpleJsonParser::_getFileContent(const std::string& pathToFile) {
  std::ifstream file(pathToFile);

  file.seekg(0, std::ios::end);
  std::string fileContent;
  fileContent.reserve(file.tellg());
  file.seekg(0, std::ios::beg);

  fileContent.assign(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>());

  return fileContent;
}

void SimpleJsonParser::_validateFileContent(const std::string& fileContent) {
  if (fileContent.front() != kLeftStraightBracket
    && fileContent[1] != kLeftCurlyBracket
    && fileContent[fileContent.size() - 2] != kRightCurlyBracket
    && fileContent.back() != kRightStraightBracket) {
     throw InvalidFileContent();
  }
}
