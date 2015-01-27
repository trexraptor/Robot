#pragma once


struct ICommunicationMessage
{
    virtual unsigned int MaxSize() = 0;
    virtual bool Validate() = 0;
    virtual char* GetInternalByteArray() = 0;
    virtual void SetMessageSize(unsigned int size) = 0;
    virtual unsigned int GetMessageSize() = 0;
    virtual ~ICommunicationMessage(){};
};