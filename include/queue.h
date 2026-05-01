#ifndef THREAD_QUEUE_H
#define THREAD_QUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    std::queue<T> q;
    std::mutex mtx;
    std::condition_variable cv;

public:
    void push(const T& value)
    {
        std::unique_lock<std::mutex> lock(mtx);
        q.push(value);
        cv.notify_one();
    }

    T pop()
    {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [this]{
            return !q.empty();
        });

        T val = q.front();
        q.pop();
        return val;
    }
};

#endif