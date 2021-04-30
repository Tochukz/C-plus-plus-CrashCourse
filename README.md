# C++ CRASH COURSE (2019)
__By Josh Lospinoso__  
[Book Website](https://ccc.codes/)  
[Github Example Code](https://github.com/JLospinoso/ccc)

## PART I: The c++ Core Language

### Chapter 1: Up and Running
__The Compiler Tool Chain__  
The _compiler tool chain_ is a collection of the three elements that un one after the other to convert source code into a program:  
1. The __Preprocessor__ processes source file and produces a single translation unit
2. The __Compiler__ reads the translation unit and generated an _object file__  
3. The __Linker__ generates programs from object files.  

You can compile an run  C++ code online using [wandbox.org](https://wandbox.org/). Another online editor, [godbolt.org](https://www.godbolt.org/) also allows you to inspect the assembly code that your code generates. Both work on a variety of compilers and systems.  

__Useful Links__   
[cppcast.com](https://cppcast.com/)  
[cppreference.com](https://en.cppreference.com/w/)  
[cplusplus.com](http://www.cplusplus.com/)  

### Chapter 2: Types
##### Fundamental Types
__Integer Types__    
Tee four sizes of integer types are `short int`, `int`, `long int` and `long long int`. Each can be either signed or _unsigned_. Integer types are signed and _int_ by default, which means you can use the following shorthand notation in your programs: `short`, `long`, and `long long`.  
__NOTE__: If you want to enforce guaranteed integer size, you can use integer types n the `<cstdint>` library. For example, if you need a signed integer with exactly 8, 16, 32, or 64 bits, you could use `int8_t`, `int16_t`, `int32_t`, or `int64_t`.  

__Floating-Point Types__  
ON major desktop operating systems, the _float_ level usually has 4 bytes of precision. The _double_ and _long double_ level usually have 8 bytes of precision (_double precision_).
__NOTE:__ If you are involved in scientific computation applications, look at the floating-point specification relevant to your hardware platform. The predominant implementation of floating point storage and arithmetic is outlined in The IEEE Standard for Floating Point Arithmetic, IEEE 754.  

__Character Types__  
The character types `char`, `signed char`, and `unsigned char` are called _narrow characters_, whereas `char16_t`, `char32_t` and `wchar_t` are called _wide characters_ due to their relative storage requirements.     
`wchar_t` is large enough to contain the largest character of the implementation's locale.    

__Character Literals__  
All characters except `char` must be prepended by a prefix: `L` for `wchar_t`, `u` for `char16_t`, and `U` for `char32_t`.

__The std::byte Type__  
System programmers sometimes work directly with _raw memory_, which is a collection of bits without a type. Employ the `std::byte` type, available in the `<cstddef>` header, in such situations. The `std:::byte` type permits bitwise logical operations. Using this type for raw data rather than an integral type can help to avoid common sources of difficult-to-debug programming errors.  

__Format Specifier__   
If you need to enbed Unicode characters into a string literal, look at `wprintf` in the `<cwchar>` header. 
