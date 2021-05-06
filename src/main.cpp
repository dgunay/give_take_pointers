#include "ThingQueue.h"

#include <memory>
#include <iostream>

int main(int argc, char const *argv[])
{
    auto ptr = std::make_unique<int>(5);
    ThingQueue<int> q;

    std::cout << "Giving " << *ptr << std::endl;

    q.give_thing(std::move(ptr));

    auto taken = q.take_thing();
    std::cout << "Got back " << *taken << std::endl;

    return 0;
}
