/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 07:59:11 by buranli           #+#    #+#             */
/*   Updated: 2025/10/13 15:30:50 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

int main(int argc, char **argv)
{
	t_map	*map;
	int		i;

	i = 1;
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
	return (0);
}