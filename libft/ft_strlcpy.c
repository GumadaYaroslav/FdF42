#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	char	*d;
	char	*s;

	if (dst == NULL)
		return (dstsize);
	if (dstsize == 0)
		return (ft_strlen(src));
	d = dst;
	s = (char *)src;
	i = 0;
	while (i < (int)dstsize - 1)
	{
		if (!s[i])
		{
			d[i] = 0;
			return (ft_strlen(src));
		}
		d[i] = s[i];
		i++;
	}
	d[i] = 0;
	return (ft_strlen(src));
}
// #include <stdio.h>
// int main()
// {
// 	// char dst[] = "";
// 	// char srs[] = "12";

// 	// strlcpy(dst, (const char *)srs, 3);
// 	// printf("%s\n", dst);

// 	// char dst1[] = "qwersd";
// 	// char srs1[] = "12";

// 	// ft_strlcpy(dst1, (const char *)srs1, 1);
// 	// printf("%s\n", dst1);

// 	char s6[15] = "123456789";
// 	ft_strlcpy(&s6[2], s6, 5);
// 	printf("%s my ft\n", s6);

// }
