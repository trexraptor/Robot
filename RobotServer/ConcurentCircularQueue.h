#pragma once
#include <stdlib.h>
#include <memory>
#include <mutex>

template<class _T>
class ConcurentCircularQueue
{
public:
    ConcurentCircularQueue(int slotNumber)
    {
        m_slotNumber = slotNumber;
        m_slots = new _T[slotNumber];
        m_HeadIndex = -1;
        m_TailIndex = 0;
    }

    bool TryPush(const _T* value)
    {
        std::lock_guard<std::mutex> guard(m_mutex);
        if (m_TailIndex == m_HeadIndex)
        {
            return false;
        }

        if (m_HeadIndex == -1)
        {
            m_HeadIndex = m_TailIndex;
        }

        m_slots[m_TailIndex] = *value;
        m_TailIndex = (m_TailIndex + 1) % m_slotNumber;
        return true;
    }
     

    bool TryPush(const _T value)
    {
        std::lock_guard<std::mutex> guard(m_mutex);
        if (m_TailIndex == m_HeadIndex)
        {
            return false;
        }

        if (m_HeadIndex == -1)
        {
            m_HeadIndex = m_TailIndex;
        }

        m_slots[m_TailIndex] = value;
        m_TailIndex = (m_TailIndex + 1) % m_slotNumber;
        
        return true;
    }

    bool TryGet(_T& value)
    {
        std::lock_guard<std::mutex> guard(m_mutex);
        if (m_HeadIndex == -1)
        {
            return false;
        }

        value = m_slots[m_HeadIndex];
        m_HeadIndex = (m_HeadIndex + 1) % m_slotNumber == m_TailIndex ? -1 : (m_HeadIndex + 1) % m_slotNumber;
        return true;
    }

    ~ConcurentCircularQueue()
    {
        std::lock_guard<std::mutex> guard(m_mutex);
        if (m_slots != NULL)
        {
            delete[] m_slots;
        }
    };

private:
    int m_HeadIndex;
    int m_TailIndex;
    _T* m_slots;
    int m_slotNumber;
    std::mutex m_mutex;

};