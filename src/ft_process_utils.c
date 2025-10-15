/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:46:46 by buranli           #+#    #+#             */
/*   Updated: 2025/10/15 19:49:18 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	ft_check_first_line(t_map *map, int *max)
{
	int	j;

	j = 0;
	while (j < map->cols)
	{
		if (map->matrix[0][j] > *max)
		{
			*max = map->matrix[0][j];
			map->square_row = 0;
			map->square_col = j;
			map->square_size = *max;
		}
		j++;
	}
}

void	ft_check_first_col(t_map *map, int *max)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		if (map->matrix[i][0] > *max)
		{
			*max = map->matrix[i][0];
			map->square_row = i;
			map->square_col = 0;
			map->square_size = *max;
		}
		i++;
	}
}

void	ft_update_max(t_map *map, int i, int j, int *max)
{
	if (map->matrix[i][j] > *max)
	{
		*max = map->matrix[i][j];
		map->square_row = i;
		map->square_col = j;
		map->square_size = *max;
	}
}

void	ft_fill_map_matrix(t_map *map, int *max)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->rows)
	{
		j = 1;
		while (j < map->cols)
		{
			if (map->matrix[i][j] != 0)
				map->matrix[i][j] = ft_fill_cell(map, i, j);
			ft_update_max(map, i, j, max);
			j++;
		}
		i++;
	}
}
