#include "libft.h"
#include "fdf.h"

int	error(t_fdf *s)
{
	s->error = 1;
	write(1, "error\n", 6);
	return (0);
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
		while (str[i])
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

void	help_get_arrays(t_dot ***s, char **str, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (str[j])
	{
		s[i][j]->height = ft_atoi(str[j]);
		tmp = ft_strchr(str[j], ',');
		if (tmp)
			s[i][j]->calor = ft_atoi_base(tmp + 3, "0123456789ABCDEF", 16);
		j++;
	}
}

t_dot ***get_arrays(t_dot ****s, char **argv, int fd)
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
		help_get_arrays(*s, str, i);
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
	arr = (t_dot ***)ft_calloc(s->length, sizeof(t_dot **));
	while (i < s->length)
	{
		arr[i] = (t_dot **)ft_calloc(s->width, sizeof(t_dot *));
		j = 0;
		while (j < s->width)
		{
			arr[i][j] = (t_dot *)ft_calloc(1, sizeof(t_dot));
			j++;
		}
		i++;
	}
	i = 0;
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
	printf("\n|%d - width, %d - length|\n", s->width, s->length);
	s->map = get_arrays(&arr, argv, -1);
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
int	main(int argc, char **argv)
{
	t_fdf	s;

	if (argc != 2)
	{
		write(2, "error\n", 6);
		return (0);		
	}
	s.width = get_width(argv, &s);
	s.length = get_length(argv, &s);
	init_map(&s, argv, 0);
	if (s.error)
		return (0);
	int i = 0;
	int j = 0;
	write(1, "SUUUUUUUUKA\n", ft_strlen("SUUUUUUUUKA\n"));
	while(i != s.length)
	{
		j = 0;
		while(j != s.width)
		{
			printf("%d ", s.map[i][j]->height);
			j++;
		}
		printf("\n");
		i++;
	}
	i=0;
		while(i != s.length)
	{
		j = 0;
		while(j != s.width)
		{
			printf("%lu ", s.map[i][j]->calor);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("%lu -> sizeof(s)\n", sizeof(t_fdf));
	printf("%lu -> sizeof(s->map)\n", sizeof(int **));
	free_t_fdf(&s);
	while(1);
}