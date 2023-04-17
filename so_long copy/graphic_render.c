#include "so_long.h"

void ft_get_dimensions(int *i, int *j, t_data *vars)
{
    *i = 0;
    *j = 0;
    while (vars->map[0][*j])
        (*j)++;

    while (vars->map[*i])
        (*i)++;
    if ((*i) == (*j) - 1)
    {
        write(1, "Error\nMap is not rectangular", 28);
        exit(0);
    }
    vars->height = (*i);
    vars->width = (*j) - 1;
    vars->mouvement = 0;
}

void ft_render(t_data *vars)
{
    int y1 = 0;
    int y_map = 0;
    int backup_w = vars->width;
    int x1;
    int x_map;
    vars->collect = 0;

    while (vars->height > 0)
    {
        x1 = 0;
        x_map = 0;
        while (vars->width > 0)
        {
            put_image_to_map(vars->map[y_map][x_map], x1, y1, &vars);
            x_map++;
            x1 += 50;
            vars->width--;
        }
        vars->width = backup_w;
        y_map++;
        y1 += 50;
        vars->height--;
    }
    ft_put_string(vars);
}
void put_image(t_data ***v, int x, int y, char *img)
{
    int img_w;
    int img_h;
    (**v)->tmp = mlx_xpm_file_to_image((**v)->mlx_ptr, img, &img_w, &img_h);
    // printf("%d %d\n", img_w, img_h);
    // exit(0);
    mlx_put_image_to_window((**v)->mlx_ptr, (**v)->win_ptr, (**v)->tmp, x, y);
}
void put_image_to_map(char p, int x1, int y1, t_data **v)
{
    if (p == '1')
        put_image(&v, x1, y1, "./img/wall.xpm");
    else if (p == 'C')
    {
        put_image(&v, x1, y1, "./img/floor.xpm");
        put_image(&v, x1, y1, "./img/collect.xpm");
        (*v)->collect++;
    }
    else if (p == 'E')
    {
        (*v)->x_e = x1;
        (*v)->y_e = y1;
        put_image(&v, x1, y1, "./img/exit.xpm");
    }
    else if (p == 'P')
    {
        (*v)->y_p = y1;
        (*v)->x_p = x1;
        put_image(&v, x1, y1, "./img/floor.xpm");
        put_image(&v, x1, y1, "./img/front.xpm");
    }
    else
        put_image(&v, x1, y1, "./img/floor.xpm");
}

void ft_put_string(t_data *data)
{
    int img_w, img_h;

    char *num = ft_itoa(data->mouvement);
    char *ok = ft_strdup("Move :");
    char *text = ft_strjoin(ok, num);
    printf("%s\n", text);
    // exit(0);

    (data)->tmp = mlx_xpm_file_to_image(
        (data)->mlx_ptr, "./img/wall.xpm", &img_w, &img_h);

    mlx_put_image_to_window(
        (data)->mlx_ptr, (data)->win_ptr, (data)->tmp, 50, 0);
    mlx_put_image_to_window(
        (data)->mlx_ptr, (data)->win_ptr, (data)->tmp, 50 * 2, 0);
    mlx_string_put(data->mlx_ptr, data->win_ptr, 50, 0, 0xffffff, text);
}
