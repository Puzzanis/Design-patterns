#pragma once

#include <iostream>
#include <string>

enum class Type
{
    warning,
    error,
    fatalError,
    unknownMessage

};


class LogMessage
{
private:
    Type mType_;
    std::string message_;
public:
    LogMessage(Type type, const std::string& message) :mType_(type), message_(message) {}
    Type type() { return mType_; }
    const std::string& message() { return message_; }
};