#include "../includes/fdf.h"
#include <stdio.h>
float		mod(float a)
{
	if (a > 0)
		return (a);
	return (-a);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_line(t_dot a, t_dot b, t_data *data, t_fdf *s)//[1,1 ] [3, 12]
{
	float x_step;
	float y_step;

	x_step = b.x - a.x;
	y_step = b.y - a.y;
	write(1, "1\n", 2);
	if (mod(x_step) > mod(y_step))
		x_step =x_step / x_step;
	else
		x_step = x_step / y_step;
	if (mod(x_step) > mod(y_step))
		y_step = y_step / x_step;
	else
		y_step = y_step / y_step;
	while((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		my_mlx_pixel_put(data, a.x, a.y, 0xffffff);
		a.x += x_step;
		a.x += y_step;
		if (a.x >= s->img_size_x || a.y >= s->img_size_y || a.x < 0 || a.y < 0)
			break;
	}
}

void	draw(t_data *data, t_fdf *s)
{
	int		y;
	int		x;

	y = 0;
	while (y != s->length - 1)
	{
		x = 0;
		while (x != s->width - 2)
		{
			if (y != s->length - 1)
				draw_line(*s->map[y][x], *s->map[y + 1][x], data, s);
			if (x == s->width - 1)
				draw_line(*s->map[y][x], *s->map[y][x + 1], data, s);
			if (x == s->width - 1)
				break ;
			x++;
		}
		y++;
	}
}