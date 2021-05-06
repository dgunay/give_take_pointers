#pragma once

#include <queue>
#include <memory>

// Manages a queue of dynamically allocated things, allowing others to take and
// give them.
template <typename T>
class ThingQueue
{
public:
    void give_thing(std::unique_ptr<T> &&thing)
    {
        things.push(std::move(thing));
    }

    auto take_thing()
    {
        auto t = std::move(things.front());
        things.pop();
        return t;
    }

protected:
    std::queue<std::unique_ptr<T>> things;
};
