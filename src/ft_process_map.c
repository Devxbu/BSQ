#include "../include/bsq.h"

void ft_print_map(t_map *map)
{
	int i;
    int j;
    i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			char c;
			if (map->matrix[i][j] == 0)
				c = map->obstacle;
			else if (map->matrix[i][j] == -1)
				c = map->full;
			else
				c = map->empty;
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void ft_update_map(t_map *map)
{
    int i;
    int j;

    if (map->square_size > 0)
	{
		int start_row = map->square_row - map->square_size + 1;
		int start_col = map->square_col - map->square_size + 1;

		i = start_row;
		while (i <= map->square_row)
		{
			j = start_col;
			while (j <= map->square_col)
			{
				map->matrix[i][j] = -1;
				j++;
			}
			i++;
		}
	}
}

int ft_dp(t_map *map)
{
    int i;
    int j;
	int max = 0;
	map->square_size = 0; // Initialize

    // consider first row
    i = 0;
    j = 0;
    while (j < map->cols)
    {
        if (map->matrix[0][j] > max)
        {
            max = map->matrix[0][j];
            map->square_row = 0;
            map->square_col = j;
            map->square_size = max;
        }
        j++;
    }
    // consider first column
    i = 0;
    while (i < map->rows)
    {
        if (map->matrix[i][0] > max)
        {
            max = map->matrix[i][0];
            map->square_row = i;
            map->square_col = 0;
            map->square_size = max;
        }
        i++;
    }

	i = 1;
	while (i < map->rows)
	{
		j = 1;
		while (j < map->cols)
		{
			if (map->matrix[i][j] != 0)
			{
				int top = map->matrix[i - 1][j];
				int left = map->matrix[i][j - 1];
				int diag = map->matrix[i - 1][j - 1];
				int min = top;
				if (left < min)
					min = left;
				if (diag < min)
					min = diag;
				map->matrix[i][j] = min + 1;
			}
			if (map->matrix[i][j] > max)
			{
				max = map->matrix[i][j];
				map->square_row = i;
				map->square_col = j;
				map->square_size = max;
			}
			j++;
		}
		i++;
	}
    ft_update_map(map);
    return (max);
}

void ft_process_map(t_map *map)
{
	ft_dp(map);
    ft_print_map(map);
}