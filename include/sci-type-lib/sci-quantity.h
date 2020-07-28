#ifndef SCI_TYPE_LIB_QUANTITY_H
#define SCI_TYPE_LIB_QUANTITY_H

#include <ratio>
#include <type_traits>
#include <sci-type-lib/sci-unit.h>
#include <sci-type-lib/sci-ratio.h>

namespace sci {
    namespace detail {
        /**
         * @brief Represents a value with a given unit. Cannot be compared or be part
         *        of an arithmetic operation with another quantity with a different unit.
         * 
         * @param Unit The sci::unit of the value (sci::temperature, sci::mass, etc. or a 
         *             user-defined unit)
         * @param R Ratio of the value compared to the common (or SI) unit
         *          (eg. kg as a ratio of 1000 compared to g). Expressed as a
         *          std::ratio<N, D>.
         * @param Offset Offset of the value compared to the common (or SI) unit
         *        (eg. °Celsius has an offset of 273.15 compared to °Kelvin). Expressed 
         *        as a std::ratio<N, D>.
         * @param T Type of the underlying value of the quantity. Defaults as long double. 
         */
        template<typename Unit, typename R = std::ratio<1>, 
                 typename Offset = std::ratio<0>, typename T = long double> 
        class quantity {
        public:
            using unit = Unit;
            using scale = R;
            using offset = Offset;
            using value_type = T;

            explicit quantity(T x) 
                : v(x) {

            }

            value_type value() const {
                return v;
            }

            /*
            operator value_type() const { 
                return v; 
            }
            */

            template<typename R2, typename O2, typename T2>
            bool operator==(const quantity<unit, R2, O2, T2>& other) const {
                using comp = typename detail::comp_auto_select<scale, offset, R2, O2>::type;
                return comp{}.eq(v, other.value());
            }
            
            template<typename R2, typename O2, typename T2>
            bool operator!=(const quantity<unit, R2, O2, T2>& other) const {
                using comp = typename detail::comp_auto_select<scale, offset, R2, O2>::type;
                return comp{}.neq(v, other.value());
            }

            template<typename R2, typename O2, typename T2>
            bool operator<=(const quantity<unit, R2, O2, T2>& other) const {
                using comp = typename detail::comp_auto_select<scale, offset, R2, O2>::type;
                return comp{}.leq(v, other.value());            }
            
            template<typename R2, typename O2, typename T2>
            bool operator>=(const quantity<unit, R2, O2, T2>& other) const {
                using comp = typename detail::comp_auto_select<scale, offset, R2, O2>::type;
                return comp{}.geq(v, other.value());
            }
            
            template<typename R2, typename O2, typename T2>
            bool operator<(const quantity<unit, R2, O2, T2>& other) const {
                using comp = typename detail::comp_auto_select<scale, offset, R2, O2>::type;
                return comp{}.lt(v, other.value());
            }

            template<typename R2, typename O2, typename T2>
            bool operator>(const quantity<unit, R2, O2, T2>& other) const {
                using comp = typename detail::comp_auto_select<scale, offset, R2, O2>::type;
                return comp{}.gt(v, other.value());
            }
            
        private:
            value_type v;
        };
    }

    template<typename Unit, typename Scale = std::ratio<1>, typename Offset = std::ratio<0>, typename T = long double>
    using quantity = detail::quantity<Unit, Scale, Offset, T>;

    using no_unit  = quantity<scalar>;

    using ton       = quantity<mass, std::mega>;
    using kilogram  = quantity<mass, std::kilo>;
    using hectogram = quantity<mass, std::hecto>;
    using decagram  = quantity<mass, std::deca>;
    using gram      = quantity<mass>;
    using decigram  = quantity<mass, std::deci>;
    using centigram = quantity<mass, std::centi>;
    using milligram = quantity<mass, std::milli>;
    
    using kilometer = quantity<length, std::kilo>;
    using hectometer = quantity<length, std::hecto>;
    using decameter = quantity<length, std::deca>;
    using meter    = quantity<length>;
    using decimeter = quantity<length, std::deci>;
    using centimeter = quantity<length, std::centi>;
    using millimeter = quantity<length, std::milli>;
    
    using kelvin   = quantity<temperature>;
    // T(K) = T(C) + 273.15
    using celsius   = quantity<temperature, std::ratio<1>, std::ratio<27315, 100>>;
    // T(K) = (5*9)*T(F) + 459.67*5/9
    using fahrenheit   = quantity<temperature, std::ratio<5, 9>, std::ratio<45967 * 5, 100 * 9>>;
    
    using ampere   = quantity<intensity>;
    using mol      = quantity<mass_quantity>;
    using candela  = quantity<luminosity>;
    
    using gigawatt = quantity<power, std::giga>;
    using megawatt = quantity<power, std::mega>;
    using kilowatt = quantity<power, std::kilo>;
    using hectowatt = quantity<power, std::hecto>;
    using decawatt = quantity<power, std::deca>;
    using watt     = quantity<power>;
    using deciwatt     = quantity<power, std::deci>;
    using centiwatt     = quantity<power, std::centi>;
    using milliwatt     = quantity<power, std::milli>;
    
    using gigavolt = quantity<voltage, std::giga>;
    using megavolt = quantity<voltage, std::mega>;
    using kilovolt = quantity<voltage, std::kilo>;
    using hectovolt = quantity<voltage, std::hecto>;
    using decavolt = quantity<voltage, std::deca>;
    using volt = quantity<voltage>;
    using decivolt = quantity<voltage, std::deci>;
    using centivolt = quantity<voltage, std::centi>;
    using millivolt = quantity<voltage, std::milli>;
} // namespace sci 


#endif // SCI_TYPE_LIB_QUANTITY_H
