#include <stdio.h>

/**
 * print_grid - Prints a 3x3 grid
 * @grid: 3x3 integer grid
 *
 * Return: Nothing
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: first 3x3 grid (result stored here)
 * @grid2: second 3x3 grid
 *
 * Return: Nothing
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j, unstable;
	int tmp[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	while (1)
	{
		unstable = 0;

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
					unstable = 1;
			}
		}

		if (!unstable)
			break;

		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				tmp[i][j] = grid1[i][j];
		}

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					tmp[i][j] -= 4;

					if (i > 0)
						tmp[i - 1][j]++;

					if (i < 2)
						tmp[i + 1][j]++;

					if (j > 0)
						tmp[i][j - 1]++;

					if (j < 2)
						tmp[i][j + 1]++;
				}
			}
		}

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
				grid1[i][j] = tmp[i][j];
		}
	}
}
