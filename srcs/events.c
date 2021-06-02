#include "../includes/fdf.h"

void	menage_param_chenges2(int btn, t_fdf *s)
{
	if (btn == 27)
	{
		if (s->zoom - 5 >= 0)
			s->zoom -= 5;
	}
	if (btn == 13)
		s->scale += 1;
	if (btn == 1)
	{
		if (s->scale - 1 > 0)
			s->scale -= 1;
	}
	if (btn == 0)
		s->angle += 0.01;
	if (btn == 2)
		s->angle -= 0.01;
}

void	menage_param_chenges1(int btn, t_fdf *s)
{
	if (btn == 53)
		exit(1);
	if (btn == 123)
		s->x_shift -=50;
	if (btn == 124)
		s->x_shift +=50;
	if (btn == 126)
		s->y_shift -=50;
	if (btn == 125)
		s->y_shift +=50;
	if (btn == 24)
		s->zoom += 5;
	menage_param_chenges2(btn, s);
}

int	button_press(int btn, t_fdf *s)
{
	menage_param_chenges1(btn, s);
	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	mlx_destroy_image(s->mlx_ptr, s->data->img);
	s->data->img = mlx_new_image(s->mlx_ptr, 2000, 2000);
	s->data->addr = mlx_get_data_addr(s->data->img, &s->data->bits_per_pixel,
			 &s->data->line_length, &s->data->endian);
	draw(s);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->data->img, 0, 0);
	ft_putnbr_fd(btn, 1);
	write(1, "\n", 1);
	return (0);
}
