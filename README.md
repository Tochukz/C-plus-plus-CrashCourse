# C++ CRASH COURSE (2019)
__By Josh Lospinoso__  
[Book Website](https://ccc.codes/)  
[Github Example Code](https://github.com/JLospinoso/ccc)

## PART I: The C++ Core Language

### Installation
See [azrael.digipen.edu/~mmead/www/public/mingw/](https://azrael.digipen.edu/~mmead/www/public/mingw/) for installation instructions.

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
System programmers sometimes work directly with _raw memory_, which is a collection of bits without a type. Employ the `std::byte` type, available in the `<cstddef>` header, in such situations. The `std::byte` type permits bitwise logical operations. Using this type for raw data rather than an integral type can help to avoid common sources of difficult-to-debug programming errors.  

__Format Specifier__   
If you need to embed Unicode characters into a string literal, look at `wprintf` in the `<cwchar>` header.

__Brace Yourself__
As a general rule to make initialization simple: use `braced initializers` everywhere. Braces initializers work as intended almost everywhere, and they cause the fewest surprises. For this reason, braced initialization is also called `uniform initialization`.   

### Chapter 3: Reference Types  
_Reference types_ store the memory address of objects. There are tow kinds of reference types: _pointers_ and _references_.

__Pointers__
_Pointers_ are the fundamental mechanism used to refer to memory addresses. Pointers encode the object's address and the object's type.  

__Pointer and Arrays__  
Pointers share several characteristics with arrays. Pointers encode object location. Array encode the location and length of contiguous objects.    
At the slightest provocation, an array will decay into a pointer. A decayed array loses length information and converts to a pointer of the array's first element.  

__void Pointers and std::byte Pointers__   
You use the _void pointer_ `void*` when pointer-to type is irrelevant. The void pointer cannot be dereferenced because the pointed-to type has been erased. Also, C++ forbids void pointer arithmetic for the same reason so bitwise and arithmetic operations are disabled.

When you want to interact with raw memory at the byte level, you use the `std::byte` pointer. Examples include low-level operations like copying raw data between files and memory, encryption, and compression.

__nullptr and Boolean Expressions__  
A pointer that equals `nullptr` doesn't point to anything. You could use `nullptr` to indicate, for example, that there's no more memory left to allocate or that some error occurred.   
Pointers have an implicit conversion to bool. Any value that is not `nullptr` convers implicitly to _true_, whereas `nullptr` converts implicitly to _false_.

### Chapter 4: The Object Life Cycle  
__Automatic Storage Duration__  
An _automatic object_ is allocated at the beginning of an enclosing code block and is deallocated at the end. Automatic objects have _automatic storage duration_. Function parameters and local variable are automatic variables/objects.

__Static Storage Duration__   
A _static object_ is declared using the `static` or `extern` keyword. You declare static variable at the same level you declare functions - at global scope ( or _namespace scope_). Static objects with global scope have _static storage duration_ and are allocated when the program starts and deallocated when the program stops.    
Another feature of being declared at the global scope is that the variable can be accessed from any function in the _translation unit_. A translation unit is what a processor produces after acting on a single source file.    
When you use the `static` keyword, you specify _internal linkage_. Internal linkage means that a variable is inaccessible to other translation units. You can alternatively specify _external linkage_, which makes a variable accessible to other translation units. For external linkage, you use the `extern` keyword instead of the `static`.  

__Local Static Variables__   
A _local static variable_ is a special kind of static variable in a local - rather than global - variable. Their lifetimes begin upon the first invocation of the enclosing function and end when the program exits.  

__Static Members__   
Normal class members have lifetimes nested within the class's lifetime, but static members have static storage durations. These members are essentially similar to static variables and functions declared at global scope; however you must refer to them using scope resolution operator `::` outside the class.
You cannot initialize a static member within a containing class definition unless they are constant integral types within the class.

__Thread Local Storage Duration__  
The sequence of instructions that a thread executes is called its _thread of execution_.  One technique for ensuring thread safety is to specify that an object has _thread storage duration_. This is useful for global variable(s) is used in the thread.  
Use the `thread_local` keyword to modify any static variable to have _thread local storage duration_ by add the keyword to `static` or `extern` keyword. If only `thread_local` is specified, `static` is assumed.   

__Dynamic Storage Duration__  
 You have manual control over when a _dynamic object's_ life begins and when it ends. Dynamic object are also called _allocated objects_ for this reason.  
 __Note__: Because the compiler doesn't typically clean up memory after an object is deleted, a subtle and potentially serious type of bud=g called a _use after free_ can occur.   
 If you delete and object and accidentally reuse it, you program might appear to function correctly because the deallocated memory might still contain reasonable values. In some situations, the problem don't manifest until the program has been in production for a long time - or until a security researcher finds a way to exploit the bug and discloses it!  

 __Memory Leaks__  
 You must make sure that dynamic objects you allocate are also deallocated. Failure to do so causes memory leaks  in which memory that is no longer needed by your program isn't released.  
 __Note__: In practice, you program's operating environment might clean up leaked resources for you. For example, if you've written user-mode code, modern operating system will clean up the resources when the program exits. However, if you've written kernel code, those operating systems won't clean up the resources. You'll only reclaim them when the computer reboots.

 __Standard Exception Classes__   
 The _stdlib_ provided your with the _standard exception classes_ in the `<stdexcept>` header.  
 How _stdlib_ exceptions are nested under `std::exception`:
 ```
                    exception
        runtime_error         logic_error
      system_error              domain_error
      under_flow_error          invalid_argument
      overflow_error            length_error
      ...                       out_of_range
                            ...

                    bad_cast
                    bad_alloc
 ```
 The `system_error` reports that the operating system encountered some error. Inside of the `<system_error>` header, there is a large number of _error codes_ and _error conditions_. The `code()` method returns an _enum class_ of type `std::errc` that has a large number of values, such as _bad_file_descriptor_, _timed_out_ and _permission_denied_.

__Throwing in Destructors__    
If you throw an exception in a destructor, the C++ compiler will call `terminate`. As a general rule, treat destructors as if they were `noexcept`.

__Constructor and Destructor__    
When you pair the allocation and deallocation of buffer with the constructor and destructor of a class, you will never leak the storage.  
This pattern is called _resource acquisition is initialized (RAII)_ or _constructor acquires, destructor releases (CADRe)_.

__Exceptions and Performance__  
Sometimes, unfortunately, you won't be able to use exceptions. One example is embedded development where real-time guarantees are required. Tools simple don't (yet) exists in this settings. With luck, this will change soon, but for now, you're stuck without exceptions in most embedded contexts. Another examples is with some legacy code. Exceptions are elegant because of how they fit in with _RAII_ objects. When destructors are responsible for cleaning up resources, stack unwinding is a direct and effective way to guarantee against resource leakages. In legacy code, you might find manual resource management and error handing instead of _RAII_ objects. This makes using exceptions very dangerous, because stack unwinding is safe only with _RAII_ objects. Without then, you could easily leak resources.  

__Structured Binding Declaration__   
_structured binding declaration is a C++ language feature that allows you to return multiple values from a function call.  Structured bindings is only available with C++17.   

__Copy Semantics__   
__Note__: Like its nefarious cousin the use after free, the double free can result in subtle and hard-to diagnose bug that manifest only very infrequently. A double free occurs when you deallocate an object twice. If you destruct and object that's already been destructed, you've got undefined behavior. In certain situations, this can cause serious security vulnerabilities.   

__Default Copy__  
Any time a class manages a resource, you must be extremely careful with default copy semantics; they are likely to be wrong. Best practice dictates that you explicitly declare that default copy assignment and copy construction are acceptable for such classes using the default keyword.     
Some classes simply cannot or should not be copied - for example, if your class manages a file or if it represents a mutual exclusive lock for concurrent programming. You can suppress the compiler from generating a cop constructor and a copy assignment operator using the _delete_ keyword.   
It is highly recommended that you explicitly defined the _copy assignment operator_ and _copy constructor_ for any class that owns a resource (like a printer, a network connection, or a file). If custom behavior is not needed, use either `default` or `delete`. This will save you from a lot of nasty and difficult-to-debug errors.   

__Move Semantics__  
_Move semantics_ is move's corollary to copy semantics. Similar to how you specify copying behavior, you specify how objects move with _move constructors_ and _move assignment operators_.

__Value Categories__   
An _lvalue_ is any value that has a name, and an _rvalue_ is anuthing that isn't an _lvalue_.

Todo: Exercises 4-1 to 4-7

### Chapter 5: Runtime Polymorphism  
__Polymorphism__  
C++ offers two polymorphic approaches. _Compile-time polymorphic code_ incorporated polymorphic types you can determine at compile time. The other approach is _runtime polymorphism_, which instead incorporates types determined at runtime. Which approach you choose depends on whether you know the types you want to use with your polymorphic code at compile time or runtime.

__Object Composition and Implementation Inheritance__  
_Object composition_ is a design pattern where a class contains members of other class types. An alternate, antiquated design pattern called _implementation inheritance_ achieves runtime polymorphism.    
Over the years, accumulated experience with implementation inheritance has convinced many that it is an anti-pattern.  For example, Go and Rust -- two new and increasingly popular system-programming languages -- have zero support for implementation inheritance.   

__Member Inheritance__   
The supposes benefit of member inheritance is that you can define functionality once in a base class and not have to repeat it in the derived classes. Unfortunately, experience has convinced many in the programming community to avoid member inheritance because it can easily yield brittle, hard-to-reason-about code compared to composition-based polymorphism. This is why so many modern programming languages exclude it.  

__Virtual Methods__  
__Note__: Virtual functions can incur runtime overhead, although the cost is typically low (within 25 percent of a regular function call). The compiler generates virtual function tables (vtables) that contains function pointer. At runtime, a consumer of an interface does not generally know its underlying type, but it knows how t invoke the interface's methods (thanks to the vtable). In some circumstances, the linker can detect all uses of an interface and devirtualize a function call. This removes the function call from the vtable and thus eliminates associated runtime cost.  

__Pure-Virtual Classes and Virtual Destructors__  
Usually, you add virtual destructors to interfaces. In some rare circumstances it's possible to leak resources if you fail to mark destructors as virtual.   
Declaring a virtual destructor is optional when declaring an interface, but beware.

TOdo: Return to chp6 exercises

### Chapter 6: Compile-Time Polymorphism
__Templates__  
_Template instantiation_ is the process of creating a class or a function from a template. Template instantiation are sometimes called concrete classes and concrete types.

__Concepts__  
_Concepts_ constrain template parameters, allowing for parameter checking at the point of instantiation rather than the point of first use. By catching usage issues at the point of instantiation, the compiler can give you a friendly, informative error code.  
Concepts allow you to express requirements on template parameters directly in language.  
Concept aren't yet officially part of the C++ standard, although they have been voted into C++20. If you can use GCC 6.0 or later, concepts are available by turning on the `-fconcepts` compiler flag.  

To implement a concept, you write a predicate (a function that returns a boolean).
```
template<typename T1, typename T2, ...>
concept bool my_concept_name() {
  ...
  return boolean_expression
}
```
The predicate will return true if the template parameters are supported or false otherwise.

__Type Traits__  
Type traits are often the building blocks for a concept. Type traits tell you _what_ types are.  

__Requirements__  
Type traits tell you _what_ types are, but sometimes you must also specify _how_ the template will use them. For this, you use requirements.   
Because requires expressions are evaluated at compile time, concepts can contain any number of them.   

__Using Concepts__  
[The Origins Library](https://github.com/asutton/origin)

__static_assert: The Preconcepts Stopgap__  
You can use type traits in combination with _static_assert_ to achieve a similar result as using a _concept_. Using _static_assert_ as a proxy for concept is a hack, but it's widely uses.  

Todo: Return to chp6 exercises

### Chapter 7: Expressions
__Unary Arithmetic Operators__   
The _unary plus_ + and _unary minus_ - operators _promote_ their operand to _int_. So, if the operand is of type _bool_, _char_, _short int_, the result of the expression is an _int_.  

__Binary Arithmetic Operators__  
Like the unary operators, the binary operator: _addition_ +, _substraction_ -, _multiplication_ *, _division_ /, also cause integer promotion on their operands. There are also floating-point promotion rules and signed promotion rules.

__Free Store Availability__  
To take control of free store allocation you can overload the free store operations. You do this by overloading the `new` operator.  

#### Overloading Operator new
Todo:  Return to this

__The <new> Header__    
In the environment that support free store operations, the `<new>` header contains the following four operators:
* `void* operator new(size_t)`;
* `void operator delete(void*);`
* `void* operator new[](size_t);`
* `void operator delete[](void*);`


#### Execution Order
_Precedence_ is a compile time concept that drive how operators bind or operands. _Evaluation order_ is a runtime concept that drives the scheduling of operator execution. In general C++ has no clearly specified execution order for operands. The language allows the compiler writers to find clever optimization opportunities.   

#### Type Conversion
__C-Style Casts__  
For each C-style cast, there exits some incantation of `static_cast`, `const_cast` and `reinterpret_cast` that would achieve the desired type conversion. C-style casts are far more dangerous than the named casts.

__Exercises__  
Todo: Return to 7-2.

### Chapter 8: Statements
#### Namespaces
__Using Directives__  
__Note:__ You should never put a _using namespace_ directive within a header file. Every source file that includes your header will dump all the symbol from that using directive into the global namespace. This can cause issues that are very difficult to debug.   

Todo: Chapter 8 Exercises

### Chapter 9: Functions

__Prefix Modifiers__  
_Inlining a function_ means copying and pasting the contents of the function directly into the execution path, eliminating the need for the five steps process required for a function call. This means that as the processor executes your code, it will immediately execute your function's code rather than executing the modest ceremony required for function invocation. The provides a marginal increase in speed at the cost of an increase in binary size.  
The `inline` keyword hints to the compiler's optimizer to put a function directly inline rather than perform a function call.  


__final and override__   
Whenever you are using interface inheritance, you should mark implementing classes _final_ because the modifier can encourage the compiler to perform an optimization called _devirtualization_. When virtual calls are devirtualized, the compiler eliminates the runtime overhead associated with a virtual call.

__volatile__  
Only methods marked `volatile` can be invoked on a volatile instance a the class. Similarly, only methods marked `const` to be invoked on a constant instance of a class.

__The Function-Call Operator__  
You can make user-defined types callable or invocable by overloading the function-call operator `operator()()`. Such a type is called a _function type_, and instance of a function type are called _function objects_.  The function-call operator permits any combination of argument types, return types, and modifiers (except static).

## PART II: C++ Libraries and Frameworks  

### Chapter 10: Testing
__Reg-Green-Refactor__   
TDD practitioners have a mantra: _red_, _green_, _refactor_.  

#### Unit-Testing and Mocking Frameworks
__The Catch Unit-Testing Framework__  
Because it's a header-only library, you can set up Catch by downloading the single-header version and including it in each translation unit that contains unit-testing code.  
[Catch2 Github](https://github.com/catchorg/Catch2/)   
[Catch2 Tutotrial](https://github.com/catchorg/Catch2/blob/devel/docs/tutorial.md#top)   

__Google Test__  
Google Test follows the `xUnit` unit-testing framework tradition. It also includes Google Mocks, the mocking framework.Unlike Catch, Google Test is not a header-only library.  
[GoogleTest Github](https://github.com/google/googletest)  
[GoogleTest Docs](https://google.github.io/googletest/)  

Continue from Google Test pg [310]

__Boost Test__  
Boost Test is a unit-testing framework that ships as part of the Boost C++ libraries. Boost is an excellent collection of open source C++ libraries of which Boost Test is one.  
[boost.org](https://www.boost.org)   
You can use Boost Test in three modes: as a header-only library (like Catch), as a static library (like Google Test), or as a shared library, which will link the Boost Test module at runtime.  

### Chapter 11: Smart Pointers
You can use RAII to handle dynamic memory management by acquiring dynamic storage in the constructor of the RAII object and releasing dynamic storage in the destructor.  
_Smart pointers_ are prewritten implementation of RAII objects. Smart pointers are class templates that behave like pointers and implement RAII for dynamic objects.  

There are five available options included in _stdlib_ and Boost:
1. _scoped pointer_
2. _unique pointer_
3. _shared pointer_
4. _weak pointer_
5. _intrusive pointer_    
Their ownership models differentiate these five smart pointer categories.

__Smart Pointer Ownership__   
When you use a smart pointer, you can rest assured that the pointed-to object is alive and that the pointed-to object won't leak. The smart pointer manages the object it owns, so you can't forget to destroy it thanks to RAII.

__Scoped Pointers__   
A _scoped pointer_ expresses _non-transferable_, _exclusive ownership_ over a single dynamic object.  No other smart pointer can have ownership of a scoped pointer's dynamic object.   
The `boost::scoped_ptr` is defined in the `<boost/smart_ptr/scoped_ptr.hpp>` header. There is no _stdlib_ scoped pointer.  

### C++ and Oracle RDBMS
To connect to Oracle Database from C++ application  
__Requirements__  
* __API__: SQLAPI++ Library
* __OCCI__: Oracle C++ Call Interface  

Download Links   
[sqlapi.com/Download/](https://www.sqlapi.com/Download/)  []


### Appendix
__C++ Libraries/Frameworks__  
* Boost: [Docs](https://www.boost.org/doc/libs/1_76_0/more/getting_started/windows.html)
* Drogon: [Docs](https://drogon.docsforge.com/master/overview/),  [Githib](https://github.com/an-tao/drogon)
