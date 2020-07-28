A scientific library to introduce typings in matematical/physics computing in C++
===

## Prerequisites

This library works with three types of objects: units, ratio and quantities.

**Units:**

A unit correspond to a *type* of a variable, expressed as SI units; in common terms, this is the *unit* of a variable. The idea is that one can only compare value which have the same unit.

Units are defined as `sci::unit`. One can define its own units as a combination of the standard units but several common ones are already defined: `sci::power`, `sci::temperature`, `sci::voltage`, `sci::intensity`, ...

Values with the same units can be added, subtracted, multiplied and divided. Values with different units can only be multiplied and divided. Of course, in a multiplication and division, the unit of the resulting value is a function of the two previous units.

**Ratio:**

Ratios differentiate between *grams* and *kilograms*, *volt* and *megavolt*, ... The units are the same but the *ratio* differ. Therefore, if `a = 3000 g` one can also express it as `a = 3 kg`. 

sci-type-lib's ratios are based on `std::ratio` and its predefined types: `std::giga`, `std::mega`, `std::kilo`, ...

**Quantities:**

Quantities are the real values that are manipulated with sci-type-lib. A quantity is given a unit, a ratio and a value. his value can be updated, compared and be part of arithmetic expressions. Predefined quantities' type exist such as `sci::watt`, `sci::ampere`, `sci::kelvin`, ... The full list can be found in the predefined types below or in `sci-type-lib/sci-quantity.h`

## Getting started

Include the general `sci-type-lib/sci-lib.h` header to include all the features of the library at once. Then, use th quantites for your equations !

```c++
#include <sci-type-lib/sci-lib.h>

int main() {
    sci::volt u { 5 };
    sci::ampere i { 10 };

    sci::power p = u*i;
    std::cout << "Power through a resistance with U = 5V and I = 10A: " << p.value();
    return 0;
}
```

## Predefined types

### Quantities

**Powers:** from `sci::milliwatt` to `sci::gigawatt`
**Length:** from `sci::millimeter` to `sci::kilometer`
**Mass:** from `sci::milligram` to `sci::ton`
**Voltage:** from `sci::milivolt` to `sci::gigavolt`
**Temperature:** from `sci::kelvin`, `sci::celsius`, `sci::fahrenheit`
**Others:** `sci::ampere`, `sci::no_unit`, `sci::mol`, `sci::candela`

