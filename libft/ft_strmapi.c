#include <stdlib.h>
#include "libft.h"
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	str = malloc(ft_strlen(s) + 1);
	if (str == NULL)
		return (NULL);
	i = ft_strlen(s);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = f(i, s[i]);
		i--;
	}
	return (str);
}
