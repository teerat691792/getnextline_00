/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:49:56 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/16 18:06:21 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 
#define READFILE "plaintext/test"

int main(void)
{

//	int		result;
//	char	buffer[BUFF_SIZE + 1];
	int		i;
	char	*tmp;

	int		fd;
	fd = open(READFILE, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open () fails\n");
		return (1);
	}
	i = 0;

	tmp = get_next_line(fd);
	printf("main i = %d : %s" ,i,tmp);
	i++;
	free(tmp);

	tmp = get_next_line(fd);
	printf("main i = %d : %s" ,i,tmp);
	i++;
	free(tmp);

	tmp = get_next_line(fd);
	printf("main i = %d : %s" ,i,tmp);
	i++;
//	tmp = NULL;
	free(tmp);
//	tmp = "start";
//	while (i++ < 1)
/*
	while (tmp)
	{
//		printf("->");
		free(tmp);
		tmp = get_next_line(fd);
//		printf("****gnl	return	= %s***",tmp);
		i++;

	}	
*/
//	printf("\nfd = %d\n",fd);
	if (close(fd) == -1)
	{
		ft_putstr("close() fails");
		return (1);
	}
	return (0);
}
