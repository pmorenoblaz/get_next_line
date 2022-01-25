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

int	ft_read_more(int fd, char **rest)
{
	char	*buffer;
	char	*aux2;
	int		len;
	int		pos;

	buffer = 0;
	pos = ft_getpos(buffer, 10);
	aux2 = 0;
	while (pos == -1)
	{
		//printf("olo");
		buffer = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		if (!buffer)
			return (0);
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == 0)
		{
			free(buffer);
			if (aux2)
				return (1);
			else
				return (0);
		}
		
			aux2 = ft_strlcat(*rest, buffer, ft_strlen(*rest) + len + 1);
			// aux2 = ft_strlcat(*rest, buffer);
			printf("aux2 %s\n", aux2);
			pos = ft_getpos(aux2, 10);
			//if (ft_strlen(aux2) < BUFFER_SIZE && pos == -1)
			//if (buffer && ft_strlen(buffer) > 0)
				//free(buffer);
			if (*rest)
				free(*rest);
			*rest = ft_substr(aux2, 0, ft_strlen(aux2));
			free(aux2);
			aux2 = 0;
			if (ft_strlen(aux2) < BUFFER_SIZE)
				break ;
			buffer = 0;
	}
	printf("aux2: %s, rest: %s\n", aux2, *rest);
	return (1);
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
		//printf("eo\n");
		if (ft_read_more(fd, &rest) == 0)
			return (0);
	}
	 printf("\nrest después de leer = %s", rest);
	// printf("\naux después de leer = %s", aux);
	pos = ft_getpos(aux, 10);
	if (pos != -1)
	{
		 //printf("\naux = %s", aux);
		aux3 = ft_substr(aux, 0, pos + 1);
		printf("->rest %s\n", rest);
		//if (ft_strlen(rest) > 0)
			//free(rest);
		rest = 0;
		rest = ft_substr(aux, pos + 1, BUFFER_SIZE + 1 - pos);
		free(aux);
		aux = aux3;
		// printf("rest = %s", rest);
		// printf("\nfinal = %s", aux);
	}
	// printf("rest = %p", rest);
	// printf("\naux = %p ", aux);
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