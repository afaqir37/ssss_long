#include "so_long.h"

void ft_to_right(t_data *data)
{
    if (data->map[data->y_p / 50][data->x_p / 50 + 1] == '1')
    {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, data->x_p, data->y_p);
        return;
    }
    if (data->map[data->y_p / 50][data->x_p / 50 + 1] == 'C')
    {
        data->collect--;
        data->map[data->y_p / 50][data->x_p / 50 + 1] = 'V';
        if (data->collect <= 0)
            ft_open_door(data);
    }
    if (data->map[data->y_p / 50][data->x_p / 50 + 1] == 'E')
    {
        if (data->collect <= 0)
            ft_last_moment(data, data->img);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, data->x_p, data->y_p);
        return;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img1, data->x_p, data->y_p);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img, data->x_p + 50, data->y_p);
    data->x_p += 50;
    data->mouvement++;
    ft_put_string(data);
}
void ft_to_left(t_data *data)
{
    if (data->map[data->y_p / 50][data->x_p / 50 - 1] == '1')
    {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img2, data->x_p, data->y_p);
        return;
    }
    if (data->map[data->y_p / 50][data->x_p / 50 - 1] == 'C')
    {
        data->collect--;
        data->map[data->y_p / 50][data->x_p / 50 - 1] = 'V';
        if (data->collect <= 0)
            ft_open_door(data);
    }
    if (data->map[data->y_p / 50][data->x_p / 50 - 1] == 'E')
    {
        if (data->collect <= 0)
            ft_last_moment(data, data->img2);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img2, data->x_p, data->y_p);
        return;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img1, data->x_p, data->y_p);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img2, data->x_p - 50, data->y_p);
    data->x_p -= 50;
    data->mouvement++;
    ft_put_string(data);
}

void ft_to_back(t_data *data)
{
    if (data->map[data->y_p / 50 - 1][data->x_p / 50] == '1')
    {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img3, data->x_p, data->y_p);
        return;
    }
    if (data->map[data->y_p / 50 - 1][data->x_p / 50] == 'C')
    {
        data->map[data->y_p / 50 - 1][data->x_p / 50] = 'V';
        data->collect--;
        if (data->collect <= 0)
            ft_open_door(data);
    }
    if (data->map[data->y_p / 50 - 1][data->x_p / 50] == 'E')
    {
        if (data->collect <= 0)
            ft_last_moment(data, data->img3);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img3, data->x_p, data->y_p);
        return;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img1, data->x_p, data->y_p);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img3, data->x_p, data->y_p - 50);
    data->y_p -= 50;
    data->mouvement++;
    ft_put_string(data);
}
void ft_to_front(t_data *data)
{
    if (data->map[data->y_p / 50 + 1][data->x_p / 50] == '1')
    {
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img4, data->x_p, data->y_p);
        return;
    }
    if (data->map[data->y_p / 50 + 1][data->x_p / 50] == 'C')
    {
        data->collect--;
        data->map[data->y_p / 50 + 1][data->x_p / 50] = 'V';
        if (data->collect <= 0)
            ft_open_door(data);
    }
    if (data->map[data->y_p / 50 + 1][data->x_p / 50] == 'E')
    {
        if (data->collect <= 0)
            ft_last_moment(data, data->img4);
        mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img4, data->x_p, data->y_p);
        return;
    }
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img1, data->x_p, data->y_p);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img4, data->x_p, data->y_p + 50);
    data->y_p += 50;
    data->mouvement++;
    ft_put_string(data);
}
