/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainGnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: potero-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:53:01 by potero-d          #+#    #+#             */
/*   Updated: 2021/10/26 12:20:43 by potero-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"get_next_line.h"
#include<stdio.h>
/*
int	main(void)
{
	int		fd;
//	char	*print;
	
	fd = open("123.txt", O_RDONLY);
	if (fd == -1)
		return (write(1, "NULL\n", 5));

	get_next_line(0);	
	get_next_line(0);	
	get_next_line(0);	
	get_next_line(0);	
//	system("leaks a.out");
//	printf("%s\n", print);
//	printf("--------\n");
//	print = get_next_line(fd);
//	printf("%s\n", print);
//	printf("--------\n");
//	print = get_next_line(fd);
//	printf("%s\n", print);
//	printf("--------\n");
//	print = get_next_line(fd);
//	printf("%s\n", print);
//	close(fd);
}
*/
int				main()
{
	int			fd;
	char		*str;
	int			i;

	i = 0;
	fd = open("nl", O_RDONLY);
// 	get_next_line(fd, &str);
//	printf("%s", str); 
	while ((str = get_next_line(fd)))
	{
        printf("line %i=>%s", i + 1, str);
		free(str);
		i++;
		if (i == 5)
			sleep(30);
	}
//	system("leaks a.out");
	return (0);
}

