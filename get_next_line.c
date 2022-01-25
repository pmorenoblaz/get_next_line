

#include "get_next_line.h"

int	ft_getpos(const char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i] != 0)
	{
		if (s[i] == (unsigned char)c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

int	ft_read_more(int fd, char **rest)
{
	char	*buffer;
	char	*aux;
	int		len;
	int		pos;

	pos = ft_getpos(*rest, 10);
	while (pos == -1)
	{
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == 0)
		{
			free(buffer);
			return (0);
		}
		pos = ft_getpos(buffer, 10);
		aux = ft_strlcat(*rest, buffer);
		free(buffer);
		if (*rest)
			free(*rest);
		*rest = aux;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	static int	final;
	char		*aux;
	char		*aux3;
	int			pos;
	int			len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	pos = ft_getpos(rest, 10);
	if (pos == -1)
	{
		len = ft_read_more(fd, &rest);
		if (len == 0 && final == 0 && rest)
		{
			final = 1;
			if (*rest)
			{
				return (rest);
			}
			free(rest);
			return (0);
		}
		else if (len == 0)
			return (0);
	}
	aux = rest;
	pos = ft_getpos(aux, 10);
	if (pos != -1)
	{
		aux3 = ft_substr(aux, 0, pos + 1);
		rest = ft_substr(aux, pos + 1, ft_strlen(aux) + 1 - pos);
		free(aux);
		aux = aux3;
	}
	return (aux);
}
