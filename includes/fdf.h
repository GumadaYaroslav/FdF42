#ifndef FDF_H
# define FDF_H
typedef struct s_dot
{
	int				height;
	unsigned long	calor;
}				t_dot;
typedef struct s_fdf
{
	int		width;
	int		length;
	int		height;
	t_dot	***map;
	int		error;
}				t_fdf;
#endif