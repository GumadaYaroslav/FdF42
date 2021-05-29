#include <strings.h>

void	*ft_bzero(void *s, size_t len)
{
	int		i;
	char	*buf;

	buf = (char *)s;
	i = 0;
	while (i < (int)len)
	{
		buf[i] = 0;
		i++;
	}
	return (s);
}
