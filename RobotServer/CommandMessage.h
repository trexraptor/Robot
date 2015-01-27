#pragma once
#include <stddef.h>
#include "ICommunicationMessage.h"

class CommandMessage : public ICommunicationMessage
{
public:
    CommandMessage(int maxSize) : m_maxSize(maxSize)
    {
        m_pInnerBuffer = new char[maxSize];
        m_currentSize = 0;
    }

    bool Validate()
    {
        //To-Do: Add validation;
        return true; 
    }

    unsigned int MaxSize()
    {
        return m_maxSize;
    }

    void SetMessageSize(unsigned int size)
    {
        this->m_currentSize = size;
    }


    void PutDataIntoMessage(const char* data, unsigned size)
    {

    }

    unsigned int GetMessageSize()
    {
        return this->m_currentSize;
    }

    char * GetInternalByteArray()
    {
        return m_pInnerBuffer;
    }

    ~CommandMessage()
    {
        if (m_pInnerBuffer != NULL)
            delete[] m_pInnerBuffer;
    };

private:
    int m_maxSize;
    int m_currentSize;
    char* m_pInnerBuffer;
};