#ifndef SCI_TYPE_LIB_RATIO_H
#define SCI_TYPE_LIB_RATIO_H

#include <type_traits>
#include <cmath>
#include <ratio>
#include <tuple>

namespace sci {
    namespace detail {

    }
}

namespace sci {
namespace detail {
    /* From https://stackoverflow.com/a/15404153/8147455 */
    template<std::size_t N, typename... T>
    using static_switch = typename std::tuple_element<N, std::tuple<T...> >::type;
        
    /**
     * @brief Comparison class
     */
    template<typename F>
    struct comp_class {
        using functor = F;

        template<typename T1, typename T2>
        bool eq(const T1& v1, const T2& v2) const {
            return F{}(v1, v2) == 0;
        }
        
        template<typename T1, typename T2>
        bool neq(const T1& v1, const T2& v2) const {
            return F{}(v1, v2) != 0;
        }

        template<typename T1, typename T2>
        bool geq(const T1& v1, const T2& v2) const {
            return F{}(v1, v2) >= 0;
        }
        
        template<typename T1, typename T2>
        bool leq(const T1& v1, const T2& v2) const {
            return F{}(v1, v2) <= 0;
        }

        template<typename T1, typename T2>
        bool gt(const T1& v1, const T2& v2) const {
            return F{}(v1, v2) > 0;
        }

        template<typename T1, typename T2>
        bool lt(const T1& v1, const T2& v2) const {
            return F{}(v1, v2) < 0;
        }
    };

    
    template<typename R1, typename O1, typename R2, typename O2>
    struct comp_auto_select {
        template<typename R1, typename O1, typename R2, typename O2>
        struct general_case {
            template<typename T1, typename T2>
            T1 operator()(const T1& val1, const T2& val2) const{
                using R = std::ratio_divide<R1, R2>;
                using O = std::ratio_divide<
                    std::ratio_subtract<O1, O2>, R2>;

                constexpr long double ratio = static_cast<long double>(R::num) / R::den;
                constexpr long double offset = static_cast<long double>(O::num) / O::den;
                
                return static_cast<T1>(ratio*val1) + static_cast<T1>(offset) - static_cast<T1>(val2);
            }
        };
        
        template<typename R1, typename O1, typename R2, typename O2>
        struct same_ratio_same_offset {
            template<typename T1, typename T2>
            T1 operator()(const T1& val1, const T2& val2) const {
                return val1 - static_cast<T1>(val2);
            }
        };
        
        template<typename R1, typename O1, typename R2, typename O2>
        struct same_ratio_different_offset {
            template<typename T1, typename T2>
            T1 operator()(const T1& val1, const T2& val2) const {
                using O = std::ratio_subtract<O1, O2>;
                constexpr long double offset = static_cast<long double>(O::num) / O::den;
                
                return val1 - static_cast<T1>(val2) + static_cast<T1>(offset);
            }
        };

        template<typename R1, typename O1, typename R2, typename O2>
        struct different_ratio_same_offset {
            template<typename T1, typename T2>
            T1 operator()(const T1& val1, const T2& val2) const {
                using R = std::ratio_divide<R1, R2>;
                constexpr long double ratio = static_cast<long double>(R::num) / R::den;
                
                return static_cast<T1>(ratio*val1) - static_cast<T1>(val2);
            }
        };


        template<std::size_t N, typename R1, typename O1, typename R2, typename O2>
        using f_switch = sci::detail::static_switch<N,
            general_case<R1, O1, R2, O2>, // 0: different offset + different ratio
            same_ratio_different_offset<R1, O1, R2, O2>, // 1: diffenrent offset + same ratio
            different_ratio_same_offset<R1, O1, R2, O2>, // 2: same offset + different ratio
            same_ratio_same_offset<R1, O1, R2, O2>>; // 3: same offset + same ratio

        constexpr static std::size_t ratio_case = std::ratio_equal<R1, R2>::value ? 1 : 0;
        constexpr static std::size_t offset_case = std::ratio_equal<O1, O2>::value ? 1 : 0;
        constexpr static std::size_t switch_case = (1 << offset_case) + ratio_case;

        using type = comp_class<f_switch<switch_case, R1, O1, R2, O2>>;
    };
    
}
} 

        
#endif
