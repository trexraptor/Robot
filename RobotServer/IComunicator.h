#pragma once
#include <memory>
#include "ICommunicationMessage.h"
struct IComunicator
{
    virtual ICommunicationMessage* ReciveMessage() = 0;
    virtual void SendMessage(const ICommunicationMessage* message) = 0;
    ~IComunicator(){};
};