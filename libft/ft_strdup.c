#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	int		i;

	i = 0;
	dst = malloc(ft_strlen(s1) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
// #include <stdio.h>
// int main()
// {
// 	const char s[] = "qwerty";
// 	char *g = strdup(s);
// 	printf("%s\n", g);
// 	return 0;
// }
