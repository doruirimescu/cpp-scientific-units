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
