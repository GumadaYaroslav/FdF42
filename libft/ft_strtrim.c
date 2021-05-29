#include "libft.h"

static int	ft_cmp(char s, char *set)
{
	int	i;

	i = 0;
	while (*set)
	{
		if (*set == s)
			i = 1;
		set++;
	}
	return (i);
}

char	*ft_alloc_and_rec(char *s1, int j, int i)
{
	int		s;
	char	*str;

	s = 0;
	if (j - i == 0)
	{
		str = malloc(1);
		str[0] = 0;
		return (str);
	}
	str = malloc(j + 1);
	if (str == NULL)
		return (str);
	while (s <= j - 1)
	{
		str[s] = s1[s];
		s++;
	}
	str[s] = 0;
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL)
		return ((char *)s1);
	i = 0;
	if (*s1 == (char const) NULL && *set == (char const) NULL)
		return (NULL);
	while (*s1 && ft_cmp(*s1, (char *)set))
		s1++;
	j = ft_strlen(s1);
	while (j > 1 && ft_cmp(s1[j - 1], (char *)set))
	{
		j--;
		i++;
	}
	str = ft_alloc_and_rec((char *)s1, j, i);
	return (str);
}
