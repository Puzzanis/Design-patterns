#pragma once
#include <iostream>


class LogCommand {
public:
    virtual ~LogCommand() = default;
    virtual void print(const std::string& message) = 0;
};

class LogToConsol : public LogCommand
{
public:
    void print(const std::string& message) override
    {
        std::cout << "print to Consol: " << message << std::endl;
    }
   
};

class LogToFile :public LogCommand
{
public:
    void print(const std::string& message) override
    {
        std::cout << "print to File: " << message << std::endl;
    }
};

class PrintAnywhere
{
private:
    const std::string& message_;

public:
    PrintAnywhere(const std::string& message) : message_{ message } {}
    void print(LogCommand& log)
    {
        log.print(message_);
    }
};
