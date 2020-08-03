#include "ParserExceptions.hpp"

const char kInvalidFileContentException[] = "Invalid file content ot formatting";

ParserExceptionBase::ParserExceptionBase(std::string msg) : _msg(msg) {}

const char* ParserExceptionBase::what() const noexcept {
  return _msg.c_str();
}

InvalidFileContent::InvalidFileContent() : ParserExceptionBase(kInvalidFileContentException) {}
