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
sci::gigawatt operator""_Gw(unsigned long long val) {
    return sci::gigawatt(static_cast<long double>(val));
}
sci::megawatt operator""_Mw(long double val) {
    return sci::megawatt(val);
}
sci::megawatt operator""_Mw(unsigned long long val) {
    return sci::megawatt(static_cast<long double>(val));
}
sci::kilowatt operator""_kw(long double val) {
    return sci::kilowatt(val);
}
sci::kilowatt operator""_kw(unsigned long long val) {
    return sci::kilowatt(static_cast<long double>(val));
}
sci::hectowatt operator""_hw(long double val) {
    return sci::hectowatt(val);
}
sci::hectowatt operator""_hw(unsigned long long val) {
    return sci::hectowatt(static_cast<long double>(val));
}
sci::decawatt operator""_daw(long double val) {
    return sci::decawatt(val);
}
sci::decawatt operator""_daw(unsigned long long val) {
    return sci::decawatt(static_cast<long double>(val));
}
sci::watt operator""_w(long double val) {
    return sci::watt(val);
}
sci::watt operator""_w(unsigned long long val) {
    return sci::watt(static_cast<long double>(val));
}
sci::deciwatt operator""_dw(long double val) {
    return sci::deciwatt(val);
}
sci::deciwatt operator""_dw(unsigned long long val) {
    return sci::deciwatt(static_cast<long double>(val));
}
sci::centiwatt operator""_cw(long double val) {
    return sci::centiwatt(val);
}
sci::centiwatt operator""_cw(unsigned long long val) {
    return sci::centiwatt(static_cast<long double>(val));
}
sci::milliwatt operator""_mw(long double val) {
    return sci::milliwatt(val);
}
sci::milliwatt operator""_mw(unsigned long long val) {
    return sci::milliwatt(static_cast<long double>(val));
}

// Mass literals
// From milligram to ton
// ---
sci::ton operator""_t(long double val) {
    return sci::ton(val);
}
sci::ton operator""_t(unsigned long long val) {
    return sci::ton(static_cast<long double>(val));
}
sci::kilogram operator""_kg(long double val) {
    return sci::kilogram(val);
}
sci::kilogram operator""_kg(unsigned long long val) {
    return sci::kilogram(static_cast<long double>(val));
}
sci::hectogram operator""_hg(long double val) {
    return sci::hectogram(val);
}
sci::hectogram operator""_hg(unsigned long long val) {
    return sci::hectogram(static_cast<long double>(val));
}
sci::decagram operator""_dag(long double val) {
    return sci::decagram(val);
}
sci::decagram operator""_dag(unsigned long long val) {
    return sci::decagram(static_cast<long double>(val));
}
sci::gram operator""_g(long double val) {
    return sci::gram(val);
}
sci::gram operator""_g(unsigned long long val) {
    return sci::gram(static_cast<long double>(val));
}
sci::decigram operator""_dg(long double val) {
    return sci::decigram(val);
}
sci::decigram operator""_dg(unsigned long long val) {
    return sci::decigram(static_cast<long double>(val));
}
sci::centigram operator""_cg(long double val) {
    return sci::centigram(val);
}
sci::centigram operator""_cg(unsigned long long val) {
    return sci::centigram(static_cast<long double>(val));
}
sci::milligram operator""_mg(long double val) {
    return sci::milligram(val);
}
sci::milligram operator""_mg(unsigned long long val) {
    return sci::milligram(static_cast<long double>(val));
}

