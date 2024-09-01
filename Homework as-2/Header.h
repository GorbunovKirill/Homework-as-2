#ifndef HEADER_H
#define HEADER_H

#include <algorithm>
#include <future>
#include <iterator>

template<typename Iterator, typename Func>
void parallel_for_each(Iterator first, Iterator last, Func func) {
    auto length = std::distance(first, last);

    if (length <= 1000) {
        std::for_each(first, last, func);
        return;
    }

    Iterator middle = first;
    std::advance(middle, length / 2);

   
    std::future<void> first_half = std::async(std::launch::async, parallel_for_each<Iterator, Func>, first, middle, func);
    parallel_for_each(middle, last, func);

    first_half.get();
}

#endif 
