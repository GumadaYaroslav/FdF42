#include <string.h>
#include "libft.h"
#include <stdio.h>

// static int ft_strnlen(char *src, int max)
// {
// 	int i;

// 	i = 0;
// 	while(*src && max > 0)
// 	{
// 		src++;
// 		max--;
// 		i++;
// 	}
// 	return (i);
// }
size_t	ft_strlcat(char *dst, const char *src, size_t maxlen)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dlen;

	d = dst;
	s = src;
	n = maxlen;
	while (n-- != 0 && *d != '\0')
		d++;
	dlen = d - dst;
	n = maxlen - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}

// int main()
// {
// // 	// char *s[10] = {"qwer", "q",
// // 	//  "123456789", "abc",
// // 	// "", "123",
// // 	// "123", "",
// // 	// "", ""}
// 	char s1[10] = "1234";
// 	char d1[] = "5";
// 	ft_strlcat(s1, d1, 30);
// 	printf("%s  qwer + q\n", s1);
// 	char s2[10] = "1234";
// 	char d2[] = "5";
// 	strlcat(s2, d2, 30);
// 	printf("%s  qwer + q\n", s2);
// 	printf("--------------");

// 	char s3[10] = "1234";
// 	char d3[] = "5";
// 	ft_strlcat(s1, d1, 30);
// 	printf("%s  qwer + q\n", s3);
// 	char s4[10] = "1234";
// 	char d4[] = "5";
// 	strlcat(s2, d2, 30);
// 	printf("%s  qwer + q\n", s4);
// 	printf("--------------");

// 	char s5[10] = "1234";
// 	char d5[] = "5";
// 	ft_strlcat(s1, d1, 30);
// 	printf("%s  qwer + q\n", s5);
// 	char s6[10] = "1234";
// 	char d6[] = "5";
// 	strlcat(s2, d2, 30);
// 	printf("%s  qwer + q\n", s6);
// 	printf("--------------");

// 	char s7[10] = "1234";
// 	char d7[] = "5";
// 	ft_strlcat(s1, d1, 30);
// 	printf("%s  qwer + q\n", s7);
// 	char s8[10] = "1234";
// 	char d8[] = "5";
// 	strlcat(s2, d2, 30);
// 	printf("%s  qwer + q\n", s8);
// 	printf("--------------");

// 	char s2[20] = "123456789";
// 	char d2[] = "abc"; 

// 	char s3[10] = "";
// 	char d3[] = "q"; 
// 	char s4[4] = "123";
// 	char d4[] = ""; 
// 	char s5[6] = "qwer";
// 	char d5[] = "q"; 

// 	ft_strlcat(s1, d1, 30);
// 	printf("%s  qwer + q\n", s1);

// 	ft_strlcat(s2, d2, 16);
// 	printf("%s  123456789 + abc\n", s2);

// 	ft_strlcat(s3, d3, 2);
// 	printf("%s q + probel\n", s3);

// 	ft_strlcat(s4, d4, 4);
// 	printf("%s q + probel\n", s4);
// 	strlcat(s5, d5, (size_t)6);
// 	printf("%s q + probel\n", s5);
// 	strlcat(s1, d1, (size_t)5);

// 	strlcat(s1, d1, (size_t)4);

// 	return (0);
// }
