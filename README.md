# What is MSTR?
Mutable, Manipulatable, and Malubale string or MSTR(prounanced Mister) for short is a string library made purly in C. The library itself is only one header file and one source file, and it does not use any C string functions(except 'memcpy' which is in the string.h library). All of the manipulation done with strings and characters are entirely done from scratch. Unfourtunately, MSTR only supports ASCII currently, with no plans to support UTF8 anytime soon. 

However, the library does include all types of string manipulation functions that you might need. To see the full functions list, refer to the 'How to use MSTR' section below. The code is documented throughly so there is no need to look outside of the header file to understand how the functions work or when to use them. 

Just one more thing, however, this library is not made to be used in serious projects whatsoever. It is made for educational purposes. For *my* educational purposes. The code is documented and is also self-explantory; however, it is not optimized at all and it even might have some bugs(ones that I did not come cross yet). Perhaps, with me using the library more, I can add those optimizations and squash any bugs I might come cross. But, nonetheless, that could be in the next month or year. Again, this library was made for education purposes only and not as a well thought out project. I made this library after getting **extremly** angry at C++'s version of the string library. So, basically, this library is fueled by my hate and anger with C++.

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

After running the above commands, you should have the .a file ready in the **build** folder. All you have to do is take the header file(located in the root directory of the project), the .a file, and put them anywhere in your project. You can link to the library from any project either by using cmake, make, or any other build system. The following is an example of how you can use the library in your project using cmake. You can add these lines of code anywhere in your `CMakeLists.txt` file.

~~~
# Put this before add_executable()
add_library(mstr mstr REQUIRED)

# Put these after add_executable()
target_include_directories(${PROJECT_NAME} PUBLIC(you can also make this PRIVATE) path/to/libmstr.a)
target_link_libraries(${PROJECT_NAME} mstr)
~~~

# How to use MSTR?
This library only has one header file. The header file only has one type(the `String` type) and several functions that operate on that type. The following is the list of functions which are currently available in MSTR:

~~~
// Counts every characters until the null-termination character 
// and returns the result.
size_t MR_GetStringLength(String* str);

// Prints the string to the console
void MR_PrintString(String* str);

// Returns 0 if the two given strings are the same, 1 if they are not the same or the strings are of different sizes, 
// and -1 if the two strings are similiar but have different capitilizations. 
// NOTE: Make sure to pass in strings of the same size, otherwise that will count as a fail case.
int MR_StringCompare(String* str, String other);

// Removes all of the whitespace in the given string.
void MR_RemoveWhitespace(String* str);

// Returns 0 if there is whitespace detected or 1 otherwise
int MR_HasWhitespace(String* str);

// Uppercases all characters in the string
void MR_ToUpper(String* str);

// Lowercases all characters in the string
void MR_ToLower(String* str);

// Returns 0 if the given character is upper cased. Otherwise, if the 
// character is lower case, it will return 1. This function can also return
// -1 if the character given was not a letter(i.e a symbol or number)
int MR_IsCharUpperCase(String* str, size_t index);

// Capitilizes the first letter of a string
void MR_ToUpperFirstChar(String* str);

// Capitilizes the first character and every character after a whitespace
// NOTE: This function will only capitilize every FIRST character after a whitespace.
void MR_ToUpperCharAfterWhitespace(String* str);

// Returns 0 if the character at the specified index is a letter.
// This function will check if the character at the given index is
// in the range of 'a' and 'z' or in the range of 'A' and 'Z'.
// Anything other than the characters between these two ranges are not letters
// and therefore the function will return 1.
// NOTE: The index should be counted from 0
int MR_IsLetter(String* str, size_t index);

// Return the character at the specified position.
// Returns the null-termination character(which is '\0') if position is out of bounds.
// Otherwise, it will return the actual character.
char MR_GetCharAt(String* str, size_t position);

// Looks for the specified character in the string.
// This function is case-sensitive, meaning, it will only look for the character
// that has the equivelent case to the given character.
// Returns 0 if the character was found and 1 if otherwise.
int MR_HasChar(String* str, char ch);

// Replace the 'target' character with the 'other' character.
// Returns 1 if the 'target' character was not found.
// NOTE: This function will only replace ONE instance of the 'target' character.
// So, if there are, say, two or more characters that are also identical to the 
// 'target' character, the function will ignore them entirely and only replace
// the FIRST instance of that character. So be careful.
int MR_ReplaceChar(String* str, char target, char other);

// Appends 'other' to 'target'. 
void MR_AppendString(String* target, String* other);

// Completely replace all characters of the target string by the given string
void MR_ChangeString(String* target, String* other);

// Reverses the string entirely
void MR_ReverseString(String* str);
~~~

As you can see, the library isn't huge and does not support other string functionality. However, it is extensively documented and verbose. Every function in the library uses the 'MR_' prefix to avoid any name collisions. 

# Some notes
As I said above, the code is not optimized at all. There are several functions in the library which allocate and deallocate data, which are very costly as you may know. So please use this library at your own caution. 

If you want to add more functionality to this library, fix some bugs, optimize the code, or copy the entire project and use it for your own projects, you are free to do so. It is in a public domain and thus *should* be the public's property.
