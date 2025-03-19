#pragma once
#include "LogMessage.h"

class LogHandler
{
public:
    virtual ~LogHandler() {};
    virtual void receiveMessage(LogMessage* logMessage) = 0;
    virtual void setNext(LogHandler* handler) = 0;
};