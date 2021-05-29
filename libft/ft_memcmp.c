#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*sor1;
	char	*sor2;

	sor1 = (char *)s1;
	sor2 = (char *)s2;
	while ((*sor1 == *sor2) && (--n))
	{
		sor1++;
		sor2++;
	}
	if (!n)
		return (0);
	return ((unsigned char)*sor1 - (unsigned char)*sor2);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_memcmp("asdf", "asdf", 4));
// 	printf("%d\n", ft_memcmp("asdf", "asdf", 1));
// 	printf("%d\n", ft_memcmp("asdfas", "asdf12", 6));
// 	printf("%d\n", ft_memcmp("asdfas", "", 6));
// 	printf("%d\n", ft_memcmp("", "1234", 6));
// 	return 0;
// }
