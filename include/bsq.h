/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buranli <buranli@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 02:59:43 by buranli           #+#    #+#             */
/*   Updated: 2025/10/15 19:52:00 by buranli          ###   ########.fr       */
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
	short			**matrix;
	short			square_size;
	int				square_row;
	int				square_col;
}					t_map;

void	ft_memcpy(char *dest, const char *src, int num);
int		ft_atoi(char *str);
t_map	*ft_map_error(void);
void	ft_free_map(t_map *map);
void	ft_process_map(t_map *map);
int		ft_get_matrix(t_map *map, char *file_content);
int		ft_header_map(t_map *map, char *file_content);
t_map	*ft_create_map(char *file_name);
int		ft_init_fd_map(char *file_name, t_map **map, int *fd);
int		ft_parse_file(t_map *map, char *file_content, int fd);
void	ft_check_first_line(t_map *map, int *max);
void	ft_check_first_col(t_map *map, int *max);
void	ft_update_max(t_map *map, int i, int j, int *max);
void	ft_fill_map_matrix(t_map *map, int *max);
int		ft_fill_cell(t_map *map, int i, int j);
void	ft_update_map(t_map *map);
void	ft_print_map(t_map *map);

#endif
