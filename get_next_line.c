/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:50:10 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/01/27 08:50:13 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_final_line(char **rest, int pos)
{
	char	*line;
	char	*aux;

	aux = *rest;
	line = ft_substr(aux, 0, pos + 1);
	*rest = ft_substr(aux, pos + 1, ft_strlen(aux) + 1 - pos);
	free(aux);
	return (line);
}

int	ft_file(char **rest, int pos, int *final)
{
	if (pos == 0)
	{
		if (*final == 0 && *rest)
		{
			*final = 1;
			if (**rest)
				return (1);
			free(*rest);
			return (0);
		}
		else
			return (0);
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	static int	final;
	char		*aux;
	int			pos[2];
	int			op;

	if (fd < 0 || read(fd, &final, 0) == -1 || BUFFER_SIZE <= 0)
		return (0);
	pos[0] = ft_getpos(rest, 10);
	if (pos[0] == -1)
	{
		pos[1] = ft_read_more(fd, &rest);
		op = ft_file(&rest, pos[1], &final);
		if (op == 1)
			return (rest);
		if (op == 0)
			return (0);
	}
	aux = rest;
	pos[0] = ft_getpos(aux, 10);
	if (pos[0] != -1)
	{
		aux = ft_final_line(&rest, pos[0]);
	}
	return (aux);
}
