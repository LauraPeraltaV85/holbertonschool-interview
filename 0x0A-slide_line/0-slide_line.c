#include "slide_line.h"

#define LINE_SIZE 32

/**
 * reverse_array - reverse the array
 * @a: first input array
 * @n: second input length of first input
 *
 * Return: this function doesn't use return
 */
void reverse_array(int *a, int n)
{
  int a2 = 0;
  int izq;
  int der;
  n = n - 1;
  while (n > a2)
    {
      izq = a[a2];
      der = a[n];
      a[a2] = der;
      a[n] = izq;
      n = n - 1;
      a2 = a2 + 1;
    }
}

/**
 * left_order - order the array
 * @line: line points to an array of integers containing size elements
 * @size: Number of elements in line
 */
void left_order(int *line, size_t size)
{
  int con = 0, con2 = 0, pos = 0, flag = 0, count_Z = 0;
  con = size - 1;
  for (; con >= 0; con--)
    {
      if (flag == 1 && line[con] == 0)
	count_Z = count_Z + 1;
      if (line[con] > 0 && flag == 0)
	{
	  pos = con;
	  flag = 1;
	}
    }
  for (con2 = 0; con2 <= count_Z; con2++)
    {
      for (pos = size - 2; pos >= 0; pos--)
      {
	if (line[pos] == 0)
	  {
	    line[pos] = line[pos + 1];
	    line[pos + 1] = 0;
	  }
      }
    }
}


/**
 *slide_line - moves numbers and sums them as in 2048 game
 *@line: pointer to array of integers containing size elements
 *@direction: direction to slide the numbers to
 *@size: number of elements in the line
 *Return: 1 if success or 0 if failure
 */
int slide_line(int *line, size_t size, int direction)
{
  int con = 5;
  int con3 = 0;
  if (direction == 0)
    {
      left_order(line, size);
      con = size;
      for (con3 = 1; con3 < con; con3++)
	{
	  if (line[con3] == line[con3 - 1])
	    {
	      line[con3 - 1] = line[con3] * 2;
	      line[con3] = 0;
	    }
	}
      left_order(line, size);
      return (1);
    }
  if (direction == 1)
    {
      reverse_array(line, size);
      left_order(line, size);
      for (con3 = 1; con3 < con; con3++)
	{
	  if (line[con3] == line[con3 - 1])
	    {
	      line[con3 - 1] = line[con3] * 2;
	      line[con3] = 0;
	    }
	}
      left_order(line, size);
      reverse_array(line, size);
      return (1);
    }
  return (0);
}
