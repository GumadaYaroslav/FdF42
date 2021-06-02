#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include <mlx.h>
# include <math.h>
typedef struct s_dot
{
	float			height;
	unsigned long	calor;
	int				last;
	float			x;
	float			y;
}				t_dot;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_fdf
{
	int		width;
	int		length;
	int		zoom;
	int		x_shift;
	int		y_shift;
	t_dot	***map;
	int		error;
	void	*mlx_ptr;
	void	*win_ptr;
	int		img_size_x;
	int		img_size_y;
}				t_fdf;
void	draw_line(t_dot a, t_dot b, t_data *data, t_fdf *s);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw(t_data *data, t_fdf *s);
#endif