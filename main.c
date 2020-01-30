/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:00:15 by vgrankul          #+#    #+#             */
/*   Updated: 2019/12/09 10:14:55 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>

int	main(int argc, char** argv)
{
		argc = 0;
	//	argv = 0;
	int fd;
//	int fd2;
	int t;
	//int b;
	//int i;
	char *line;
	//char *line2;
		//int* fd;

		//i = 1;
	//if (argc == 1)
		//return (0);
	//fd = open(0, O_RDONLY);
	fd = open(argv[1], O_RDONLY);
	//fd2 = open(argv[2], O_RDONLY);
	t = 1;
	//printf("%s", argv[1]);
	
	while (t > 0)
	{
		 t = get_next_line(fd, &line);

		//printf("it worked");
	//	printf("%d", t);
//	printf("%s | %d \n", line, t);
		if (line != NULL)
		{
	ft_putstr(line);
		ft_putstr("\n");
		}
		ft_strdel(&line);
		//printf("%d\n", t);
		//	printf("segfault");
		//	t--;
	}
/*	while (1)
	{

	}
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_strdel(&line);
		get_next_line(fd2, &line2);
		ft_putstr(line2);
		ft_strdel(&line2);
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_strdel(&line);
		get_next_line(fd2, &line2);
		ft_putstr(line2);
		ft_strdel(&line); */
	return (0);
}
