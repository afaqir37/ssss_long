#include "so_long.h"

void ft_free(char **map)
{

    int i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}
int ft_strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return 0;
        i++;
    }
    if (s1[i] || s2[i])
        return 0;
    return 1;
}
void ft_check_extension(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '.')
        i++;
    if (!(ft_strcmp(".ber", str + i)))
    {
        write(1, "Error\nInvalid file format. Map file must have the '.ber' extension", 66);
        exit(1);
    }
}
int ft_count_row(int fd)
{
    int i;
    char *s;

    i = 0;
    s = "";
    while (s)
    {
        s = get_next_line(fd);
        i++;
        if (!s)
        {
            i--;
        }
        free(s);
    }
    return (i);
}
void ft_fill_map(int fd, char **map)
{
    int i;

    i = 0;
    map[0] = "";
    while (map[i])
    {

        map[i] = get_next_line(fd);
        // if (map[i] && map[i][0] == '\n')
        // {
        //     free(map[i]);
        //     i--;
        // }
        i++;
    }
}