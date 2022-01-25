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
	s = (char *)malloc((size * count) + 1);
	if (s == 0)
		return (0);
	while (i < (size * count) + 1)
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

// char	*ft_strlcat(char *dst, char *src, size_t dstsize)
// {
// 	size_t	pos[2];
// 	char	*s;

// 	pos[0] = 0;
// 	pos[1] = 0;
// 	if (!dst)
// 		return (src);
// 	s = malloc(sizeof(char) * (ft_strlen(dst) + ft_strlen(src) + 1));
// 	if (s == 0)
// 		return (0);
// 	while (dst[pos[0]] && pos[0] < (dstsize - 1))
// 	{
// 		s[pos[0]] = dst[pos[0]];
// 		pos[0]++;
// 	}
// 	// printf("\n------> dst(rest) antes de concatenar = %s", dst);
// 	// printf("\n------> src (aux) antes de concatenar = %s", src);
// 	// printf("\n------> s antes de concatenar = %s", s);
// 	while (pos[0] < (dstsize - 1) && src[pos[1]])
// 	{
// 		s[pos[0]] = src[pos[1]];
// 		pos[0]++;
// 		pos[1]++;
// 	}
// 	// printf("\n------> dst (rest) al concatenar = %s", dst);
// 	// printf("\n------> src (aux) al concatenar = %s", src);
// 	// printf("\nlo que concateno en la función s = %s", s);
// 	s[pos[0]] = '\0';
// 	return (s);
// }

char	*ft_strlcat(char *dst, char *src)
{
	char	*str;
	size_t	i;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(dst);
	s2len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < (s1len + s2len + 1))
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
	i = -1;
	while (++i < s1len)
		str[i] = dst[i];
	i = -1;
	while (++i < s2len)
		str[i + s1len] = src[i];
	return (str);
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

