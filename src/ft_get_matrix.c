/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:26:14 by buranli           #+#    #+#             */
/*   Updated: 2025/10/15 18:28:06 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	ft_fill_matrix(t_map *map, char *file_content)
{
	int	i;
	int	j;
	int	index;

	index = 0;
	i = 0;
	while (i < map->rows)
	{
		while (file_content[index] == '\n')
			index++;
		j = 0;
		while (j < map->cols)
		{
			if (!file_content[index])
				return ;
			map->matrix[i][j] = file_content[index] == map->empty;
			index++;
			j++;
		}
		if (file_content[index] == '\n')
			index++;
		i++;
	}
}

void	ft_get_col(t_map *map, char *file_content)
{
	int	i;

	i = 0;
	while (file_content[i] && file_content[i] != '\n')
		i++;
	map->cols = i;
}

int	ft_get_matrix(t_map *map, char *file_content)
{
	int	i;

	ft_get_col(map, file_content);
	map->matrix = (short **)malloc(sizeof(short *) * map->rows);
	if (!map->matrix)
		return (0);
	i = 0;
	while (i < map->rows)
	{
		map->matrix[i] = (short *)malloc(sizeof(short) * map->cols);
		if (!map->matrix[i])
		{
			while (--i >= 0)
				free(map->matrix[i]);
			free(map->matrix);
			return (0);
		}
		i++;
	}
	ft_fill_matrix(map, file_content);
	return (1);
}
