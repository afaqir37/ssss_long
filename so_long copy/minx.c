#include <mlx.h>
#include <stdlib.h>
typedef struct s{
	void *mlx_ptr;
	void *win_ptr;
}	data;
int key_hook(int keycode, data*var)
{
	if(keycode == 2)
	{
		int a, b;
		void *img = mlx_xpm_file_to_image(var->mlx_ptr, "./img/right.xpm", &a, &b);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, img, 0,0);
	}
	if(keycode == 0)
	{
		int a, b;
		void *img = mlx_xpm_file_to_image(var->mlx_ptr, "./img/left.xpm", &a, &b);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, img, 0,0);
	}
	if(keycode == 13)
	{
		int a, b;
		void *img = mlx_xpm_file_to_image(var->mlx_ptr, "./img/back.xpm", &a, &b);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, img, 0,0);
	}
	if(keycode == 1)
	{
		int a, b;
		void *img = mlx_xpm_file_to_image(var->mlx_ptr, "./img/front.xpm", &a, &b);
		mlx_put_image_to_window(var->mlx_ptr, var->win_ptr, img, 0,0);
	}
	return 0;
}
int main(void)
{
	data var;

	int a;
	int b;
	var.mlx_ptr = mlx_init();
	var.win_ptr = mlx_new_window(var.mlx_ptr, 1920, 1080, "testing");
	void *img = mlx_xpm_file_to_image(var.mlx_ptr, "./img/floor.xpm", &a, &b);
	mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, img, 0, 0);
	img = mlx_xpm_file_to_image(var.mlx_ptr, "./img/front.xpm", &a, &b);
	mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, img, 0,0);
	img = mlx_xpm_file_to_image(var.mlx_ptr, "./img/floor.xpm", &a, &b);
	//mlx_put_image_to_window(var.mlx_ptr, var.win_ptr, img, 0, 0);
	//mlx_hook(var.win_ptr, 2, 1L << 0, key_hook, &var);
	
	mlx_loop(var.mlx_ptr);
	

}
