#pragma once
#include <memory>
#include "ICommunicationMessage.h"

struct IComunicationChannel
{
    virtual void WriteMessage(const void* message, int lenght) = 0;
    virtual void WriteMessage(const ICommunicationMessage*) = 0;
    virtual ICommunicationMessage* ReadMessage() = 0;
    virtual ~IComunicationChannel() {};
};