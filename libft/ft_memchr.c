#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*srs;

	srs = (char *)s;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*srs == c)
			return (srs);
		srs++;
	}
	return (NULL);
}

// int main()
// {
// 	char s[] = "asdfgh";
// 	printf("%s\n", memchr(s, 'f', 50));
// 	return 0;
// }
