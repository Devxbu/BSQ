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
	int file;
	char *filename;
	t_map *map;
	char *test;
	char *test2;
	char *test3;
	int i;
	int j;

	test = (char *)malloc(sizeof(char) * 105);
	map = (t_map *)malloc(sizeof(t_map));
	filename = argv[1];

	if (argc < 2){
		file = STDIN_FILENO;
	} else {
		file = open(filename, O_RDONLY);
	}

	if (file == -1){
		return (0);
	}

	read(file, test, 105);
	char *test_start = test; // Save for freeing later

	test2 = NULL;
	i = 0;
	j = 0;
	while (*test >= '0' && *test <= '9')
	{
		test3 = (char *)malloc(sizeof(char) * (i + 2));
		for (j = 0; j < i; j++){
			test3[j] = test2[j];
		}
		test3[i] = *test;
		test3[i + 1] = '\0';

		if (test2 != NULL){
			free(test2);
		}
		test2 = test3;
		test++;
		i++;
	}

	int num = ft_atoi(test2);
	free(test2); // Free test2 after using it

	map->rows = num;
	map->empty = *test++;
	map->obstacle = *test++;
	map->full = *test++;

	// Skip newline character
	if (*test == '\n')
		test++;

	// Count columns from first line
	map->cols = 0;
	char *temp = test;
	while (*temp && *temp != '\n') {
		map->cols++;
		temp++;
	}

	printf("%d %d %c %c %c\n", map->cols, map->rows, map->empty, map->obstacle, map->full);

	map->matrix = (short **)malloc(sizeof(short *) * map->rows);

	i = 0;
	while (i < map->rows) {
		map->matrix[i] = (short *)malloc(sizeof(short) * map->cols);
		i++;
	}

	// Fill the matrix
	i = 0;
	while (i < map->rows) {
		j = 0;
		while (j < map->cols) {
			if (*test == '\n') { // Skip newlines
				test++;
				continue;
			}
			if (*test != map->obstacle) {
				map->matrix[i][j] = 1;
			} else {
				map->matrix[i][j] = 0;
			}
			test++;
			j++;
		}
		i++;
	}

	int max = 0;
	map->square_size = 0; // Initialize

	i = 1;
	while (i < map->rows)
	{
		j = 1;
		while (j < map->cols)
		{
			if (map->matrix[i][j] != 0)
			{
				int top = map->matrix[i - 1][j];
				int left = map->matrix[i][j - 1];
				int diag = map->matrix[i - 1][j - 1];
				int min = top;
				if (left < min)
					min = left;
				if (diag < min)
					min = diag;
				map->matrix[i][j] = min + 1;
			}
			if (map->matrix[i][j] > max)
			{
				max = map->matrix[i][j];
				map->square_row = i;
				map->square_col = j;
				map->square_size = max;
			}
			j++;
		}
		i++;
	}

	// Check if any square was found
	if (map->square_size > 0)
	{
		int start_row = map->square_row - map->square_size + 1;
		int start_col = map->square_col - map->square_size + 1;

		i = start_row;
		while (i <= map->square_row)
		{
			j = start_col;
			while (j <= map->square_col)
			{
				map->matrix[i][j] = -1;
				j++;
			}
			i++;
		}
	}
	printf("%d %d %d", map->square_col, map->square_row, map->square_size);

	// Print map
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			char c;
			if (map->matrix[i][j] == 0)
				c = map->obstacle;
			else if (map->matrix[i][j] == -1)
				c = map->full;
			else
				c = map->empty;
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}

	// Print map 01
	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			char c = map->matrix[i][j] + '0';
			write(1, &c, 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}

	// Clean up
	i = 0;
	while (i < map->rows) {
		free(map->matrix[i]);
		i++;
	}
	free(map->matrix);
	free(map);
	free(test_start);

	close(file);
	return (0);
}

// Open -> open(filename, file_descriptor);
// Read -> read(file_des
