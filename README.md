## Header-only framework which allows using different units and quantities as types

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
