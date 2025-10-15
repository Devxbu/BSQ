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
#include <stdio.h>
int main(int argc, char **argv)
{
	// Define Varaibles
	t_map	*map;
	int		i;

	i = 1;
	// If there is no argument, it will read from the standard input
	if (argc < 2)
	{
		map = ft_create_map(STDIN_FILENO);
		// If map is not empty, process the created map
		if (map)
			ft_process_map(map);
		return (0);
	}
	// Fetch all arguments
	while (i < argc)
	{
		// create map with given map name
		map = ft_create_map(argv[i]);
		// If it is not empty, process the created map
		if (map)
			ft_process_map(map);
		i++;
		// If there are more arguments, it generates a new line between the Maps
		if (i < argc)
			write(1, "\n", 1);
	}
	return (0);
}