#include "sandpiles.h"

/** 
 * print_grid - prints resultant matrix
 * @matrix: resultant matrix
 */
static void print_grid(int grid[3][3])
{
  int i, j;
  printf("=\n");
  for (i = 0; i < 3; i++)
    {
      for (j = 0; j < 3; j++)
	{
	  if (j)
	    printf(" ");
	  printf("%d", grid[i][j]);
	}
      printf("\n");
    }
}

/**
 *sandpiles_sum - computes the sum of two sandpiles
 *@grid1: first grid to add
 *@grid2: second grid to add
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{

  /*int i, j, a, b, top, down, left, right, evaluate = 1;*/
  int i, j, a, b, evaluate = 1;
  int matrix[3][3];

  for (a = 0; a < 3; a++)
    {
      for (b = 0; b < 3; b++)
	{
	  matrix[a][b] = grid1[a][b] + grid2[a][b];	  
	}
    }
  print_grid(matrix);
  
  while (evaluate == 1) 
  {
    evaluate = 0;
    /*top = 0;
    down = 0;
    left = 0;
    right = 0;*/

    for (i = 0; i < 3; i++)
      {
	for (j = 0; j < 3; j++)
	  {
	    if (matrix[i][j] >= 4)
	      {
		/*if (i == 2 && j == 2 && matrix[i][j] >= 4)
		  break;*/
		if (i - 1 >= 0)
		  {
		    /*top = 1;*/
		    matrix[i - 1][j] += 1;
		    if (matrix[i - 1][j] >= 4)
		      evaluate = 1;
		    printf(" ^%d", matrix[i-1][j]);
		  }
		if (i + 1 < 3)
		  {
		    /*down = 1;*/
		    matrix[i + 1][j] += 1;
		    if (matrix[i + 1][j] >= 4)
		      evaluate = 1;
		    printf(" -%d", matrix[i + 1][j]);
		  }
		if (j - 1 >= 0)
		  {
		    /*left = 1;*/
		    matrix[i][j -1] += 1;
		    if (matrix[i][j - 1] >= 4)
		      evaluate = 1;
		    printf(" <%d", matrix[i][j - 1]);
		  }
		if (j + 1 < 3)
		  {
		    /*right = 1;*/
		    matrix[i][j + 1] +=1;
		    if (matrix[i][j + 1] >= 4)
		      evaluate = 1;
		    printf(" >%d", matrix[i][j + 1]);
		  }
		/*matrix[i][j] -= (top + down + left + right);*/
		matrix[i][j] -= 4;
		if (matrix[i][j] >= 4)
		  evaluate = 1;
		printf(" **%d**", matrix[i][j]);
	      }      
	  }
      }
    printf("*******");
    print_grid(matrix);
  }
}
