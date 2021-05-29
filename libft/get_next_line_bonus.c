#include "libft.h"

static int	ft_check_tail(char **tmp, char **line, char **tail)
{
	*tmp = ft_strchr(*tail, '\n');
	if (*tmp)
	{
		(*tmp)[0] = '\0';
		*line = ft_strdup(*tail);
		(*tmp)++;
		(*tail) = ft_memcpy((*tail), (*tmp), ft_strlen_f(*tmp, 0) + 1);
		if (!(*tail) || !(*line))
			return (-1);
		return (1);
	}
	*line = ft_strdup(*tail);
	if (!(*line))
		return (-1);
	free(*tail);
	*tail = NULL;
	return (2);
}

static int	ft_creater_of_tail(char **tmp, char **tail)
{
	if (*tmp)
	{
		**tmp = '\0';
		if (*tail)
			free(*tail);
		*tail = ft_strdup(++*tmp);
		if (*tail == NULL)
			return (-1);
		return (0);
	}
	return (1);
}

static int	reader(int fd, char **tail, char **line)
{
	char	buf[1 + 4];
	char	*tmp;
	int		i;

	i = 1;
	tmp = NULL;
	while (i && !tmp)
	{
		i = read(fd, buf, 4);
		if (i == -1)
			return (-1);
		if (i == 0)
		{
			return (0);
		}
		buf[i] = '\0';
		tmp = ft_strchr(buf, '\n');
		i = ft_creater_of_tail(&tmp, tail);
		if (i == -1)
			return (-1);
		*line = ft_strjoin_my(*line, buf);
		if (*line == NULL)
			return (-1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*tail[10000];
	char		*tmp;
	int			i;

	tmp = NULL;
	if (fd < 0 || line == NULL || 1 <= 0)
		return (-1);
	if (tail[fd])
	{
		i = ft_check_tail(&tmp, line, &tail[fd]);
		if (i != 2)
			return (i);
	}
	else
	{
		*line = ft_strdup("");
		if (!(*line))
			return (-1);
	}
	if (!tmp)
		return (reader(fd, &tail[fd], line));
	return (1);
}
//
//#include <stdio.h>
//int main()
//{
//	int fd1 = open("/Users/fmilissa/Desktop/MyGNL/baudelaire.txt" , O_RDWR);
//	int fd2 = open("/Users/fmilissa/Desktop/MyGNL/baudelaire_coppy.txt" ,
//				   O_RDWR);
//	int b, c, d, e, f;
//	if (fd1 == -1)
//		return (0);
//	if (fd2 == -1)
//		return (0);
//	char *str;
//	str = NULL;
//	int i = get_next_line(fd1, &str);
//	printf("%s== STR  %d== I\n", str, i);
//	b = get_next_line(fd2, &str);
//	printf("%s== STR  %d== I\n", str, b);
//	c = get_next_line(fd1, &str);
//	printf("%s== STR  %d== I\n", str, c);
//	d = get_next_line(fd2, &str);
//	printf("%s== STR  %d== I\n", str, d);
//	e = get_next_line(fd1, &str);
//	printf("%s== STR  %d== I\n", str, e);
//	f= get_next_line(fd2, &str);
//	printf("%s== STR  %d== I\n", str, f);
//	// printf("%c == STR\n", str[0]);
//	// close(fd);
//	// while (1)
//	// {
//
//	// }
//	return 0;
//}
// #include <stdio.h>
// int main()
// {
// 	 int fd = open("baudelaire_coppy.txt", O_RDWR);
// 	 int i = 0;
// 	 // printf("%d == STR\n", fd);
// 	 // if (fd == -1)
// 	 // 	return (0);
// 	 char *str;
// //	 i = get_next_line(fd, str);
// 	 while ((i = get_next_line(fd, &str)))
// 	 {
// 		 printf("%s ||%d\n", str, i);
// 		 free(str);
// 	 }
// 	 printf("%s ||%d\n", str, i);
// 	 while (1)
// 	 {}
// 	 return 0;
// }
// get_next_line(fd, &str);
// 	printf("%s == STR\n", str);
// get_next_line(fd, &str);
// printf("%s == STR\n", str);
// printf("%c == STR\n", str[0]);
