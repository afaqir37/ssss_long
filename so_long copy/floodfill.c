#include "so_long.h"

void floodfill(int i, int j, char **map, int new_elem)
{
    if (map[i][j] == new_elem || map[i][j] == '1')
        return;

    map[i][j] = new_elem;

    floodfill(i + 1, j, map, new_elem);
    floodfill(i - 1, j, map, new_elem);
    floodfill(i, j + 1, map, new_elem);
    floodfill(i, j - 1, map, new_elem);
}
void ft_find_player(char **map, int *i, int *j)
{

    while (map[*i])
    {
        (*j) = 0;
        while (map[*i][*j])
        {
            if (map[*i][*j] == 'P')
                return;
            (*j)++;
        }
        (*i)++;
    }
}
int ft_valid_path(char **map)
{
    int i = 0;
    int j = 0;

    ft_find_player(map, &i, &j);

    floodfill(i, j, map, 'F');

    // i =0;
    // while(map[i])
    // {
    //     printf("%s", map[i]);
    //     i++;
    // }
    i = 0;
    j = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == 'E' || map[i][j] == 'C')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}