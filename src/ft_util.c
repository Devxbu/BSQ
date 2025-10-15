/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:16:03 by buranli           #+#    #+#             */
/*   Updated: 2025/10/15 18:17:29 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

t_map	*ft_map_error(void)
{
	write(STDERR_FILENO, "map error\n", 10);
	return (NULL);
}

void	ft_memcpy(char *dest, const char *src, int num)
{
	int	i;

	if (!dest || !src)
		return ;
	i = 0;
	while (i < num)
	{
		dest[i] = src[i];
		i++;
	}
}

int	ft_atoi(char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (sign * num);
}

void	ft_free_map(t_map *map)
{
	int	i;

	if (!map)
		return ;
	if (map->matrix)
	{
		i = 0;
		while (i < map->rows)
		{
			if (map->matrix[i])
				free(map->matrix[i]);
			i++;
		}
		free(map->matrix);
	}
	free(map);
}
