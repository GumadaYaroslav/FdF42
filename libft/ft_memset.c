#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*buf;

	buf = (char *)b;
	i = 0;
	while (len > 0)
	{
		buf[i] = c;
		i++;
		len--;
	}
	return (b);
}
