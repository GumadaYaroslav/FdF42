#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	int		i;

	if (s == NULL)
		return (NULL);
	i = (int)ft_strlen(s);
	if (i < (int)start)
	{
		sub_str = malloc(1);
		sub_str[0] = 0;
		return (sub_str);
	}
	i = 0;
	sub_str = malloc(sizeof(char) * (len + 1));
	if (sub_str == NULL)
		return (NULL);
	while (s[start] && i < (int)len)
	{
		sub_str[i] = s[(int)start];
		i++;
		start++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}
