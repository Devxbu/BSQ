#include "../include/bsq.h"

int ft_get_rows(char *file_content)
{
    int     i;
    char    *temp;
    char    *temp2;

    i = 0;
    temp = NULL;
    while (*file_content >= '0' && *file_content <= '9')
    {
        temp2 = (char *)malloc(sizeof(char) * (i + 2));
        if (!temp2)
            return (1);
        ft_memcpy(temp2, temp, i);
        temp2[i] = *file_content++;
        temp2[i + 1] = '\0';
        if (temp)
            free(temp);
        temp = temp2;
        i++;
    }
    if (temp)
        free(temp);
    return (ft_atoi(temp));
}

int ft_header_map(t_map *map, char *file_content, int file_descriptor)
{
    map->rows = ft_get_rows(file_content);
    map->empty = *file_content++;
    map->obstacle = *file_content++;
    map->full = *file_content++;

    while (*file_content != '\n')
        file_content++;
    return (0);
}

char *ft_get_file(int file_descriptor)
{
    char    *file_content;
    char    *temp;
    char    buffer[1];
    int     size;
    int     byte;
    int     i;

    size = 0;
    file_content = NULL;
    while ((byte = read(file_descriptor, buffer, 1)) > 0)
    {
        temp = (char *)malloc(size + byte + 1);
        if (!temp)
            return (NULL);
        ft_memcpy(temp, file_content, size);
        temp[size] = buffer[0];
        size++;
        temp[size] = '\0';
        file_content = temp;
    }
    return (file_content);
}

t_map   *ft_create_map(char *file_name)
{
    char    *file_content;
    int     file_descriptor;
    t_map   *map;
    
    if (!ft_strcmp(file_name, STDIN_FILENO))
        file_descriptor = STDIN_FILENO;
    else
        file_descriptor = open(file_name, O_RDONLY);
    map = (t_map *)malloc(sizeof(t_map));
    file_content = ft_get_file(file_descriptor);
    if (!file_content || file_descriptor == -1 || !map)
        return (ft_map_error());
    ft_header_map(map, file_content, file_descriptor);
    ft_get_matrix(map, file_content, file_descriptor);
}