#ifndef SCI_TYPE_LIB_LITERALS_H
#define SCI_TYPE_LIB_LITERALS_H

#include <sci-type-lib/sci-quantity.h>

namespace sci {
namespace literals {

// Power literals
// From milliwatt to Gigawatt
// ---
sci::gigawatt operator""_Gw(long double val) {
    return sci::gigawatt(val);
}
sci::megawatt operator""_Mw(long double val) {
    return sci::megawatt(val);
}
sci::kilowatt operator""_kw(long double val) {
    return sci::kilowatt(val);
}
sci::hectowatt operator""_hw(long double val) {
    return sci::hectowatt(val);
}
sci::decawatt operator""_daw(long double val) {
    return sci::decawatt(val);
}
sci::watt operator""_w(long double val) {
    return sci::watt(val);
}
sci::deciwatt operator""_dw(long double val) {
    return sci::deciwatt(val);
}
sci::centiwatt operator""_cw(long double val) {
    return sci::centiwatt(val);
}
sci::milliwatt operator""_mw(long double val) {
    return sci::milliwatt(val);
}

// Mass literals
// From milligram to ton
// ---
sci::ton operator""_t(long double val) {
    return sci::ton(val);
}
sci::kilogram operator""_kg(long double val) {
    return sci::kilogram(val);
}
sci::hectogram operator""_hg(long double val) {
    return sci::hectogram(val);
}
sci::decagram operator""_dag(long double val) {
    return sci::decagram(val);
}
sci::gram operator""_g(long double val) {
    return sci::gram(val);
}
sci::decigram operator""_dg(long double val) {
    return sci::decigram(val);
}
sci::centigram operator""_cg(long double val) {
    return sci::centigram(val);
}

sci::milligram operator""_mg(long double val) {
    return sci::milligram(val);
}

// Length literals
// From millimeter to killometer
// ---
sci::kilometer operator""_km(long double val) {
    return sci::kilometer(val);
}
sci::hectometer operator""_hm(long double val) {
    return sci::hectometer(val);
}
sci::decameter operator""_dam(long double val) {
    return sci::decameter(val);
}
sci::meter operator""_m(long double val) {
    return sci::meter(val);
}
sci::decimeter operator""_dm(long double val) {
    return sci::decimeter(val);
}
sci::centimeter operator""_cm(long double val) {
    return sci::centimeter(val);
}
sci::millimeter operator""_mm(long double val) {
    return sci::millimeter(val);
}

// Voltage literals
// From millivolt to Gigavolt
sci::gigavolt operator""_GV(long double val) {
    return sci::gigavolt(val);
}
sci::megavolt operator""_MV(long double val) {
    return sci::megavolt(val);
}
sci::kilovolt operator""_kV(long double val) {
    return sci::kilovolt(val);
}
sci::hectovolt operator""_hV(long double val) {
    return sci::hectovolt(val);
}
sci::decavolt operator""_daV(long double val) {
    return sci::decavolt(val);
}
sci::volt operator""_V(long double val) {
    return sci::volt(val);
}
sci::decivolt operator""_dV(long double val) {
    return sci::decivolt(val);
}
sci::centivolt operator""_cV(long double val) {
    return sci::centivolt(val);
}
sci::millivolt operator""_mV(long double val) {
    return sci::millivolt(val);
}

// Temperature literals
// Kelvin, Celcius, Fahrenheit
// ---
sci::kelvin operator""_K(long double val) {
    return sci::kelvin(val);
}
sci::celsius operator""_C(long double val) {
    return sci::celsius(val);
}
sci::fahrenheit operator""_F(long double val) {
    return sci::fahrenheit(val);
}

// Miscelanneous (for now)
// ---
sci::ampere operator""_A(long double val) {
    return sci::ampere(val);
}
sci::mol operator""_mol(long double val) {
    return sci::mol(val);
}
sci::candela operator""_cd(long double val) {
    return sci::candela(val);
}

} // namespace literals  
}

#endif // SCI_TYPE_LIB_LITERALS_H
