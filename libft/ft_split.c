#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

#include <unistd.h>

static void	ft_free_to_demenshon_arr(char **arr, int tmp)
{
	while (tmp > 0)
	{
		tmp--;
		free(arr[tmp]);
	}
	free(arr);
}

static int	ft_how_meny_words(char const *s, char c)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			len++;
			while (*s != c && *s)
				s++;
		}
		else
			s++;
	}
	return (len);
}

static char	*ft_record_str(char *dst, const char *src, int c, int n)
{
	int		i;

	i = 0;
	while (i < (int)n)
	{
		dst[i] = src[i];
		if (((unsigned char *)src)[i] == (unsigned char)c)
			return ((char *)dst);
		i++;
	}
	return (dst);
}

static char	**ft_record_and_allocate(char **arr, char *s, char c, int j)
{
	int	i;
	int	tmp;

	tmp = 0;
	i = 0;
	while (j != 0)
	{
		while (s[i] == c && s[i])
			i++;
		arr[tmp] = malloc(ft_strlen_l(&s[i], c) + 1);
		if (arr[tmp] == NULL)
		{
			ft_free_to_demenshon_arr(arr, tmp);
			return (NULL);
		}
		arr[tmp] = ft_record_str(arr[tmp], &s[i], c, ft_strlen_l(&s[i], c));
		arr[tmp][ft_strlen_l(&s[i], c)] = 0;
		i = i + (ft_strlen_l(&s[i], c));
		j--;
		tmp++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	char	**arr;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = ft_how_meny_words(s, c);
	arr = malloc(sizeof(char *) * (j + 1));
	if (arr == NULL)
		return (NULL);
	if (j == 0)
	{
		arr[0] = NULL;
		return (arr);
	}
	arr = ft_record_and_allocate(arr, (char *)s, c, j);
	arr[j] = NULL;
	return (arr);
}

// int main()
// {
// 	int i = 0;
// 	char *str = "             ";
// 	char **s = ft_split(str, ' ');
// 	// while(s[i] && s)
// 	// {
// 		printf("%s\n", s[i]);
// 	// 	i++;
// 	// }
// 	// printf("\n%s len of word\n", s[0]);
// 	return (0);
// }
