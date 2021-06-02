#include "../includes/libft.h"
#include "../includes/fdf.h"

int	error(t_fdf *s)
{
	s->error = 1;
	write(1, "error\n", 6);
	return (0);
}

void init_strukt(t_fdf *s)
{
	s->error = 0;
	s->zoom = 30;
	s->img_size_x = 0;
	s->img_size_y = 0;
	s->length = 0;
	s->map = NULL;
	s->mlx_ptr = NULL;
	s->width = 0;
	s->win_ptr = NULL;
	s->x_shift = 150;
	s->y_shift = 150;
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
	}	
	// printf("%d - x\n", s->width);
	ft_free_split(str);
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
		if(j == fdf->width - 1)
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
		// write(1, "1\n", 2);
		str = ft_split(line, ' ');
		if (str == NULL)
			return 0;
		// write(1, "1\n", 2);
		help_get_arrays(*s, str, i, fdf);
		free(line);
		ft_free_split(str);
		i++;
	}
	free(line);
	// ft_free_split(str);
	close(fd);
	return (*s);
}

int init_map(t_fdf *s, char **argv, int j)
{
	int		i;
	t_dot	***arr;

	i = 0;
	write(1, "2", 1);
	arr = (t_dot ***)ft_calloc(s->length, sizeof(t_dot **));
	while (i < s->length)
	{
		// write(1, "2\n", 2);
		arr[i] = ft_calloc(s->width, sizeof(t_dot *));
		j = 0;
		while (j < s->width)
		{
			// write(1, "2\n", 2);
			arr[i][j] = ft_calloc(1, sizeof(t_dot));
			j++;
		}
		printf("%d -it's me CALLOC!\n", j);
		i++;
	}
	i = 0;
	// write(1, "2", 1);
	printf("%lu -> sizeof(arr)\n", s->length * sizeof(int *));
	if (arr == NULL)
		return (error(s));
	// while (i != s->length + 1)
	// {
	// 	arr[i] = (t_dot *)ft_calloc(s->width, sizeof(t_dot *));
	// 	j = 0;
	// 	while (j != s->width)
	// 	{
	// 		arr[i][j] = ft_calloc(1, sizeof(t_dot));
	// 		j++;
	// 	}
	// 	if ((*arr)[i] == NULL)
	// 		return (error(s));
	// 	i++;
	// }
	// printf("\n|%d - width, %d - length|\n", s->width, s->length);
	s->map = get_arrays(&arr, argv, -1, s);
	return (1);
}
void free_t_fdf(t_fdf *s)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while(i != s->length)
	{
		j = 0;
		while(j != s->width)
		{
			free(s->map[i][j]);
			j++;
		}
		free(s->map[i]);
		i++;
	}
	// free(s->map[i]);
	free(s->map);
	// free(s);
}

int button_press(int btn, t_fdf *s, t_data *data)
{
	(void)s;
	if (btn == 53)
		exit(1);
	if (btn == 123)
		s->x_shift -=10;
	if (btn == 126)
		s->x_shift +=10;
	if (btn == 125)
		s->y_shift +=10;
	if (btn == 124)
		s->y_shift -=10;
	mlx_clear_window(s->mlx_ptr, s->win_ptr);
	draw(data, s);
	ft_putnbr_fd(btn, 1);
	write(1, "\n", 1);
	return (0);
}

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
	s.img_size_x = 2000;
	s.img_size_y = 2000;
	s.mlx_ptr = mlx_init();
	s.width = get_width(argv, &s);
	s.length = get_length(argv, &s);
	printf("%d - width, %d - length\n", s.width, s.length);
	s.win_ptr = mlx_new_window(s.mlx_ptr, 2000, 2000, "FdF");
	init_map(&s, argv, 0);
	// write(1, "1\n", 2);
	if (s.error)
		return (0);
	data.img = mlx_new_image(s.mlx_ptr, 2000, 2000);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	draw(&data, &s);
	mlx_put_image_to_window(s.mlx_ptr, s.win_ptr, data.img, 0, 0);
	mlx_key_hook(s.win_ptr, button_press, &s);
	mlx_loop(s.mlx_ptr);
	// mlx_key_hook(s.win_ptr, ,NULL);
	// int i;
	// int	j;

	// j = 0;
	// i = 0;
	// while(i != 900)
	// {
	// 	j = 0;
	// 	while(j != 900)
	// 	{
	// 		my_mlx_pixel_put(&data, i, j, 0xffffff);
	// 		j++;
	// 	}
	// 	i++;
	// }
	// write(1, "1\n", 2);
	// write(1, "1\n", 2);
	// int i = 0;
	// int j = 0;
	// write(1, "SUUUUUUUUKA\n", ft_strlen("SUUUUUUUUKA\n"));
	// while(i != s.length)
	// {
	// 	j = 0;
	// 	while(j != s.width)
	// 	{
	// 		printf("%d ", s.map[i][j]->height);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	// i=0;
	// 	while(i != s.length)
	// {
	// 	j = 0;
	// 	while(j != s.width)
	// 	{
	// 		printf("%lu ", s.map[i][j]->calor);
	// 		j++;
	// 	}
	// 	printf("\n");
	// 	i++;
	// }
	// printf("%lu -> sizeof(s)\n", sizeof(t_fdf));
	// printf("%lu -> sizeof(s->map)\n", sizeof(int **));
	// free_t_fdf(&s);
	// while(1);
}