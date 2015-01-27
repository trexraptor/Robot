#pragma once
#include <deque>
#include <memory>
#include <mutex>

template<class T> class ConcurentQueue
{
public:

    ConcurentQueue()
    {}

    std::shared_ptr<T> Pop()
    {
        std::lock_guard<std::mutex> guard(m_mutex);
        if (m_queue.empty())
        {
            return std::shared_ptr<T>();
        }

        std::shared_ptr<T> data = m_queue.front();
        m_queue.pop_front();
        return data;
    }

    bool TryPop(T& value)
    {
        std::lock_guard<std::mutex> guard(m_mutex);
        if (m_queue.empty())
        {
            return false;
        }

        value = std::move(*m_queue.front());
        m_queue.pop_front();
        return true;
    }

    void Push(T value)
    {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(value)));
        std::lock_guard<std::mutex> guard(m_mutex);
        m_queue.push_back(data);
    }

    void Push(std::shared_ptr<T> value)
    {
        std::lock_guard<std::mutex> guard(m_mutex);
        m_queue.push_back(value);
    }

private:
    std::deque<std::shared_ptr<T>> m_queue;
    std::mutex m_mutex;

};