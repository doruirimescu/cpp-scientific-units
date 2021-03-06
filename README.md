## Header-only framework which allows using different units and quantities as types
![C++](https://img.shields.io/badge/-C++-05122A?style=flat&logo=cplusplus&logoColor=00599C)
[![GitHub license](https://img.shields.io/github/license/mpusz/units?cacheSeconds=3600&color=informational&label=License)](./LICENSE.md)

## How to use

Example usage:

```cpp
static_assert(static_cast<q_J>(1.0_q_J).value == 1.0);
constexpr auto grav_acc = 10.0_q_mps / 1.0_q_s;
constexpr auto height = 10.0_q_m;
constexpr auto mass = 10.0_q_g;
static_assert(static_cast<q_J>(1.0_q_J + 2.0_q_N * 2.5_q_m - grav_acc * height * mass).value == 5.0);
```

When dealing with prefixes, the first prefix appearing in the expression will be assigned to the resulting type:
```cpp
auto mass =  10.0_q_g + 1.0_q_kg;
static_assert(std::is_same<decltype(mass), q_g>::value);
//******************************************************
auto mass =  1.0_q_kg + 10.0_q_g;
static_assert(std::is_same<decltype(mass), q_kg>::value);
```

It is possible to cast between different prefixes, as long as the unit is the same:
```cpp
static_assert(static_cast<q_g>(q_kg{1.0}).value == 1000.0);
```

As you note, all types are starting with ```q_``` and all user-defined type literals start with ```_q_```. Conversion between equivalent types happen implicitly. 

This code will generate a compile-time error.
```cpp
q_g grams{10.0};
q_J energy = 2.0 * grams;
```
![Selection_086](https://user-images.githubusercontent.com/7363000/153576272-87e3a913-4228-4fc1-853f-15cd6baf5059.png)

## How it works

The framework consists of 3 building blocks:
- metaprogramming
- type_list
- quantity

### Metaprogramming
[Metaprogramming](https://github.com/doruirimescu/cpp-scientific-units/tree/master/include/metaprogramming) is a set of helper templates which allow 
performing type manipulations on variadic structs. 

Terminology: In this framework, a variadic/Variadic is any type declared as follows:

```cpp
template<typename...T>
struct ExampleVariadic;
```

This, using the helper ```IsVariadic<ExampleVariadic<int, double>>::value``` will return ```true```. 
```IsVariadic<int>::value``` will return ```false```.

The usage of the metaprogramming library can be easily understood from the [unit tests](https://github.com/doruirimescu/cpp-scientific-units/blob/master/test/metaprogramming/metaprogramming_test.cpp).

### Type lists
[Type lists](https://github.com/doruirimescu/cpp-scientific-units/tree/master/include/type_list) are built from putting all together the metaprogramming helpers into one class. Type lists are the building blocks of quantities. 

For example, ```TypeList<kg, m>``` could represent a type of "kilogram times meter". 

```TypeList<s, s>``` could represent a type of "second square". Thus, a quantity will be represented by two type lists, one for the numerator and one for the denominator.

```TypeList<>``` could represent a numerator or denominator of 1. For example, a quantity of meter could be represented by two type lists, ```TypeList<m>``` and ```TypeList<>```, for the numerator and denominator respectively.

The metaprogramming helpers are used to define basic algebraic operations with TypeLists.
