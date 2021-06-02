#include "../includes/libft.h"
#include "../includes/fdf.h"

void	init_strukt(t_fdf *s)
{
	s->error = 0;
	s->zoom = 8;
	s->img_size_x = 0;
	s->img_size_y = 0;
	s->length = 0;
	s->map = NULL;
	s->mlx_ptr = NULL;
	s->width = 0;
	s->win_ptr = NULL;
	s->img_size_x = 2000;
	s->img_size_y = 2000;
	s->x_shift = s->img_size_x / 3;
	s->y_shift = s->img_size_y / 3;
	s->data = NULL;
	s->scale = 1;
	s->angle = 0.8;
}

// int do_shit_for_test(int btn, t_fdf *s)
// {
// 	menage_param_cheng(btn, s);
// 	if (btn == 53)
// 		exit(1);
// 	if (btn == 123)
// 		s->x_shift -=10;
// 	if (btn == 124)
// 		s->x_shift +=10;
// 	if (btn == 126)
// 		s->y_shift -=10;
// 	if (btn == 125)
// 		s->y_shift +=10;
// 	mlx_clear_window(s->mlx_ptr, s->win_ptr);
// 	mlx_destroy_image(s->mlx_ptr, s->data->img);
// 	s->data->img = mlx_new_image(s->mlx_ptr, 2000, 2000);
// 	s->data->addr = mlx_get_data_addr(s->data->img,
//  &s->data->bits_per_pixel, &s->data->line_length, &s->data->endian);
// 	draw(s);
// 	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->data->img, 0, 0);
// 	ft_putnbr_fd(btn, 1);
// 	write(1, "\n", 1);
// 	return (0);
// }

int	main(int argc, char **argv)
{
	t_fdf	s;
	t_data	data;

	if (argc != 2)
	{
		write(2, "error\n", 6);
		return (0);
	}
	init_strukt(&s);
	s.mlx_ptr = mlx_init();
	s.width = get_width(argv, &s);
	s.length = get_length(argv, &s);
	s.win_ptr = mlx_new_window(s.mlx_ptr, 2000, 2000, "FdF");
	init_map(&s, argv, 0);
	if (s.error)
		return (0);
	data.img = mlx_new_image(s.mlx_ptr, 2000, 2000);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel,
			 &data.line_length, &data.endian);
	s.data = &data;
	draw(&s);
	mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, data.img, 0, 0);
	mlx_key_hook(s.win_ptr, button_press, &s);
	mlx_loop(s.mlx_ptr);
	free_t_fdf(&s);
}
