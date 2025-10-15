#include "../include/bsq.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int file;
    char buffer[1];
    char *file_content = NULL;
    int bytes_read;
    int total_size = 0;

    file = open(argv[1], O_RDONLY);

    while ((bytes_read = read(file, buffer, 1)) > 0)
    {
        char *temp = malloc(total_size + bytes_read + 1);
        if (!temp)
            return (1);
        // eski veriyi kopyala
        if (file_content)
        {
            for (int i = 0; i < total_size; i++)
                temp[i] = file_content[i];
            free(file_content);
        }
        // yeni karakteri ekle
        temp[total_size] = buffer[0];
        total_size += bytes_read;
        temp[total_size] = '\0';
        file_content = temp;
    }

    if (file_content)
        printf("%s\n", file_content);

    free(file_content);
    close(file);
    return (0);
}
