#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <mlx.h>

typedef struct data
{
    void    *mlx_ptr;
    void    *win_ptr;
    int     width;
    int     height;
    int     x_p;
    int     y_p;
    int     collect;
    int     x_e;
    int     y_e;
    int     mouvement;
    char    **map;
    void *img;
    void *img1;
    void *img2;
    void *img3;
    void *img4;
    void *img5;
    void *tmp;
} t_data;

typedef struct checker
{
    int player_counter;
    int collectible;
    int exit_counter;
} t_checker;
char *get_next_line(int fd);
int ft_strlen(char *s);
void ft_free(char **map);
int ft_valid_path(char **map);
char **ft_check_map(char **av);
void ft_process_map(char **map, int row);
void ft_get_dimensions(int *i, int *j, t_data *vars);
void ft_render(t_data *vars);
void put_image_to_map(char p, int x1, int y1, t_data **v);
void put_image(t_data ***v, int x, int y, char *img);
void ft_put_string(t_data *data);
void ft_check_walls(char **map, int i, int row);
void ft_exit(char **map);
void ft_nopath(char **map);
void ft_initialize_img(t_data *data);
void ft_to_right(t_data *data);
void ft_to_left(t_data *data);
void ft_to_back(t_data *data);
void ft_to_front(t_data *data);
void ft_destroy_images(t_data *data);
char	*ft_itoa(int n);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
void	*ft_calloc(size_t count, size_t size);
int ft_strcmp(char *s1, char *s2);
void ft_check_extension(char *str);
int ft_count_row(int fd);
void ft_fill_map(int fd, char **map);
char **ft_check_map(char **av);
void ft_check_walls(char **map, int i, int row);
void ft_check_all_walls(char **map, int i);
void ft_check_elements(char **map, int i, t_checker *group);
void ft_check_rectangular(char **map, int i, int row);
void ft_exit(char **map);
void ft_process_map(char **map, int row);
void ft_open_door(t_data *data);
void ft_last_moment(t_data *data, void *img);



#endif