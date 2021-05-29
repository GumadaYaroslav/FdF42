#include <string.h>
#include "libft.h"

void	*ft_memmove(void *distan, const void *source, size_t n)
{
	char	*dis;
	char	*srs;
	int		i;

	i = 0;
	if (n == 0)
		return (distan);
	if (distan <= source)
	{
		ft_memcpy(distan, source, n);
		return (distan);
	}
	dis = (char *)distan + n - 1;
	srs = (char *)source + n - 1;
	while (n)
	{
		dis[i] = srs[i];
		i--;
		n--;
	}
	return (distan);
}
// #include <stdio.h>
// int main()
// {
// 	char s1[15] = "123456789";
// 	printf("%s my ft\n", ft_memmove(s1, "qwer", 30));	

// 	char s2[15] = "123456789";
// 	printf("%s my ft\n", memmove(s2, "qwer", 14));
// 	printf("%c AAAAAA\n", s2[6]);
// 	printf("----------------\n");
// 	char s3[15] = "";
// 	printf("%s my ft\n", ft_memmove(s3, "qwer", 30));	

// 	char s4[15] = "";
// 	printf("%s my ft\n", memmove(s4, "qwer", 3));
// 	printf("----------------\n");
	// char s5[15] = "123456789";
	// printf("%s my ft\n", ft_memmove(s1, "qwer", 30));	

	// char s6[15] = "123456789";
	// printf("%s my ft\n", memmove(s2, "qwer", 14));		
	// char s7[15] = "123456789";
	// printf("%s my ft\n", ft_memmove(s1, "qwer", 30));	

	// char s2[15] = "123456789";
	// printf("%s my ft\n", memmove(s2, "qwer", 14));		
	// char s1[15] = "123456789";
	// printf("%s my ft\n", ft_memmove(s1, "qwer", 30));	

	// char s2[15] = "123456789";
	// printf("%s my ft\n", memmove(s2, "qwer", 14));		
	// char s1[15] = "123456789";
	// printf("%s my ft\n", ft_memmove(s1, "qwer", 30));	

	// char s2[15] = "123456789";
	// printf("%s my ft\n", memmove(s2, "qwer", 14));	
	// char s1[15] = "123456789";
	// printf("%s my ft\n", ft_memmove(s1, "qwer", 30));	

	// char s2[15] = "123456789";
	// printf("%s my ft\n", memmove(s2, "qwer", 14));	
// }
