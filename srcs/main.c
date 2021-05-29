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
	int i;

	i = 0;
	while(str[i])
		i++;
	while(i != -1)
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
	char 	**str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error(s));
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		str = ft_split(line, ' ');
		if (str == NULL)
			return (error(s));
		while(str[i])
			i++;
		if(i > s->width)
			s->width = i;
		free(line);
		ft_free_split(str);
	}
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
	close(fd);
	return (i);
}

int **get_map(t_fdf *s, char **argv, int fd)
{
	char	**str;
	char	*line;
	int		i;
	int		j;

	i = 0;
	fd = open(argv[1], O_RDWR);
	if (fd == -1)
		return (NULL);
	while (get_next_line(fd, &line) == 1 && i != s->length)
	{
		j = 0;
		str = ft_split(line, ' ');
		if (str == NULL)
			return (NULL);
		while(str[j] && j != s->width)
		{
			s->map[i][j] = ft_atoi(str[j]);
			j++;
		}
		free(line);
		ft_free_split(str);
		i++;
	}
	close(fd);
	return (s->map);
}

int init_map(t_fdf *s, char **argv)
{
	int i;

	i = 0;
	s->map = malloc((s->length + 1) * sizeof(int *));
	if(s->map == NULL)
		return (error(s));
	while(i != s->length)
	{
		s->map[i] = ft_calloc(s->width + 1, sizeof(int));
		if(s->map[i] == NULL)
			return (error(s));
		i++;
	}
	printf("\n|%d - width, %d - length|\n", s->width, s->length);
	s->map = get_map(s, argv, -1);
	if (s->map == NULL)
		return (error(s));
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	*s;

	if (argc != 2)
	{
		write(2, "error\n", 6);
		return (0);		
	}
	s = (t_fdf *)ft_calloc(1, sizeof(t_fdf *));
	if (s == NULL)
	{
		write(2, "error\n", 6);
		return (0);
	}
	s->width = get_width(argv, s);
	s->length = get_length(argv, s);
	init_map(s, argv);
	if (s->error)
		return (0);
	int i = 0;
	int j = 0;
	while(i != s->length)
	{
		j = 0;
		while(j != s->width)
		{
			printf("%d ", s->map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}