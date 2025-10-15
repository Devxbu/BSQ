/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:19:09 by buranli           #+#    #+#             */
/*   Updated: 2025/10/15 20:17:54 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/bsq.h"
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

int	ft_get_rows(char *file_content, int *read_count)
{
	int		i;
	char	*temp;
	char	*temp2;

	i = 0;
	temp = NULL;
	while (file_content[i] >= '0' && file_content[i] <= '9')
	{
		temp2 = (char *)malloc(sizeof(char) * (i + 2));
		if (!temp2)
			return (-1);
		if (temp)
			ft_memcpy(temp2, temp, i);
		temp2[i] = file_content[i];
		temp2[i + 1] = '\0';
		if (temp)
			free(temp);
		temp = temp2;
		i++;
	}
	*read_count = i;
	i = ft_atoi(temp);
	if (temp)
		free(temp);
	return (i);
}

int	ft_header_map(t_map *map, char *file_content)
{
	int	rows;
	int	i;

	rows = ft_get_rows(file_content, &i);
	map->rows = rows;
	if (map->rows <= 0)
		return (-1);
	map->empty = file_content[i];
	map->obstacle = file_content[i + 1];
	map->full = file_content[i + 2];
	if (file_content[i + 3] != '\n')
		return (-1);
	return (i + 4);
}

static char	*ft_join_and_free(char *s1, char *s2, int bytes)
{
	char	*new;
	int		len;

	len = 0;
	if (s1)
		while (s1[len])
			len++;
	new = (char *)malloc(len + bytes + 1);
	if (!new)
		return (NULL);
	if (s1)
	{
		ft_memcpy(new, s1, len);
		free(s1);
	}
	ft_memcpy(new + len, s2, bytes);
	new[len + bytes] = '\0';
	return (new);
}

char	*ft_get_file(int fd)
{
	char	buffer[BUFFER_SIZE];
	char	*file_content;
	int		bytes;

	file_content = NULL;
	bytes = read(fd, buffer, BUFFER_SIZE);
	while (bytes > 0)
	{
		file_content = ft_join_and_free(file_content, buffer, bytes);
		if (!file_content)
			return (NULL);
		bytes = read(fd, buffer, BUFFER_SIZE);
	}
	return (file_content);
}

t_map	*ft_create_map(char *file_name)
{
	t_map	*map;
	char	*file_content;
	int		fd;

	if (ft_init_fd_map(file_name, &map, &fd) < 0)
		return (ft_map_error());
	file_content = ft_get_file(fd);
	if (!file_content)
	{
		if (fd != STDIN_FILENO)
			close(fd);
		free(map);
		return (ft_map_error());
	}
	if (ft_parse_file(map, file_content, fd) < 0)
	{
		free(file_content);
		ft_free_map(map);
		return (ft_map_error());
	}
	free(file_content);
	return (map);
}
