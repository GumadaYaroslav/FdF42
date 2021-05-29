#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*d;
	char	*s;
	int		i;

	if (dst == NULL && src == NULL)
		return (dst);
	if (n == 0)
		return (dst);
	i = 0;
	d = (char *)dst;
	s = (char *)src;
	while (n > 0)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dst);
}
