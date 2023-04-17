#include "so_long.h"

void ft_process_map(char **map, int row)
{
    int i;
    int j;
    t_checker group;

    i = 0;
    j = 0;
    group.player_counter = 0;
    group.collectible = 0;
    group.exit_counter = 0;
    
    while (map[i])
    {
        if (i == 0 || i == row - 1)
            ft_check_walls(map, i, row);
        else
        {
            ft_check_all_walls(map, i);
            ft_check_elements(map, i, &group);
        }
        ft_check_rectangular(map, i, row);
        i++;
    }
    if (group.player_counter != 1 || !group.collectible || group.exit_counter != 1)
        ft_exit(map);
    if (!ft_valid_path(map))
        ft_nopath(map);
}
void ft_exit(char **map)
{
    ft_free(map);

    write(1, "Error\nInvalid characters", 24);
    exit(1);
}