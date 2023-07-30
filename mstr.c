#include "mstr.h"

#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

size_t MR_GetStringLength(String* str)
{
  // Getting the size of the string
  size_t count = 1;
  for(int i = 0; i < count; i++)
  {
    // Is not at the end of the given string.
    // i.e the current character is not a null-termination character
    if(str->str[i] != '\0')
      count++;
    else
      break;
  }
  
  return count;
}

void MR_PrintString(String* str)
{
  for(int i = 0; i < MR_GetStringLength(str); i++)
  {
    printf("%c", str->str[i]);
  }
}

int MR_StringCompare(String* str, String other)
{
  size_t strLength = MR_GetStringLength(str);
  size_t otherLength = MR_GetStringLength(&other);

  // The strings are not of the same size
  if(strLength != otherLength)
    return 1;

  int successCases = 0;
  int capitalizeFailCase = 0;
  for(int i = 0; i < strLength; i++)
  {
    // Check if the two current characters are the same
    if(str->str[i] == other.str[i])
    {
      successCases++;
      continue;
    }

    // Make sure to check if both are symbols
    if(MR_IsLetter(str, i) != 0 && MR_IsLetter(&other, i) != 0)
    {
      // Increase the success cases and move on
      if(str->str[i] == other.str[i])   
      {
        successCases++;
        continue;
      }

      // Otherwise, the symbols are not the same and we have a failure case, 
      // which means the strings are not the same, even if there are more characters
      // to compare.
      return 1;
    }
    // If both are not letter, one of the characters can also be a letter and other a symbol or a number.
    // In that case they CANNOT be the same in any way possible. So, fail.
    else if(MR_IsLetter(str, i) != 0 || MR_IsLetter(&other, i) != 0)
      return 1; 

    // Two copies of the current characters for easier visualization
    char c1, c2;

    // if the current character from 'str' is upper case, 
    // lower case it for comparison.
    if(MR_IsCharUpperCase(str, i) == 0)
      c1 = str->str[i] + 32;
    else 
      c1 = str->str[i];

    // Do the same thing to the character from the 'other' string
    if(MR_IsCharUpperCase(&other, i) == 0)
      c2 = other.str[i] + 32;
    else 
      c2 = other.str[i];

    // Now that the characters are both lower cases, they need to be compared again.
    // If both are the same, that means there could be a capitilization issues. 
    // Increase the counter relevant to that case and move on. Otherwise, the characters
    // cannot be the same at all, as they failed all of the checks above.
    if(c1 == c2)
    {
      capitalizeFailCase++;
      continue;
    } 

    // Even though there are more characters to compare, having one fail
    // case will mean that the strings are not the same at all, even after 
    // the checks above.
    return 1;
  }
  
  // The characters are all identical
  if(successCases == strLength)
    return 0;
  // Otherwise, the strings are the same but have different capitilization
  else if(capitalizeFailCase > 0)
    return -1;

  // Return default value in all other cases
  return 1;
}

void MR_RemoveWhitespace(String* str)
{
  size_t length = MR_GetStringLength(str);
  
  int whitespaceCounter = 0;
  for(int i = 0; i < length; i++)
  {
    if(str->str[i] == ' ')
      whitespaceCounter++;
  }
  
  // Make a temporary array with the modified length that takes out whitespaces
  int newLength = length - whitespaceCounter;
  char* tempArr = (char*)malloc(sizeof(char) * newLength);

  // Copies every character that's not a whitespace into the temporary array
  int tempIndex = 0;
  for(int i = 0; i < length; i++)
  {
    // Once the current character is a whitespace, make sure to not increase the 
    // temporary index since the array is allocated with whitespaces taken out of the 
    // equation. However, when the current character is not a whitespace, you can 
    // simply index into the temporary array and copy whatever is in the given string
    // into it.
    if(str->str[i] != ' ')
    {
      tempArr[tempIndex] = str->str[i];
      tempIndex++;
    }
  }
  
  // Delete the old string
  str->str = 0;

  // Copy the temporary array into the given string
  str->str = (char*)malloc(sizeof(char) * newLength);
  memcpy(str->str, tempArr, sizeof(char) * newLength);

  free(tempArr);
}

