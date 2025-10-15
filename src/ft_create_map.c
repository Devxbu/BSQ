#include "../include/bsq.h"

int ft_get_rows(char *file_content, int *read_count)
{
    int     i;
    char    *temp;
    char    *temp2;

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
    int rows = ft_atoi(temp);
    if (temp)
        free(temp);
    *read_count = i;
    return (rows);
}

int ft_header_map(t_map *map, char *file_content)
{
    int rows;
    int i;

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

char *ft_get_file(int file_descriptor)
{
    char    *file_content;
    char    *temp;
    char    buffer[1];
    int     size;
    int     byte;

    size = 0;
    file_content = NULL;
    while ((byte = read(file_descriptor, buffer, 1)) > 0)
    {
        temp = (char *)malloc(size + byte + 1);
        if (!temp)
            return (NULL);
        if (file_content)
            ft_memcpy(temp, file_content, size);
        temp[size] = buffer[0];
        size++;
        temp[size] = '\0';
        if (file_content)
            free(file_content);
        file_content = temp;
    }
    return (file_content);
}

t_map   *ft_create_map(char *file_name)
{
    char    *file_content;
    int     file_descriptor;
    t_map   *map;
    
    if (!file_name)
        file_descriptor = STDIN_FILENO;
    else
        file_descriptor = open(file_name, O_RDONLY);
    if (file_descriptor == -1)
        return (ft_map_error());
    map = (t_map *)malloc(sizeof(t_map));
    if (!map)
    {
        if (file_descriptor != STDIN_FILENO)
            close(file_descriptor);
        return (ft_map_error());
    }
    map->rows = 0;
    map->cols = 0;
    map->matrix = NULL;
    map->square_size = 0;
    map->square_row = 0;
    map->square_col = 0;
    file_content = ft_get_file(file_descriptor);
    if (!file_content)
    {
        if (file_descriptor != STDIN_FILENO)
            close(file_descriptor);
        free(map);
        return (ft_map_error());
    }
    int i = ft_header_map(map, file_content);
    if (i < 0)
    {
        free(file_content);
        if (file_descriptor != STDIN_FILENO)
            close(file_descriptor);
        free(map);
        return (ft_map_error());
    }
    if (!ft_get_matrix(map, &file_content[i]))
    {
        free(file_content);
        if (file_descriptor != STDIN_FILENO)
            close(file_descriptor);
        ft_free_map(map);
        return (ft_map_error());
    }
    free(file_content);
    if (file_descriptor != STDIN_FILENO)
        close(file_descriptor);
    return (map);
}
