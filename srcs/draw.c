#include "../includes/fdf.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	perspective(float *x, float *y, float z, float angle)
{
	*x = (*x - *y) * cos(angle);
	*y = (*x + *y) * sin(angle) - z;
}

void	isometric(t_dot *a, t_dot *b, t_fdf *s)
{
	b->x = b->x * s->zoom;
	b->y = b->y * s->zoom;
	a->y = a->y * s->zoom;
	a->x = a->x * s->zoom;
	b->height = b->height * s->zoom / s->scale;
	a->height = a->height * s->zoom / s->scale;
	perspective(&a->x, &a->y, a->height, s->angle);
	perspective(&b->x, &b->y, b->height, s->angle);
	b->x = b->x + s->x_shift;
	b->y = b->y + s->y_shift;
	a->y = a->y + s->y_shift;
	a->x = a->x + s->x_shift;
}

void	draw_line(t_dot a, t_dot b, t_fdf *s)
{
	float	x_step;
	float	y_step;
	float	maximum;

	isometric(&a, &b, s);
	x_step = b.x - a.x;
	y_step = b.y - a.y;
	maximum = max(x_step, y_step);
	x_step /= maximum;
	y_step /= maximum;
	if (a.calor == 0)
		a.calor = 0x00ff00;
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		if (a.x >= s->img_size_x || a.y >= s->img_size_y || a.x < 0 || a.y < 0)
			break ;
		my_mlx_pixel_put(s->data, a.x, a.y, a.calor);
		a.x += x_step;
		a.y += y_step;
		if (a.x >= s->img_size_x || a.y >= s->img_size_y || a.x < 0 || a.y < 0)
			break ;
	}
}

void	draw(t_fdf *s)
{
	int		y;
	int		x;

	y = 0;
	while (y != s->length)
	{
		x = 0;
		while (x != s->width)
		{
			if (y == s->length - 1 && x + 1 < s->width)
				draw_line(*s->map[y][x], *s->map[y][x + 1], s);
			else if (x == s->width - 1 && y != s->length - 1)
			{
				draw_line(*s->map[y][x], *s->map[y + 1][x], s);
			}
			else if (x < s->width - 1 && y != s->length - 1)
			{
				draw_line(*s->map[y][x], *s->map[y][x + 1], s);
				draw_line(*s->map[y][x], *s->map[y + 1][x], s);
			}
			x++;
		}
		y++;
	}
}