int MR_HasWhitespace(String* str)
{
  return MR_HasChar(str, ' ');
}

void MR_ToUpper(String* str)
{
  size_t length = MR_GetStringLength(str);
 
  // If you are confused by this, refer to the same code in the 
  // 'MR_ReplaceChar' function to get an exmplanation.
  char* tempArr = (char*)malloc(sizeof(char) * length - 1);
  memcpy(tempArr, str->str, sizeof(char) * length - 1); 
  str->str = tempArr;

  for(int i = 0; i < length; i++)
  {
    // Skip if the character is not a letter
    if(MR_IsLetter(str, i) != 0)
      continue;
    
    // Upper case the current character if it's lower case.
    // Otherwise, the character is already upper case and it can 
    // safely be ignored.
    if(MR_IsCharUpperCase(str, i) != 0)
      str->str[i] -= 32;
  }

  free(tempArr);
}

void MR_ToLower(String* str)
{
  size_t length = MR_GetStringLength(str);
  
  // If you are confused by this, refer to the same code in the 
  // 'MR_ReplaceChar' function to get an exmplanation.
  char* tempArr = (char*)malloc(sizeof(char) * length - 1);
  memcpy(tempArr, str->str, sizeof(char) * length - 1); 
  str->str = tempArr;
  
  for(int i = 0; i < length; i++)
  {
    // Skip if the character is not a letter
    if(MR_IsLetter(str, i) != 0)
      continue;
   
    // Lower case the current character if it's upper case.
    // Otherwise, the character is already lower case and it can 
    // safely be ignored.
    if(MR_IsCharUpperCase(str, i) == 0)
      str->str[i] += 32;
  }

  free(tempArr);
}

int MR_IsCharUpperCase(String* str, size_t index)
{
  if(MR_IsLetter(str, index) != 0)
    return -1;

  if(str->str[index] >= 'A' && str->str[index] <= 'Z')
    return 0;

  return 1;
}

void MR_ToUpperFirstChar(String* str)
{
  size_t length = MR_GetStringLength(str);

  // If you are confused by this, refer to the same code in the 
  // 'MR_ReplaceChar' function to get an exmplanation.
  char* tempArr = (char*)malloc(sizeof(char) * length - 1);
  memcpy(tempArr, str->str, sizeof(char) * length - 1); 
  str->str = tempArr;
  
  // Do nothing if the character is not a letter
  if(MR_IsLetter(str, 0) != 0)
    return;
    
  // Do nothing when if the character is already capitilized
  if(MR_IsCharUpperCase(str, 0) == 0)
   return;
  
  str->str[0] -= 32;

  free(tempArr);
}

void MR_ToUpperCharAfterWhitespace(String* str)
{
  size_t length = MR_GetStringLength(str);
  
  // If you are confused by this, refer to the same code in the 
  // 'MR_ReplaceChar' function to get an exmplanation.
  char* tempArr = (char*)malloc(sizeof(char) * length - 1);
  memcpy(tempArr, str->str, sizeof(char) * length - 1); 
  str->str = tempArr;
  
  for(int i = 0; i < length; i++)
  {
    // Break if the character is not a letter
    if(MR_IsLetter(str, 0) != 0)
      continue;

    // Skip if the current character is already capitilized
    if(MR_IsCharUpperCase(str, i) == 0)
      continue;

    // Capitilize the first letter in any case(except the above)
    if(i == 0)
    {
      str->str[0] -= 32;
      continue;
    }

    // Capitilize the current character if the previous character is a whitespace
    if(str->str[i - 1] == ' ')
      str->str[i] -= 32;
  }

  free(tempArr);
}

