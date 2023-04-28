# C++ native types

## Integer numbers

### Types with size depended on platform and compiler

* char - One character. Almost always 8 bits.
* short - At least 16 bits
* int - At least 16 bits. This type usually used when you need an integer number of "normal" size.
* long - At least 32 bit
* long long - At least 64 bit

#### Integer type modifiers

You can specify a modifier to make type support negative numbers or not. For instance "unsigned char" type usually has range 0.255
but "signed char" -128..127. Without a modifier the type is signed except for "char". "char" without modifier can be signed or
not depending on platform and used compiler options.   

* signed - can be negative. Twice less range
* unsigned - only positive. Twice more range.


### Size with fixed sizes

There are aliases defined in C++ standard library allowing you to request integer type of precise size.

* std::int8_t, std::uint8_t
* std::int16_t, std::uint16_t
* std::int32_t, std::uint32_t
* std::int64_t, std::uint64_t
