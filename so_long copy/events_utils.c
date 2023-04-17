#include "so_long.h"

void ft_free_fail(char **map)
{
    ft_free(map);
    exit(1);
}
void ft_destroy_images(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img);
    mlx_destroy_image(data->mlx_ptr, data->img1);
    mlx_destroy_image(data->mlx_ptr, data->img2);
    mlx_destroy_image(data->mlx_ptr, data->img3);
    mlx_destroy_image(data->mlx_ptr, data->img4);
    mlx_destroy_image(data->mlx_ptr, data->img5);
}
void ft_initialize_img(t_data *data)
{
    int a;
    int b;

    data->img = mlx_xpm_file_to_image(data->mlx_ptr, "./img/right.xpm", &a, &b);
    if (!data->img)
        ft_free_fail(data->map);
    data->img1 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/floor.xpm", &a, &b);
    if (!data->img1)
        ft_free_fail(data->map);
    data->img2 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/left.xpm", &a, &b);
    if (!data->img2)
        ft_free_fail(data->map);
    data->img3 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/back.xpm", &a, &b);
    if (!data->img3)
        ft_free_fail(data->map);
    data->img4 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/front.xpm", &a, &b);
    if (!data->img4)
        ft_free_fail(data->map);
    data->img5 = mlx_xpm_file_to_image(data->mlx_ptr, "./img/o_exit.xpm", &a, &b);
    if (!data->img5)
        ft_free_fail(data->map);
}
void ft_open_door(t_data *data)
{
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img5, data->x_e, data->y_e);
}
void ft_last_moment(t_data *data, void *img)
{
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, data->x_p, data->y_p);
    ft_destroy_images(data);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    ft_free(data->map);
    exit(0);
}