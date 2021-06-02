#include "../includes/fdf.h"

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

float	mod(float a)
{
	if (a > 0)
		return (a);
	return (-a);
}

float	max(float a, float b)
{
	if (mod(a) > mod (b))
		return (mod(a));
	return (mod(b));
}
