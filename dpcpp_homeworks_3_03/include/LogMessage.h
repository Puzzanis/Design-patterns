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
public:
    virtual void set_next_handler(LogMessage* handler) = 0;
    virtual void type(Type t) const = 0;
    virtual const std::string_view& message() const = 0;
    
};