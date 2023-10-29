#ifndef MSTR
#define MSTR

#include <stddef.h>
#include <stdint.h>

// Typedefs 
typedef char* String;
typedef int MSTR_bool;

// Defines 
#define MSTR_TRUE  0
#define MSTR_FALSE 1

// Return the length of the string by counting all the way till the null termination character.
// By the way, this function *does* count the null termination character. So it's the number 
// of characters in the string *plus* the null termination character.
size_t MSTR_GetStringLength(String str);

// Return true if the strings are equal and false if the strings have different sizes 
// or are completely different.
MSTR_bool MSTR_StringCompare(String str, String other);

// Return the upper case version of the given string
String MSTR_ToUpperString(String str);

// Return the lower case version of the given string
String MSTR_ToLowerString(String str);

// Return the upper case version of the given character
char MSTR_ToUpperChar(char ch);

// Return the lower case version of the given character
char MSTR_ToLowerChar(char ch);

// Returns true if the given character is upper case
MSTR_bool MSTR_IsCharUpperCase(char ch);

// Returns the modified version of the string where the first character is upper case
String MSTR_ToUpperFirstChar(String str);

// Capitlaizes the first character and every character after a whitespace
String MSTR_ToUpperCharAfterWhitespace(String str);

// Returns true if the given character is a letter (i.e between 'A'/'a' and 'Z'/'z')
// and false otherwise (i.e a number or symbol)
MSTR_bool MSTR_IsLetter(char ch);

// Returns a string completely devoid of any whitespace
String MSTR_RemoveWhitespace(String str);

// Returns if the given string contains any whitespace and false otherwise
MSTR_bool MSTR_HasWhitespace(String str);

// Returns true if the given string contains the given character
MSTR_bool MSTR_HasChar(String str, char ch);

// Returns the modified version of the given string where the given target character 
// is replaced with the given other character
String MSTR_ReplaceChar(String str, char target, char other);

// Returns a new string which is a combination of the target string and the other string
String MSTR_AppendString(String target, String other);

// Returns a modified version of the string where it is completely reversed
String MSTR_ReverseString(String str);

#endif // MSTR
