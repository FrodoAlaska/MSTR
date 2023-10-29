# What is MSTR?
Mutable, Manipulatable, and Malubale string or MSTR (prounanced Mister) for short is a string library made purly in C. The library itself is only one header file and one source file, and it does not use any C string functions(except 'memcpy' which is in the string.h library). All of the manipulation done with strings and characters are entirely done from scratch. Unfourtunately, MSTR only supports ASCII currently, with no plans to support UTF8 anytime soon. 

However, the library does include all types of string manipulation functions that you might need. To see the full functions list, refer to the 'How to use MSTR' section below. The code is documented throughly so there is no need to look outside of the header file to understand how the functions work or when to use them. 

Just one more thing, however, this library is not made to be used in serious projects whatsoever. It is made for educational purposes. For *my* educational purposes. The code is documented and is also self-explantory; however, it is not optimized at all and it even might have some bugs (ones that I did not come cross yet). Perhaps, with me using the library more, I can add those optimizations and squash any bugs I might come cross. But, nonetheless, that could be in the next month or year. Again, this library was made for education purposes only and not as a well thought out project. I made this library after getting **extremly** angry at C++'s version of the string library. So, basically, this library is fueled by my hate and anger with C++.

# How to build MSTR?
MSTR uses cmake as it's defualt build system. Why use cmake and not Make? Because I know cmake but not Make. If you would rather sell your soul to the devil before ever toching the anti-christ that is cmake, then I inquire you to use another string library that doesn't suck. But... it does have a cool name, though, right? Also, for some good news, the library does not use any external dependencies, so you don't have to deal with linking errors. MSTR only uses some C libraries and that's it. 

Nonetheless, to build MSTR, all you have to do is run the following commands in your favorite terminal.

~~~
git clone https://github.com/MohamedAG2002/MSTR.git
cd MSTR
mkdir build 
cd build
cmake ..
make(or cmake --build . if on Windows)
~~~

After running the above commands, you should have the .a file ready in the **build** folder. All you have to do is take the header file (located in the root directory of the project), the .a file, and put them anywhere in your project. You can link to the library from any project either by using cmake, make, or any other build system. The following is an example of how you can use the library in your project using cmake. You can add these lines of code anywhere in your `CMakeLists.txt` file.

~~~cmake
# Put this before add_executable()
add_library(mstr mstr REQUIRED)

# Put these after add_executable()
target_include_directories(${PROJECT_NAME} PUBLIC (you can also make this PRIVATE) path/to/libmstr.a)
target_link_libraries(${PROJECT_NAME} mstr)
~~~

# How to use MSTR?
This library only has one header file. The header file only has one a couple of defines, some typedefs, and several functions. The following is the list of functions which are currently available in MSTR:

~~~c
// Typedefs 
typedef char* String;
typedef int MSTR_bool;

// Defines 
#define MSTR_TRUE  0
#define MSTR_FALSE 1

// Functions
size_t MSTR_GetStringLength(String str);
MSTR_bool MSTR_StringCompare(String str, String other);
String MSTR_ToUpperString(String str);
String MSTR_ToLowerString(String str);
char MSTR_ToUpperChar(char ch);
char MSTR_ToLowerChar(char ch);
MSTR_bool MSTR_IsCharUpperCase(char ch);
String MSTR_ToUpperFirstChar(String str);
String MSTR_ToUpperCharAfterWhitespace(String str);
MSTR_bool MSTR_IsLetter(char ch);
String MSTR_RemoveWhitespace(String str);
MSTR_bool MSTR_HasWhitespace(String str);
MSTR_bool MSTR_HasChar(String str, char ch);
String MSTR_ReplaceChar(String str, char target, char other);
String MSTR_AppendString(String target, String other);
String MSTR_ReverseString(String str);
~~~

As you can see, the library isn't huge and does not support other string functionality. However, it is extensively documented and verbose. Every function in the library uses the 'MSTR_' prefix to avoid any name collisions. 

# Some notes
As I said above, the code is not optimized at all. There are several functions in the library which allocate and deallocate data, which are very costly as you may know. So please use this library at your own caution. 

If you want to add more functionality to this library, fix some bugs, optimize the code, or copy the entire project and use it for your own projects, you are free to do so. It is in a public domain and thus *should* be the public's property.
