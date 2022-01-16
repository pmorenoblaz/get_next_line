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

char	*get_next_line(int fd)
{
	char		*str;
	char		*fin;
	char		*str2;
	char		*str3;
	static char	*rest;
	int			len[3];
	int			j;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	j = 0;
	len[0] = ft_strlen(rest);
	if (rest != 0 && len[0] != 0)
	{
		str = ft_substr(rest, 0, len[0] + 1);
		free(rest);
	}
	else
	{
		free(rest);
		str = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
		read(fd, str, BUFFER_SIZE);
	}
	len[0] = ft_strlen(str);
	if (len[0] == 0)
	{
		free(str);
		return (0);
	}
	len[2] = 0;
	fin = ft_calloc(sizeof(char), 1);
	len[1] = ft_strlen(str);
	while (str[len[2]] != '\n')
	{
		if (len[2] == len[1] - 1)
		{
			str2 = fin;
			fin = ft_strlcat(str2, str, ft_strlen(str2) + ft_strlen(str) + 1);
			free(str2);
			free(str);
			str = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
			read(fd, str, BUFFER_SIZE);
			len[1] = ft_strlen(str);
			if (len[1] == 0)
				break ;
			len[2] = -1;
		}
		len[2]++;
		j++;
	}
	len[0] = ft_strlen(fin);
	str3 = ft_substr(str, 0, len[2] + 1);
	j = ft_strlen(str3) + 1;
	str2 = fin;
	fin = ft_strlcat(str2, str3, len[0] + j);
	free(str2);
	free(str3);
	if (BUFFER_SIZE > 1)
		rest = ft_substr(str, (len[2] + 1), ft_strlen(str) - len[2] + 1);
	free(str);
	return (fin);
}

// void leaksss()
// {
// 	system ("leaks a.out");
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*print;

// atexit(leaksss);
// 	fd = open("big_line_with_nl", O_RDONLY);
// 	  if (fd == -1)
// 		return (write(1, "NULL\n", 5));
// 	 print = get_next_line(fd);
// 	  printf("%s\n", print);
// 	  free(print);

// 	 printf("--------\n");
// 	 print = get_next_line(fd);
// 	 printf("%s\n", print);
// 	  free(print);

// 	 printf("--------\n");
// 	 print = get_next_line(fd);
// 	  printf("%s\n", print);
// 	   free(print);

// 	 printf("--------\n");
// 	  print = get_next_line(fd);
// 	 printf("%s\n", print);
// 	  free(print);
	  
// 	close(fd);
// }
