#include <iostream>
#include <vector>
#include <numeric> 
#include "Header.h"

int main() {
    std::vector<int> data(10000);
    std::iota(data.begin(), data.end(), 1);

    
    auto process = [](int& x) { x *= 2; }; 

    std::cout << "Before processing: " << data[0] << ", " << data[1] << ", " 
        << data[2] << ", " << data[3] << std::endl;

   
    parallel_for_each(data.begin(), data.end(), process);

    std::cout << "After processing: " << data[0] << ", " << data[1] << ", " 
        << data[2] << ", " << data[3] << std::endl;

    return 0;
}
