#include "libft.h"

int	ft_strlen_f(const char *str, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (str[i])
			i++;
	}
	else if (flag == 1)
	{
		while (str[i] && str[i] != '\n')
			i++;
	}
	else
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
		return (0);
	}
	return (i);
}

char	*ft_strjoin_my(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_str;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = malloc(ft_strlen_f(s1, 0) + ft_strlen_f(s2, 0) + 1);
	if (new_str == NULL)
		return (NULL);
	while (s1[i])
	{
		new_str[i] = (char)s1[i];
		i++;
	}
	while (s2[j])
	{
		new_str[i] = (char)s2[j];
		j++;
		i++;
	}
	new_str[i] = '\0';
	free ((void *)s1);
	return (new_str);
}
