#include "so_long.h"

void ft_nopath(char **map)
{
    ft_free(map);

    write(1, "Error\nThere's no valid path to the exit", 39);
    exit(1);
}
int handle(int key, t_data *data)
{

    if (key == 2 || key == 124)
        ft_to_right(data);
    if (key == 0 || key == 123)
        ft_to_left(data);
    if (key == 13 || key == 126)
        ft_to_back(data);
    if (key == 1 || key == 125)
        ft_to_front(data);
    if (key == 53)
    {
        ft_free(data->map);
        ft_destroy_images(data);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        exit(1);
    }

    return 0;
}
int ft_force_close(t_data *data)
{
    ft_destroy_images(data);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    ft_free(data->map);
    exit(1);
}
int ft_close(t_data *data)
{
    ft_free(data->map);
    exit(1);
}
int main(int argc, char **argv)
{
    int i;
    int j;
    t_data vars;

    if (argc != 2)
    {
        write(1, "Usage : ./so_long <map.ber>", 27);
        return (1);
    }
    ft_check_extension(argv[1]);
    vars.map = ft_check_map(argv);
    ft_get_dimensions(&i, &j, &vars);
    vars.mlx_ptr = mlx_init();
    if (!vars.mlx_ptr)
    {
        ft_free(vars.map);
        exit(1);
    }
    ft_initialize_img(&vars);
    vars.win_ptr = mlx_new_window(vars.mlx_ptr, vars.width * 50, vars.height * 50, "so_long");
    ft_render(&vars);
    mlx_hook(vars.win_ptr, 2, 1L << 0, handle, &vars);
    mlx_hook(vars.win_ptr, 17, 1L << 0, ft_close, &vars);
    mlx_loop(vars.mlx_ptr);
    return 0;
}
