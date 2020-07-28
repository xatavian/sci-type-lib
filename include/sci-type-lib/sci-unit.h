#ifndef SCI_TYPE_LIB_UNIT_H
#define SCI_TYPE_LIB_UNIT_H

#include <ratio>
#include <type_traits>
#include <cstdint>

namespace sci {
    namespace detail {
        template<std::intmax_t num, std::intmax_t den>
        using ratio = std::ratio<num, den>;

        template<typename R>
        using inv_ratio = typename std::conditional<
            R::num == 0, R, std::ratio<R::den, R::num>>::type;


        template<typename M, typename S, typename L, typename K,
                 typename I, typename Mol, typename Cd>
        struct unit {
            using mass = M;
            using time = S;
            using length = L;
            using temperature = K;
            using intensity = I;
            using mol = Mol;
            using luminosity = Cd;
        };

        template<int M, int S, int L, int K, int I, int Mol, int Cd>
        using make_int_unit = unit<std::ratio<M>, std::ratio<S>, std::ratio<L>, std::ratio<K>, 
                                   std::ratio<I>, std::ratio<Mol>, std::ratio<Cd>>;


        template<typename U1, typename U2>
        struct mult_helper {
            using unit = unit<
                std::ratio_add<typename U1::mass, typename U2::mass>,
                std::ratio_add<typename U1::time, typename U2::time>,  
                std::ratio_add<typename U1::length, typename U2::length>,
                std::ratio_add<typename U1::temperature, typename U2::temperature>,
                std::ratio_add<typename U1::intensity, typename U2::intensity>,
                std::ratio_add<typename U1::mol, typename U2::mol>,
                std::ratio_add<typename U1::luminosity, typename U2::luminosity>>;
        };
        
        template<typename U1, typename U2>
        struct div_helper {
            using unit = unit<
                std::ratio_subtract<typename U1::mass, typename U2::mass>,
                std::ratio_subtract<typename U1::time, typename U2::time>,  
                std::ratio_subtract<typename U1::length, typename U2::length>,
                std::ratio_subtract<typename U1::temperature, typename U2::temperature>,
                std::ratio_subtract<typename U1::intensity, typename U2::intensity>,
                std::ratio_subtract<typename U1::mol, typename U2::mol>,
                std::ratio_subtract<typename U1::luminosity, typename U2::luminosity>>;
        };

        template<typename U, int i>
        struct sq_helper {
            using unit = typename mult_helper<typename sq_helper<U, i-1>::unit, U>::unit;
        };
        
        template<typename U>
        struct sq_helper<U, 1> {
            using unit = U;
        };
        
        template<typename U>
        struct sq_helper<U, 0> {
            using unit = U;
        };
        
        /*
        template<typename U, int i>
        struct sq_helper<U, i> {
            
            unit<
                std::ratio_multiply<typename U1::mass, std::ratio<2>>,
                std::ratio_multiply<typename U1::time, std::ratio<2>>,
                std::ratio_multiply<typename U1::length, std::ratio<2>>,
                std::ratio_multiply<typename U1::temperature, std::ratio<2>>,
                std::ratio_multiply<typename U1::intensity, std::ratio<2>>,
                std::ratio_multiply<typename U1::mol, std::ratio<2>>,
                std::ratio_multiply<typename U1::luminosity, std::ratio<2>>
            >; 
        }; */

        template<typename U>
        struct inv_helper {
            using unit = unit<
                inv_ratio<typename U::mass>, inv_ratio<typename U::time>,
                inv_ratio<typename U::length>, inv_ratio<typename U::temperature>,
                inv_ratio<typename U::intensity>, inv_ratio<typename U::mol>,
                inv_ratio<typename U::luminosity>>;
        };
        
        template<typename U, int scale>
        struct num_div_helper {
        private:
            using scale_r = std::ratio<scale, 1>;
        
        public:
            using unit = unit<
                std::ratio_divide<typename U::mass, scale_r>, 
                std::ratio_divide<typename U::time, scale_r>, 
                std::ratio_divide<typename U::length, scale_r>, 
                std::ratio_divide<typename U::temperature, scale_r>, 
                std::ratio_divide<typename U::intensity, scale_r>, 
                std::ratio_divide<typename U::mol, scale_r>, 
                std::ratio_divide<typename U::luminosity, scale_r>>;
        };
    }
    
    template<typename M, typename S, typename L, typename K, typename I, typename Mol, typename Cd>
    using unit = detail::unit<M, S, L, K, I, Mol, Cd>;
        
    template<int M, int S, int L, int K, int I, int Mol, int Cd>
    using int_unit = detail::make_int_unit<M, S, L, K, I, Mol, Cd>;

    template<typename U>
    using inv_unit = typename detail::inv_helper<U>::unit;

    template<typename U1, typename U2>
    using mult_unit = typename detail::mult_helper<U1, U2>::unit;

    template<typename U>     
    using sq_unit = typename detail::sq_helper<U, 2>::unit;
    
    template<typename U>     
    using cb_unit = typename detail::sq_helper<U, 3>::unit;
    
    template<typename U1, typename U2>
    using div_unit = typename detail::div_helper<U1, U2>::unit;
    
    template<typename U>
    using sqrt_unit = typename detail::num_div_helper<U, 2>::unit;

    template<typename T1, typename T2>
    struct is_same_unit : public std::false_type {};

    template<typename M, typename S, typename L, typename K, typename I, typename Mol, typename Cd>
    struct is_same_unit<unit<M,S,L, K, I, Mol, Cd>, unit<M,S,L, K, I, Mol, Cd>> 
        : public std::true_type {};

    using scalar        = int_unit<0, 0, 0, 0, 0, 0, 0>;
    using mass          = int_unit<1, 0, 0, 0, 0, 0, 0>;
    using time          = int_unit<0, 1, 0, 0, 0, 0, 0>;
    using length        = int_unit<0, 0, 1, 0, 0, 0, 0>;
    using temperature   = int_unit<0, 0, 0, 1, 0, 0, 0>;
    using intensity     = int_unit<0, 0, 0, 0, 1, 0, 0>;
    using mass_quantity = int_unit<0, 0, 0, 0, 0, 1, 0>;
    using luminosity    = int_unit<0, 0, 0, 0, 0, 0, 1>;

    using velocity      = int_unit<0, 1, -1, 0, 0, 0, 0>;
    using acceleration  = int_unit<0, 1, -2, 0, 0, 0, 0>;
    using force         = int_unit<1, 1, -2, 0, 0, 0, 0>;
    using momentum      = int_unit<1, 1, -1, 0, 0, 0, 0>;

    using power         = int_unit<1, -3, 2, 0, 0, 0, 0>;
    using voltage       = int_unit<1, -3, 2, 0, -1, 0, 0>;
}

template<typename M, typename T, typename L, typename K, typename I, typename Mol, typename Cd>
std::ostream& operator<<(std::ostream& stm, const sci::unit<M, T, L, K, I, Mol, Cd>& unit) {
    using U = sci::unit<M, T, L, K, I, Mol, Cd>;
    stm << "sci-type-lib/unit{" << typename U::mass::num << "/" << U::mass::den << ", "
                << typename U::time::num << "/" << typename U::time::den << ", "
                << typename U::length::num << "/" << typename U::length::den << ", "
                << typename U::temperature::num << "/" << typename U::temperature::den << ", "
                << typename U::intensity::num << "/" << typename U::intensity::den << ", "
                << typename U::mol::num << "/" << typename U::mol::den << ", "
                << typename U::luminosity::num << "/" << typename U::luminosity::den << "}";
    return stm;
}

#endif // SCI_TYPE_LIB_UNIT_H
