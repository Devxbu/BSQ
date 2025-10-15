/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 19:41:28 by buranli           #+#    #+#             */
/*   Updated: 2025/10/15 19:42:30 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"

int	ft_init_fd_map(char *file_name, t_map **map, int *fd)
{
	if (!file_name)
		*fd = STDIN_FILENO;
	else
		*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
		return (-1);
	*map = (t_map *)malloc(sizeof(t_map));
	if (!*map)
	{
		if (*fd != STDIN_FILENO)
			close(*fd);
		return (-1);
	}
	(*map)->rows = 0;
	(*map)->cols = 0;
	(*map)->matrix = NULL;
	(*map)->square_size = 0;
	(*map)->square_row = 0;
	(*map)->square_col = 0;
	return (0);
}

int	ft_parse_file(t_map *map, char *file_content, int fd)
{
	int	i;

	i = ft_header_map(map, file_content);
	if (i < 0)
		return (-1);
	if (!ft_get_matrix(map, &file_content[i]))
		return (-1);
	if (fd != STDIN_FILENO)
		close(fd);
	return (0);
}
