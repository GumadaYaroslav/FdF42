#ifndef FDF_H
# define FDF_H
typedef struct s_fdf
{
	int	width;
	int	length;
	int	height;
	int	**map;
	int	error;
}				t_fdf;
#endif