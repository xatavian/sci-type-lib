#include <sci-type-lib/sci-lib.h>
#include <iostream>

int main(int argc, char const **argv) {
    sci::power u1;
    sci::sqrt_unit<sci::power> u2;
    sci::sq_unit<sci::power> u3;
    sci::cb_unit<sci::power> u4;
    sci::inv_unit<sci::power> u5;
    
    std::cout << u1 << std::endl 
              << u2 << std::endl 
              << u3 << std::endl
              << u4 << std::endl
              << u5 << std::endl ;
    return 0;
}