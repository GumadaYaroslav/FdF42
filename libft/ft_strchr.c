char	*ft_strchr(const char *s, int c)
{
	char	*src;

	src = (char *)s;
	while (*src != c && *src)
		src++;
	if (*src == c)
		return ((char *)src);
	return (0);
}
