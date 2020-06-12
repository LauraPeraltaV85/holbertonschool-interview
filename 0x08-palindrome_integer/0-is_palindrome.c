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
unsigned long int dec = 1;
unsigned long int dec_up = 1;
unsigned long int revn = 0;
unsigned long int original = n;

while (n > dec)
{
dec = dec * 10;
}
if (dec < 1)
return (1);
dec = dec / 10;

while (dec >= 1)
{
unit = n / dec;
n = n - (unit *dec);
revn = revn + (unit *dec_up);
dec_up = dec_up * 10;
dec = dec / 10;
}
return (original == revn);
}
