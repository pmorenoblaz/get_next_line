/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmoreno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 08:46:06 by pmoreno-          #+#    #+#             */
/*   Updated: 2022/01/27 08:46:12 by pmoreno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_strlcat(char *dst, char *src)
{
	char	*str;
	size_t	i;
	size_t	dstl;
	size_t	srcl;

	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (dstl + srcl + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < (dstl + srcl + 1))
	{
		((unsigned char *)str)[i] = '\0';
		i++;
	}
	i = -1;
	while (++i < dstl)
		str[i] = dst[i];
	i = -1;
	while (++i < srcl)
		str[i + dstl] = src[i];
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
