/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   get_next_line.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pmoreno- <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/10/07 10:03:30 by pmoreno-		  #+#	#+#			 */
/*   Updated: 2021/10/07 10:04:44 by pmoreno-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "get_next_line.h"

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

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
		// printf("el buffer es: %s", buffer);
		if (len == 0)
		{
			free(buffer);
			return (0);
		}
		pos = ft_getpos(buffer, 10);
		aux = ft_strlcat(*rest, buffer);
		free(buffer);
		if(*rest)
			free(*rest);
		*rest = aux;
	}

	//printf("%p rest funcion\n", rest);
	//printf("%p buffer\n", buffer);
	//printf("%p aux en funcion\n", aux);
	// printf("el rest es: %s", *rest);
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*aux;
	char		*aux3;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	pos = ft_getpos(rest, 10);
	if (pos == -1)
	{
		ft_read_more(fd, &rest);
	}
	aux = rest;
	pos = ft_getpos(aux, 10);
	if (pos != -1)
	{
		aux3 = ft_substr(aux, 0, pos + 1);
		rest = ft_substr(aux, pos + 1, ft_strlen(aux) + 1 - pos);
		// printf("%p aux3\n", aux3);
		// printf("%p rest\n", rest);
		// printf("%p aux\n", aux);
		free(aux);
		aux = aux3;
	}
	// printf("\n..................\n");
	// printf("%p rest final\n", rest);
	if (!aux && !rest)
	{
		free(rest);
		return (0);
	}
	// printf("el rest final es: %s", rest);
	return (aux);
}
