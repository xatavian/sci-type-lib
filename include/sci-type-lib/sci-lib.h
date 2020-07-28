#ifndef SCI_TYPE_LIB_H
#define SCI_TYPE_LIB_H

#include <type_traits>
#include <sci-type-lib/sci-ratio.h>
#include <sci-type-lib/sci-unit.h>
#include <sci-type-lib/sci-quantity.h>
#include <sci-type-lib/sci-literals.h>

namespace sci {    
    

    template<typename Unit, typename Scale, typename T>
    quantity<Unit, T>
    operator+(const quantity<Unit, Scale, T>& v1, const quantity<Unit, Scale, T>& v2) {
        return quantity<Unit, T>(v1.value() + v2.value());
    }
    
    template<typename Unit, typename Scale, typename T>
    quantity<Unit, Scale, T>
    operator-(const quantity<Unit, Scale, T>& v1, const quantity<Unit, Scale, T>& v2) {
        return quantity<Unit, Scale, T>(v1.value() - v2.value());
    }

    template<typename U1, typename U2, typename Scale, typename T>
    quantity<typename detail::mult_helper<U1, U2>::unit, T>
    operator*(const quantity<U1, Scale, T>& v1, const quantity<U2, Scale, T>& v2) {
        return quantity<detail::mult_helper<U1, U2>::unit, T>(v1.value() * v2.value());
    }

    template<typename U1, typename U2, typename Scale, typename T>
    quantity<typename detail::div_helper<U1, U2>::unit, T>
    operator/(const quantity<U1, Scale, T>& v1, const quantity<U2, Scale, T>& v2) {
        return quantity<detail::mult_helper<U1, U2>::unit, T>(v1.value() / v2.value());
    }
}

#endif