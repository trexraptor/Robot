#pragma once
#include "IComunicationChannel.h"
#include "ConcurentCircularQueue.h"
#include "CommandMessage.h"

class CommandChannel : public IComunicationChannel
{
public:
    CommandChannel();
    virtual void WriteMessage(const ICommunicationMessage*);
    virtual ICommunicationMessage* ReadMessage();
    ~CommandChannel(){};

private:
    ConcurentCircularQueue<CommandMessage>* m_queue;
};