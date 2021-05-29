char	*ft_strrchr(const char *s, int c)
{
	char	*src;
	int		i;

	i = 0;
	src = 0;
	if ((char)c == '\0')
	{
		while (*s)
			s++;
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == c)
			src = (char *)s;
		s++;
	}
	return (src);
}
