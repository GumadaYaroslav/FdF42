#include "../includes/libft.h"
#include "../includes/fdf.h"

int	error(t_fdf *s)
{
	s->error = 1;
	write(1, "error\n", 6);
	return (0);
}

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

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i != -1)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

int	get_width(char **argv, t_fdf *s)
{
	int		fd;
	char	*line;
	int		i;
	char	**str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error(s));
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		str = ft_split(line, ' ');
		if (str == NULL)
			return (error(s));
		while (str[i] != NULL)
			i++;
		if (i > s->width)
			s->width = i;
		free(line);
		ft_free_split(str);
	}
	free(line);
	close(fd);
	return (s->width);
}

int	get_length(char **argv, t_fdf *s)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(argv[1], O_RDONLY);
	i = 0;
	if (fd == -1)
		return (error(s));
	while (get_next_line(fd, &line) == 1)
	{
		i++;
		free(line);
	}
	free(line);
	close(fd);
	return (i);
}

void	help_get_arrays(t_dot ***s, char **str, int i, t_fdf *fdf)
{
	int		j;
	char	*tmp;

	j = 0;
	while (str[j])
	{
		s[i][j]->height = ft_atoi(str[j]);
		s[i][j]->x = j;
		s[i][j]->y = i;
		if (j == fdf->width - 1)
			s[i][j]->last = 1;
		else
			s[i][j]->last = 0;
		tmp = ft_strchr(str[j], ',');
		if (tmp)
			s[i][j]->calor = ft_atoi_base(tmp + 3, "0123456789ABCDEF", 16);
		j++;
	}
}

t_dot ***get_arrays(t_dot ****s, char **argv, int fd, t_fdf *fdf)
{
	char	**str;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1)
	{
		j = 0;
		str = ft_split(line, ' ');
		if (str == NULL)
			return (0);
		help_get_arrays(*s, str, i, fdf);
		free(line);
		ft_free_split(str);
		i++;
	}
	free(line);
	close(fd);
	return (*s);
}

int	init_map(t_fdf *s, char **argv, int j)
{
	int		i;
	t_dot	***arr;

	i = 0;
	arr = (t_dot ***)ft_calloc(s->length, sizeof(t_dot **));
	while (i < s->length)
	{
		arr[i] = ft_calloc(s->width, sizeof(t_dot *));
		j = 0;
		while (j < s->width)
		{
			arr[i][j] = ft_calloc(1, sizeof(t_dot));
			j++;
		}
		i++;
	}
	i = 0;
	if (arr == NULL)
		return (error(s));
	s->map = get_arrays(&arr, argv, -1, s);
	return (1);
}

void	free_t_fdf(t_fdf *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i != s->length)
	{
		j = 0;
		while (j != s->width)
		{
			free(s->map[i][j]);
			j++;
		}
		free(s->map[i]);
		i++;
	}
	free(s->map);
	free(s);
}

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
	{
		free_t_fdf(s);
		exit(1);
	}
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
// 	s->data->addr = mlx_get_data_addr(s->data->img, &s->data->bits_per_pixel, &s->data->line_length, &s->data->endian);
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
