/*
 * Coursework 3 sem, KTSO-02-20
 * Coded by:
 * Arkadskov Arseniy
 * Kasiev Ismail
 * */
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <chrono>
#include "rk.h"
#include "bm.h"
#include "kmp.h"

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
    std::cout << "\nThe first string:\n";
    auto timer_first = std::chrono::steady_clock::now();
    search.start(std::string("123456"));
    std::cout <<"\nTime elapsed(ms) : " << since(timer_first).count() << "\n";

    std::cout << "\nString in the middle:\n";
    auto timer_start = std::chrono::steady_clock::now();
    search.start(std::string("alex2004")); //somewhere in the middle (#4232644)
    std::cout << "\nTime elapsed(ms) : " << since(timer_start).count() << "\n";

    std::cout << "\nThe last string:\n";
    auto timer_start1 = std::chrono::steady_clock::now();
    search.start(std::string("sagar")); //last string(#9692420)
    std::cout << "\nTime elapsed(ms) : " << since(timer_start1).count() << "\n";

//    BM_Search bm;
//    std::cout << "\n\t---Boyer-Moor---";
//    std::cout << "\nThe first string:\n";
//    auto timer_bm1 = std::chrono::steady_clock::now();
//    bm.start(std::string("123456"));
//    std::cout <<"\nTime elapsed(ms) : " << since(timer_bm1).count() << "\n";
//
//    std::cout << "\nString in the middle:\n";
//    auto timer_bm2 = std::chrono::steady_clock::now();
//    bm.start(std::string("cassandra"));
////    bm.start(std::string("alex2004")); //somewhere in the middle (#4232644)
//    std::cout << "\nTime elapsed(ms) : " << since(timer_bm2).count() << "\n";
//
//    std::cout << "\nThe last string:\n";
//    auto timer_bm3 = std::chrono::steady_clock::now();
//    bm.start(std::string("sagar")); //last string(#9692420)
//    std::cout << "\nTime elapsed(ms) : " << since(timer_bm3).count() << "\n";

    std::cout << "\n\t ---Knutt-Morris-Pratt---";
    KMP kmp;
    std::cout << "\nThe first string:\n";
    auto timer_kmp1 = std::chrono::steady_clock::now();
    kmp.search(std::string("123456"));
    std::cout << "Time elapsed(ms) : " << since(timer_kmp1).count() << '\n';

    std::cout << "\nString in the middle:\n";
    auto timer_kmp2 = std::chrono::steady_clock::now();
    kmp.search(std::string("alex2004"));
    std::cout << "Time elapsed(ms) : " << since(timer_kmp2).count() << '\n';

    std::cout << "\nThe last string:\n";
    auto timer_kmp3 = std::chrono::steady_clock::now();
    kmp.search(std::string("sagar"));
    std::cout << "Time elapsed(ms) : " << since(timer_kmp3).count() << '\n';
}

int main()
{
    timeTests();

    return 0;
}
