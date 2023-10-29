#include "mstr.h"

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

size_t MSTR_GetStringLength(String str)
{
  size_t size = 1;

  for(int i = 0; i < size; i++)
  {
    if(str[i] != '\0')
      size++;
    else break;
  }

  return size;
}

MSTR_bool MSTR_StringCompare(String str, String other)
{
  size_t strSize = MSTR_GetStringLength(str);
  size_t otherSize = MSTR_GetStringLength(other);
  
  // No way the strings are the same when different sizes 
  if(strSize != otherSize)
    return MSTR_FALSE;

  // Lower case both strings for easier comparison 
  str = MSTR_ToLowerString(str);  
  other = MSTR_ToLowerString(other);

  // Compare each character of the two strings
  for(int i = 0; i < strSize; i++)
  {
    // Return early if even one character is not the same
    if(str[i] != other[i])
      return MSTR_FALSE;
  }

  return MSTR_TRUE;
}

String MSTR_ToUpperString(String str)
{
  size_t strSize = MSTR_GetStringLength(str);

  // Allocating a temporary buffer to store the original string's content
  String tempStr = malloc(sizeof(char) * strSize);
  memcpy(tempStr, str, sizeof(char) * strSize);
  str = 0;

  // Treat the string literal as a memory buffer to be able to access and alter each character
  str = malloc(sizeof(char) * strSize);

  for (int i = 0; i < strSize; i++) 
  {
    str[i] = MSTR_ToUpperChar(tempStr[i]);
  }

  free(tempStr);
  
  return str;
}

String MSTR_ToLowerString(String str)
{
  size_t strSize = MSTR_GetStringLength(str);
  
  // Allocating a temporary buffer to store the original string's content
  String tempStr = malloc(sizeof(char) * strSize);
  memcpy(tempStr, str, sizeof(char) * strSize);
  str = 0; 

  // Treat the string literal as a memory buffer to be able to access and alter each character
  str = malloc(sizeof(char) * strSize);

  for (int i = 0; i < strSize; i++) 
  {
    str[i] = MSTR_ToLowerChar(tempStr[i]);
  }

  free(tempStr);

  return str;
}

char MSTR_ToUpperChar(char ch)
{
    // Check if the character is a letter since this is capitalizing the 
    // character with the ASCII standerd which has the characters--both lower case 
    // and upper case--spaced by 32.     
  if(MSTR_IsLetter(ch) == MSTR_TRUE && MSTR_IsCharUpperCase(ch) == MSTR_FALSE)
    return ch -= 32;
  else 
    return ch;
}

char MSTR_ToLowerChar(char ch)
{
  if(MSTR_IsLetter(ch) == MSTR_TRUE && MSTR_IsCharUpperCase(ch) == MSTR_TRUE)
    return ch += 32;
  else 
    return ch;
}

MSTR_bool MSTR_IsCharUpperCase(char ch)
{
  if(MSTR_IsLetter(ch) == MSTR_FALSE)
    return MSTR_FALSE;

  if(ch >= 'A' && ch <= 'Z')
    return MSTR_TRUE;

  return MSTR_FALSE;
}

String MSTR_ToUpperFirstChar(String str)
{
  return MSTR_ReplaceChar(str, str[0], MSTR_ToUpperChar(str[0]));
}

String MSTR_ToUpperCharAfterWhitespace(String str)
{
  size_t len = MSTR_GetStringLength(str);

  String tempStr = malloc(sizeof(char[len]));
  memcpy(tempStr, str, sizeof(char[len]));
  str = 0;

  str = malloc(sizeof(char[len]));
  memcpy(str, tempStr, sizeof(char[len]));
  free(tempStr);

  // Upper case the first character 
  str[0] = MSTR_ToUpperChar(str[0]);

  for(int i = 1; i < len; i++)
  {
    if(tempStr[i - 1] == ' ')
      str[i] = MSTR_ToUpperChar(str[i]);
  }

  return str;
}

MSTR_bool MSTR_IsLetter(char ch)
{
  if((ch >= 'A' && ch <= 'Z') || 
     (ch >= 'a' && ch <= 'z'))
    return MSTR_TRUE;

  return MSTR_FALSE;
}

String MSTR_RemoveWhitespace(String str)
{
  size_t len = MSTR_GetStringLength(str);
  size_t newLen = len; 
  int whitespaces = 0;

  // Count whitespaces 
  for(int i = 0; i < len; i++)
  {
    if(str[i] == ' ')
      whitespaces++;
  }

  // Take the whitespaces our of the equation
  newLen -= whitespaces;

  // Create a temporary string buffer with new length
  String tempStr = malloc(sizeof(char[newLen]));

  int tempIndex = 0;
  for(int i = 0; i < len; i++)
  {
    // Ignore whitespaces
    if(str[i] == ' ')
      continue;

    // Make sure to only index into the temporary string buffer when you 
    // copy non-whitespace characters. The tempIndex is here to help with that.
    tempStr[tempIndex] = str[i];
    tempIndex++;
  }

  // Remove the contents of the old string
  str = 0;
 
  // Allocate a new array for the string, copy the contents of the temporary 
  // string into the newly allocated string buffer, and remove the temporary string.
  str = malloc(sizeof(char[newLen]));
  memcpy(str, tempStr, sizeof(char[newLen]));
  free(tempStr);
  
  return str;
}

MSTR_bool MSTR_HasWhitespace(String str)
{
  return MSTR_HasChar(str, ' ');
}

MSTR_bool MSTR_HasChar(String str, char ch)
{
  size_t size = MSTR_GetStringLength(str);

  for(int i = 0; i < size; i++)
  {
    if(str[i] == ch)
      return MSTR_TRUE;
  }

  return MSTR_FALSE;
}

String MSTR_ReplaceChar(String str, char target, char other)
{
  size_t size = MSTR_GetStringLength(str);

  // Doing a switch to have the string literal be treated as a memory buffer 
  // instead in order for the ability to change any character.
  String tempStr = malloc(sizeof(char) * size);
  memcpy(tempStr, str, sizeof(char) * size);
  str = 0; 

  str = malloc(sizeof(char) * size);
  memcpy(str, tempStr, sizeof(char) * size);
  
  free(tempStr);

  for(int i = 0; i < size; i++)
  {
    // Replace the found character and return early
    if(str[i] == target)
      str[i] = other;
  }

  return str;
}

String MSTR_AppendString(String target, String other)
{
  size_t len1 = MSTR_GetStringLength(target) - 1; // Fuck off null termination character
  size_t len2 = MSTR_GetStringLength(other);

  String tempStr = malloc(sizeof(char[len1]));
  memcpy(tempStr, target, sizeof(char[len1]));
  target = 0; 

  target = malloc(sizeof(char[len1 + len2]));
  memcpy(target, tempStr, sizeof(char[len1]));

  // Copying over the other string to the target string
  for(int i = 0; i < len2; i++)
    target[len1 + i] = other[i];

  free(tempStr);

  return target;
}

String MSTR_ReverseString(String str)
{
  size_t len = MSTR_GetStringLength(str) - 1;

  String tempStr = malloc(sizeof(char[len]));
  memcpy(tempStr, str, sizeof(char[len]));
  str = 0;

  str = malloc(sizeof(char[len]));

  for(int i = 0; i <= len; i++)
    str[i - 1] = tempStr[len - i];  

  free(tempStr);

  return str;
}