int MR_IsLetter(String* str, size_t index)
{
  if((str->str[index] >= 'A' && str->str[index] <= 'Z') ||
    (str->str[index] >= 'a') && (str->str[index]) <= 'z')
    return 0;

  return 1;
}

char MR_GetCharAt(String* str, size_t index)
{
  size_t length = MR_GetStringLength(str);
  
  // Out of bounds check
  if(index < 0 || index > length)
    return '\0';

  return str->str[index];
}

int MR_HasChar(String* str, char ch)
{
  size_t length = MR_GetStringLength(str);
  
  for(int i = 0; i < length; i++)
  {
    if(str->str[i] == ch)
      return 0;
  }

  return 1;
}

int MR_ReplaceChar(String* str, char target, char other)
{
  size_t length = MR_GetStringLength(str);
 
  // Doing this so that this function can replace the character in the string,
  // since string literals cannot be changed. Having a new array allocated somewhere,
  // copying everything from the original array, and making the original array point to
  // the temporary one will make it safe to change anything in the string.
  // Also the length is decreased by one so that the 'memcpy' function accounts for 
  // the null-termination character.
  char* tempArr = (char*)malloc(sizeof(char) * length - 1);
  memcpy(tempArr, str->str, sizeof(char) * length - 1); 
  str->str = tempArr;

  for(int i = 0; i < length; i++)
  {
    // The character was found, so replace it with the other given character
    if(str->str[i] == target)
    {
      str->str[i] = other; 
      
      // The operation was successfully completed so exit the function with 
      // the success case
      return 0;
    }
  }

  // Getting rid of the temporary array
  free(tempArr);

  return 1;
}

void MR_AppendString(String* target, String* other)
{
  size_t targetLen = MR_GetStringLength(target);
  size_t otherLen = MR_GetStringLength(other);
  
  // Making the new string count from the to given strings and taking away
  // the two null-termination characters that exist in the given strings
  int newStrCount = (targetLen + otherLen) - 2;
  
  // A temporary string that will be deleted later
  char* newStr = (char*)malloc(sizeof(char) * newStrCount);
  
  // Copy the from the 'target' string
  for(int i = 0; i < targetLen; i++)
  {
    newStr[i] = target->str[i];
  }

  // Copy from the 'other' string
  for(int i = 0; i < otherLen; i++)
  {
    // Start from the end of the 'target' string(taking into account the null-termination)
    newStr[(i + targetLen) - 1] = other->str[i];
  } 

  // Reset the string in order to replace it
  target->str = 0;

  // Making a new array in the 'target' string
  target->str = (char*)malloc(sizeof(char) * newStrCount);

  // Copying the newly created string to the 'target' string
  memcpy(target->str, newStr, sizeof(char) * newStrCount);

  // Deintializing the temporary array
  free(newStr);
  newStr = 0;
}

void MR_ChangeString(String* target, String* other)
{
  // Make room for the new string by deleting the old one
  target->str = 0;

  // Making a new array in the 'target' string
  size_t length = MR_GetStringLength(other);
  target->str = (char*)malloc(sizeof(char) * length);
  
  // Copy the contents of the "other" string to the "target" string
  memcpy(target->str, other->str, sizeof(char) * length);
}

void MR_ReverseString(String* str)
{
  size_t length = MR_GetStringLength(str) - 1;
  char* tempArr = (char*)malloc(sizeof(char) * length);

  // Going through the string from back to front and copying
  // every character to the temporary array
  for(int i = length - 1, j = 0; i >= 0 && j < length; i--, j++)
  {
    tempArr[j] = str->str[i];   
  }

  // Making room for the new string
  str->str = 0;

  // Making a new string array
  str->str = (char*)malloc(sizeof(char) * length);
  
  // Copy the contents of the "other" string to the "target" string
  memcpy(str->str, tempArr, sizeof(char) * length);
  free(tempArr);
}
