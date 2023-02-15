/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:49:56 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/15 23:52:57 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 
#define READFILE "plaintext/5_with_nl"

int main(void)
{

//	int		result;
//	char	buffer[BUFF_SIZE + 1];
	char	*tmp;
	size_t  i;

	int		fd;
	fd = open(READFILE, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open () fails\n");
		return (1);
	}
	i = 0;
//	tmp = "start";
		tmp = get_next_line(fd);
//	while (i++ < 1)
		printf("main i = %zu : %s" ,i,tmp);
		tmp = get_next_line(fd);
		printf("main i = %zu : %s" ,i,tmp);
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