// Length literals
// From millimeter to killometer
// ---
sci::kilometer operator""_km(long double val) {
    return sci::kilometer(val);
}
sci::kilometer operator""_km(unsigned long long val) {
    return sci::kilometer(static_cast<long double>(val));
}
sci::hectometer operator""_hm(long double val) {
    return sci::hectometer(val);
}
sci::hectometer operator""_hm(unsigned long long val) {
    return sci::hectometer(static_cast<long double>(val));
}
sci::decameter operator""_dam(unsigned long long val) {
    return sci::decameter(static_cast<long double>(val));
}
sci::meter operator""_m(long double val) {
    return sci::meter(val);
}
sci::meter operator""_m(unsigned long long val) {
    return sci::meter(static_cast<long double>(val));
}
sci::decimeter operator""_dm(long double val) {
    return sci::decimeter(val);
}
sci::decimeter operator""_dm(unsigned long long val) {
    return sci::decimeter(static_cast<long double>(val));
}
sci::centimeter operator""_cm(long double val) {
    return sci::centimeter(val);
}
sci::centimeter operator""_cm(unsigned long long val) {
    return sci::centimeter(static_cast<long double>(val));
}
sci::millimeter operator""_mm(long double val) {
    return sci::millimeter(val);
}
sci::millimeter operator""_mm(unsigned long long val) {
    return sci::millimeter(static_cast<long double>(val));
}

// Voltage literals
// From millivolt to Gigavolt
sci::gigavolt operator""_GV(long double val) {
    return sci::gigavolt(val);
}
sci::gigavolt operator""_GV(unsigned long long val) {
    return sci::gigavolt(static_cast<long double>(val));
}
sci::megavolt operator""_MV(long double val) {
    return sci::megavolt(val);
}
sci::megavolt operator""_MV(unsigned long long val) {
    return sci::megavolt(static_cast<long double>(val));
}
sci::kilovolt operator""_kV(long double val) {
    return sci::kilovolt(val);
}
sci::kilovolt operator""_kV(unsigned long long val) {
    return sci::kilovolt(static_cast<long double>(val));
}
sci::hectovolt operator""_hV(long double val) {
    return sci::hectovolt(val);
}
sci::hectovolt operator""_hV(unsigned long long val) {
    return sci::hectovolt(static_cast<long double>(val));
}
sci::decavolt operator""_daV(long double val) {
    return sci::decavolt(val);
}
sci::decavolt operator""_daV(unsigned long long val) {
    return sci::decavolt(static_cast<long double>(val));
}
sci::volt operator""_V(long double val) {
    return sci::volt(val);
}
sci::volt operator""_V(unsigned long long val) {
    return sci::volt(static_cast<long double>(val));
}
sci::decivolt operator""_dV(long double val) {
    return sci::decivolt(val);
}
sci::decivolt operator""_dV(unsigned long long val) {
    return sci::decivolt(static_cast<long double>(val));
}
sci::centivolt operator""_cV(long double val) {
    return sci::centivolt(val);
}
sci::centivolt operator""_cV(unsigned long long val) {
    return sci::centivolt(static_cast<long double>(val));
}
sci::millivolt operator""_mV(long double val) {
    return sci::millivolt(val);
}
sci::millivolt operator""_mV(unsigned long long val) {
    return sci::millivolt(static_cast<long double>(val));
}

// Temperature literals
// Kelvin, Celcius, Fahrenheit
// ---
sci::kelvin operator""_K(long double val) {
    return sci::kelvin(val);
}
sci::kelvin operator""_K(unsigned long long val) {
    return sci::kelvin(static_cast<long double>(val));
}
sci::celsius operator""_C(long double val) {
    return sci::celsius(val);
}
sci::celsius operator""_C(unsigned long long val) {
    return sci::celsius(static_cast<long double>(val));
}
sci::fahrenheit operator""_F(long double val) {
    return sci::fahrenheit(val);
}
sci::fahrenheit operator""_F(unsigned long long val) {
    return sci::fahrenheit(static_cast<long double>(val));
}

// Miscelanneous (for now)
// ---
sci::ampere operator""_A(long double val) {
    return sci::ampere(val);
}
sci::ampere operator""_A(unsigned long long val) {
    return sci::ampere(static_cast<long double>(val));
}
sci::mol operator""_mol(long double val) {
    return sci::mol(val);
}
sci::mol operator""_mol(unsigned long long val) {
    return sci::mol(static_cast<long double>(val));
}
sci::candela operator""_cd(long double val) {
    return sci::candela(val);
}
sci::candela operator""_cd(unsigned long long val) {
    return sci::candela(static_cast<long double>(val));
}

} // namespace literals  
}

#endif // SCI_TYPE_LIB_LITERALS_H
