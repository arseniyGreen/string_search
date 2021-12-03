/*
 * Coursework 3 sem, KTSO-02-20
 * Coded by:
 * Arkadskov Arseniy
 * Kasiev Ismail
 * */

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <chrono>
#include "rk.h"

template<
    class result_t = std::chrono::milliseconds,
    class clock_t = std::chrono::steady_clock,
    class duration_t = std::chrono::milliseconds
>
auto since(std::chrono::time_point<clock_t, duration_t> const& start)
{
    return std::chrono::duration_cast<result_t>(clock_t::now() - start);
}

void timeTests()
{
    std::cout << "\n\t---Rabin-Karp---";
    std::cout << "\n\tFull coincidence search:\n";
    Search search;
    std::cout << "\n\tThe first string:\n";
    auto timer_first = std::chrono::steady_clock::now();
    search.start(std::string("42545219"));
    std::cout <<"\nTime elapsed(ms) : " << since(timer_first).count() << "\n";

    std::cout << "\n\tString in the middle:\n";
    auto timer_start = std::chrono::steady_clock::now();
    search.start(std::string("82959854")); //somewhere in the middle (#4232644)
    std::cout << "\nTime elapsed(ms) : " << since(timer_start).count() << "\n";

    std::cout << "\n\tThe last string:\n";
    auto timer_start1 = std::chrono::steady_clock::now();
    search.start(std::string("28699498")); //last string(#9692420)
    std::cout << "\nTime elapsed(ms) : " << since(timer_start1).count() << "\n";
}

int main()
{
    timeTests();

    return 0;
}
