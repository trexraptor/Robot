#include "CommandChannel.h"
#include "CommandMessage.h"
#include <memory>

CommandChannel::CommandChannel()
{
    this->m_queue = new ConcurentCircularQueue<CommandMessage>(10000);
}


ICommunicationMessage* CommandChannel::ReadMessage()
{
    ICommunicationMessage* value = NULL;
    m_queue->TryGet(&(*value));

    return value;
}


void CommandChannel::WriteMessage(const ICommunicationMessage* value)
{

    CommandMessage* message = dynamic_cast<CommandMessage*>(value);
    std::shared_ptr<CommandMessage> data(std::make_shared<CommandMessage>(std::move(value)));
    m_queue->Push(data);
}