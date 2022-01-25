#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;
	size_t	i;

	i = 0;
	s = (char *)malloc(size * count);
	if (s == 0)
		return (0);
	while (i < (size * count))
	{
		s[i] = '\0';
		i++;
	}
	return (s);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;

	if (dstsize == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < (dstsize - 1) && i < ft_strlen(src))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (ft_strlen(src));
}

char	*ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	pos[3];
	char	*s;

	pos[0] = 0;
	pos[1] = 0;
	s = malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src) + 1));
	if (s == 0)
		return (0);
	while (pos[0] < (dstsize - 1) && dst[pos[0]])
	{
		s[pos[0]] = dst[pos[0]];
		pos[0]++;
	}
	while (pos[0] < (dstsize - 1) && src[pos[1]])
	{
		s[pos[0]] = src[pos[1]];
		pos[0]++;
		pos[1]++;
	}
	s[pos[0]] = '\0';
	return (s);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;

	if (s == 0)
		return (0);
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	if (len == 1 && start >= ft_strlen(s))
	{
		str = malloc(1);
		str[0] = 0;
		return (str);
	}
	else
		str = malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	if (start < ft_strlen(s))
		ft_strlcpy(str, &s[start], len + 1);
	else
		ft_strlcpy(str, s, 1);
	return (str);
}
