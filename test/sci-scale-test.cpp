#include <sci-type-lib/sci-lib.h>
#include <iostream>

int main(int argc, char const **argv) {
    using r1_type = typename sci::detail::comp_auto_select<std::kilo, std::ratio<0>, std::kilo, std::ratio<0>>::type;
    using r2_type = typename sci::detail::comp_auto_select<std::mega, std::ratio<0>, std::kilo, std::ratio<0>>::type;
    using r3_type = typename sci::detail::comp_auto_select<std::kilo, std::ratio<0>, std::mega, std::ratio<0>>::type;
    
    bool r1 = r1_type{}.eq(1, 1);
    std::cout << std::boolalpha << r1 << std::endl;
    bool r2 = r2_type{}.eq(1, 1000);
    std::cout << std::boolalpha << r2 << std::endl;
    bool r3 = r3_type{}.eq(1000, 1);
    std::cout << std::boolalpha << r3 << std::endl;
    

    return 0;
}