#include "libft.h"
#include <stdio.h>

static char	*ft_str_record(char *str, int n, int flag, int k)
{
	int	i;

	i = 0;
	while (k != 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		k--;
		i++;
	}
	if (flag)
		str[i++] = '-';
	str[i] = 0;
	return (str);
}

static char	*ft_alloc(char *str, int n, int flag, int k)
{
	int	i;

	i = n;
	if (n < 0)
	{
		k++;
		flag = 1;
		n = n * (-1);
	}
	while (i != 0)
	{
		i = i / 10;
		k++;
	}
	str = malloc(k + 1);
	if (flag == 1)
		k--;
	if (str == NULL)
		return (str);
	str = ft_str_record(str, n, flag, k);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		k;
	int		flag;

	i = n;
	str = NULL;
	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (i == 0)
	{
		str = ft_strdup ("0");
		return (str);
	}
	k = 0;
	flag = 0;
	str = ft_alloc(str, n, flag, k);
	if (str == NULL)
		return (NULL);
	ft_str_rev(str);
	return (str);
}
