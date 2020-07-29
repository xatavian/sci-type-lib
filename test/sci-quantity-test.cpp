#include <sci-type-lib/sci-lib.h>
#include <iostream>
#include <string>
#include <sstream>

int main(int argc, char const **argv) {
    // Assignments
    sci::volt u { 5 };
    sci::ampere i { 10 };
    sci::ampere i2 { 10 };

    using namespace sci::literals;
    sci::decawatt p2  = 5.0_daw;
    sci::watt p = 50_w;

    // Comparisons
    std::cout << std::boolalpha;
    std::cout << (p2 == p) << std::endl;
    std::cout << (p == p2) << std::endl;
    std::cout << !(p2 != p) << std::endl;
    std::cout << !(p != p2) << std::endl;
    std::cout << (p2 >= p) << std::endl;
    std::cout << (p >= p2) << std::endl;
    std::cout << (p2 <= p) << std::endl;
    std::cout << (p <= p2) << std::endl;
    std::cout << !(p2 > p) << std::endl;
    std::cout << !(p > p2) << std::endl;
    std::cout << !(p2 < p) << std::endl;
    std::cout << !(p < p2) << std::endl;
    std::cout << (i2 == i) << std::endl;
    std::cout << (i == i2) << std::endl;
    
    // Arithmetics
    
}
