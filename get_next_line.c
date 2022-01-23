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
# define BUFFER_SIZE 5
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

char	*ft_read_more(int fd, char **rest)
{
	char	*aux;
	char	*aux2;
	int		len;

	aux = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!aux)
		return (0);
	len = read(fd, aux, BUFFER_SIZE);
	// printf("\nqué hay en aux al leer = %s", aux);
	if (len == 0)
	{
		free(aux);
		return (0);
	}
	while (ft_getpos(aux, 10) == -1)
	{
		aux2 = *rest;
		free(*rest);
		*rest = ft_strlcat(aux2, aux, ft_strlen(aux2) + len + 1);
		free(aux2);
		free(aux);
		aux = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		len = read(fd, aux, BUFFER_SIZE);
		if (len == 0)
			return (aux);
	}
	aux2 = aux;
	// printf("\nrest en la función = %s", *rest);
	// printf("\naux en la función = %s", aux);
	aux = ft_strlcat(*rest, aux2, ft_strlen(*rest) + ft_strlen(aux2) + 1);
	// printf("\naux al concatenar = %s", aux);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*aux;
	char		*aux3;
	int			pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	aux = rest;
	// printf("\nrest al principio = %s", rest);
	pos = ft_getpos(rest, 10);
	if (pos == -1)
	{
		aux = ft_read_more(fd, &rest);
		if (aux == 0)
			return (0);
	}
	// printf("\nrest después de leer = %s", rest);
	// printf("\naux después de leer = %s", aux);
	pos = ft_getpos(aux, 10);
	if (pos != -1)
	{
		// printf("\naux = %s", aux);
		aux3 = ft_substr(aux, 0, pos + 1);
		rest = ft_substr(aux, pos + 1, BUFFER_SIZE + 1 - pos);
		free(aux);
		aux = aux3;
		// printf("rest = %s", rest);
		// printf("\nfinal = %s", aux);
	}
	printf("rest = %p", rest);
	printf("\naux = %p ", aux);
	// printf("\nrest final = %s", rest);
	// printf("\n----------------------\n");
	if (!aux && !rest)
		return (0);
	return (aux);
}
/*

char	*get_next_line(int fd)
{
	char	*buffer = malloc(BUFFER_SIZE + 1);
	char	*line;
	char	*rest;
	int		salto;

(void)line;
(void)rest;
	buffer[BUFFER_SIZE] = 0;
	read(fd, buffer, BUFFER_SIZE);
	salto = ft_getpos(buffer, '\n') + 1;
	printf("%i\n", salto);
	line = ft_substr(buffer, 0, salto);
	printf("%s",line);
	rest = ft_substr(buffer, salto, BUFFER_SIZE + 1 -salto);
	printf("%s\n",rest);
	return (0);
}
*/