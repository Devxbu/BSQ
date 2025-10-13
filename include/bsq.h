/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 02:59:43 by buranli           #+#    #+#             */
/*   Updated: 2025/10/13 03:03:12 by buranli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stddef.h>

typedef struct s_map
{
	int				rows;
	int				cols;
	char			empty;
	char			obstacle;
	char			full;
	unsigned short	**matrix;
	unsigned short	square_size;
	int				square_row;
	int				square_col;
}					t_map;

void				*ft_memcpy(void *dest, void *src, size_t num);
void				*ft_realloc(void *ptr, size_t old_size, size_t new_size);
int					ft_strcmp(char *s1, char *s2);
int					ft_atoi(char *str);
t_map				*ft_map_error(void);
void				ft_free_map(t_map *map);
void				ft_get_square(t_map *map);
void				ft_process_map(t_map *map);
int					ft_get_line(t_map *map, int i, int file_name);
int					ft_get_first_line(t_map *map, int file_name);
int					ft_get_matrix(t_map *map, int file_name);
int					ft_map_header(t_map *map, int file_name);
t_map				*ft_create_map(char *file_name);

#endif
