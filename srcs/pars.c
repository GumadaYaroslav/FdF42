#include "../includes/libft.h"
#include "../includes/fdf.h"

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

static void	help_get_arrays(t_dot ***s, char **str, int i, t_fdf *fdf)
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

static t_dot	***get_arrays(t_dot ****s, char **argv, int fd, t_fdf *fdf)
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
