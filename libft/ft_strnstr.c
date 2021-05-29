#include "libft.h"

char	*ft_strnstr(const char *stack, const char *need, size_t len)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (stack[i] && (k < (int)len))
	{
		while ((stack[i + k] == need[k]) && need[k] && ((i + k) < (int)len))
			k++;
		if (need[k] == 0)
			return ((char *)&stack[i]);
		k = 0;
		i++;
	}
	if (need[0] == 0)
		return ((char *)&stack[i]);
	return (NULL);
}
