#include "libft.h"

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

int	is_base(char c, char *base)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(base))
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

long long	ft_atoi_base(char *str, char *base, int len_base)
{
	long long	nb;
	int			i;
	int			minus;

	i = 0;
	minus = 0;
	nb = 0;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = 1;
		i++;
	}
	while (is_base(str[i], base) != -1)
	{
		nb = nb * len_base;
		nb = nb + is_base(str[i], base);
		i++;
	}
	nb = nb * (1 - 2 * (minus));
	return (nb);
}
