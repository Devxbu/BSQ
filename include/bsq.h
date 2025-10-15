/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 02:59:43 by buranli           #+#    #+#             */
/*   Updated: 2025/10/13 15:30:24 by buranli          ###   ########.fr       */
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
	short	**matrix;
	short	square_size;
	int				square_row;
	int				square_col;
}					t_map;

// Utils start
void                ft_memcpy(char *dest, const char *src, int num);
int                 ft_atoi(char *str);
t_map               *ft_map_error(void);
void                ft_free_map(t_map *map);
// Utils end
void                ft_process_map(t_map *map);
int                 ft_get_matrix(t_map *map, char *file_content);
int                 ft_header_map(t_map *map, char *file_content);
t_map               *ft_create_map(char *file_name);

#endif
