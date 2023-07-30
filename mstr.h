#ifndef MSTR
#define MSTR

#include <stddef.h>
#include <stdint.h>

// If you want to instantiate a new string, use {}, with the string inside it
typedef struct 
{
  char* str;
} String;

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

#endif // MSTR
