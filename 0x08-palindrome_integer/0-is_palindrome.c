#include "palindrome.h"

/**
 *is_palindrome - checks whether or not a given
 *unsigned integer is a palindrome
 *@n: unsigned int
 *Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
int unit = 0;
unsigned long int revn = 0;
unsigned long int original = n;

while (dec >= 1)
{
unit = n % 10;
revn = (revn *(10)) + unit
n = n / 10;
}
return (original == revn);
}
