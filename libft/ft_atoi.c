#include <stdlib.h>
#include <stdio.h>

static long long	ft_return_num(char *str, int flag)
{
	int			i;
	long long	num;

	num = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	if (flag == 1)
		return (num * (-1));
	return (num);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	while (str[i] == '\f' || str[i] == '\n' || str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == ' ')
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag = 1;
		i++;
	}
	while (str[i] == '0')
		i++;
	if (str[i] >= '0' && str[i] <= '9')
		return ((int)ft_return_num((char *)&str[i], flag));
	return (0);
}
