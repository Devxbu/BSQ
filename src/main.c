/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 07:59:11 by buranli           #+#    #+#             */
/*   Updated: 2025/10/15 19:11:54 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

void	helper(int argc, char **argv, t_map *map)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		map = ft_create_map(argv[i]);
		if (map)
		{
			ft_process_map(map);
			ft_free_map(map);
		}
		i++;
		if (i < argc)
			write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	t_map	*map;

	map = NULL;
	if (argc < 2)
	{
		map = ft_create_map(NULL);
		if (map)
		{
			ft_process_map(map);
			ft_free_map(map);
		}
		return (0);
	}
	helper(argc, argv, map);
	return (0);
}
