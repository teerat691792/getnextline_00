/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:49:56 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/20 20:55:41 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 
#define READFILE3 "plaintext/test3"
#define READFILE4 "plaintext/test4"
#define READFILE5 "plaintext/test5"
#define READFILE6 "plaintext/test6"

int main(void)
{
	int		i;
	char	*tmp;
	int		fd[FOPEN_MAX];
	int		files;

	fd[3] = open(READFILE3, O_RDONLY);
	fd[4] = open(READFILE4, O_RDONLY);
	fd[5] = open(READFILE5, O_RDONLY);
	fd[6] = open(READFILE6, O_RDONLY);
/*
	if (fd == -1)
	{
		printf("open () fails\n");
		return (1);
	}
*/
	files = 3;
	i = 0;
	tmp = "start";

	while (i < 144)
	{
		tmp = get_next_line(fd[files]);
		printf("main i = %d : %s" ,i,tmp);
		free(tmp);
		i++;
		files++;
		if (files >= 7)
			files = 3;
	}

//	printf("\nfd = %d\n",fd);
	fd[3] = close(fd[3]);
	fd[4] = close(fd[4]);
	fd[5] = close(fd[5]);
	fd[6] = close(fd[6]);
/*
	if (fd == -1)
	{
		printf("close() fails");
		return (1);
	}
*/
//	printf("\nfd = %d\n",fd);
	return (0);
}
