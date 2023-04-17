#include "so_long.h"

char **ft_check_map(char **av)
{
    char **map;
    int i;
    int fd;

    fd = open(av[1], O_RDONLY);
    if (fd < 0 || fd == -1)
    {
        write(1, "Error\nPlease open a valid file", 30);
        exit(1);
    }
    i = ft_count_row(fd);

    map = malloc(sizeof(char *) * (i + 1));
    if (!map)
        exit(1);
    fd = open(av[1], O_RDONLY);
    if (fd < 0 || fd == -1)
        exit(1);

    ft_fill_map(fd, map);

    ft_process_map(map, i);
    ft_free(map);
    map = malloc(sizeof(char *) * (i + 1));
    if (!map)
        exit(1);
    fd = open(av[1], O_RDONLY);
    ft_fill_map(fd, map);

    return (map);
}
void ft_check_walls(char **map, int i, int row)
{
    int j;

    j = 0;
    while (map[i][j])
    {
        if (map[i][j] != '1' && map[i][j] != '\n' && i != row - 1)
        {
            ft_free(map);

            write(1, "Error\nYou need a wall, Right Now!", 33);
            exit(1);
        }
        else if (i == row - 1 && map[i][j] != '1')
        {
            ft_free(map);

            write(1, "Error\nYou need a wall, Right Now!", 33);
            exit(1);
        }
        j++;
    }
}
void ft_check_all_walls(char **map, int i)
{
    if (map[i][0] != '1' || map[i][ft_strlen(map[i]) - 2] != '1')
    {
        ft_free(map);

        write(1, "Error\nFill the gap in this wall!", 32);
        exit(1);
    }
}
void ft_check_elements(char **map, int i, t_checker *group)
{
    int j;

    j = 0;
    while (map[i][j])
    {
        if (map[i][j] == 'C')
            group->collectible++;
        else if (map[i][j] == 'E')
            group->exit_counter++;
        else if (map[i][j] == 'P')
            group->player_counter++;
        else if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != '\n')
        {

            ft_free(map);

            write(1, "Error\nInvalid element", 21);
            exit(1);
        }
        j++;
    }
}
void ft_check_rectangular(char **map, int i, int row)
{
    int len;

    len = ft_strlen(map[i]) - 1;

    if (map[i + 1] && i + 1 != row - 1 && ft_strlen(map[i + 1]) - 1 != len)
    {
        write(1, "Error\nMap not rectangular", 25);

        ft_free(map);

        exit(1);
    }
    else if (map[i + 1] && i + 1 == row - 1 && ft_strlen(map[i + 1]) != len)
    {
        write(1, "Error\nMap not rectangular", 25);
        ft_free(map);

        exit(1);
    }
}