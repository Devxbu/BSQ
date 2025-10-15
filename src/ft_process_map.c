/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:31:15 by buranli           #+#    #+#             */
/*   Updated: 2025/10/15 19:49:31 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	ft_print_map(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
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

void	ft_update_map(t_map *map)
{
	int	i;
	int	j;
	int	start_row;
	int	start_col;

	if (map->square_size <= 0)
		return ;
	start_row = map->square_row - map->square_size + 1;
	start_col = map->square_col - map->square_size + 1;
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

int	ft_fill_cell(t_map *map, int i, int j)
{
	int	top;
	int	left;
	int	diag;
	int	min;

	top = map->matrix[i - 1][j];
	left = map->matrix[i][j - 1];
	diag = map->matrix[i - 1][j - 1];
	min = top;
	if (left < min)
		min = left;
	if (diag < min)
		min = diag;
	return (min + 1);
}

int	ft_dp(t_map *map)
{
	int	max;

	max = 0;
	map->square_size = 0;
	ft_check_first_line(map, &max);
	ft_check_first_col(map, &max);
	ft_fill_map_matrix(map, &max);
	ft_update_map(map);
	return (max);
}

void	ft_process_map(t_map *map)
{
	ft_dp(map);
	ft_print_map(map);
}
