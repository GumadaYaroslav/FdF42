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

int **get_map(int **s, char **argv, int fd)
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
			return (NULL);
		// write(1, "1\n", 2);
		while(str[j])
		{
			// write(1, "1\n", 2);
			s[i][j] = ft_atoi(str[j]);
			// write(1, "1\n", 2);
			j++;
		}
		free(line);
		ft_free_split(str);
		i++;
	}
	// free(line);
	// ft_free_split(str);
	close(fd);
	return (s);
}

int init_map(t_fdf **s, char **argv)
{
	int i;
	int **arr;
	i = 0;
	arr = (int **)ft_calloc((*s)->length, sizeof(int *));
	printf("%lu -> sizeof(arr)\n", (*s)->length * sizeof(int *));
	if((*s)->map == NULL)
		return (error(*s));
	while(i != (*s)->length + 1)
	{
		arr[i] = ft_calloc((*s)->width, sizeof(int));
		if(arr[i] == NULL)
			return (error(*s));
		i++;
	}
	printf("\n|%d - width, %d - length|\n", (*s)->width, (*s)->length);
	(*s)->map = get_map(arr, argv, -1);
	if ((*s)->map == NULL)
		return (error(*s));
	return (1);
}
void free_t_fdf(t_fdf *s)
{
	int i;

	i = 0;
	while(i != s->length)
	{
		free(s->map[i]);
		i++;
	}
	free(s->map[i]);
	free(s->map);
	free(s);
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
	init_map(&s, argv);
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
	printf("%lu -> sizeof(s)\n", sizeof(t_fdf));
	printf("%lu -> sizeof(s->map)\n", sizeof(int **));
	free_t_fdf(s);
	while(1);
}