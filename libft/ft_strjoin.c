#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*new_str;

	j = 0;
	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
	return (new_str);
}
