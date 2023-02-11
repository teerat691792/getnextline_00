/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:49:56 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/11 16:44:22 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 
#define READFILE "plaintext/alter"

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
	while (i++ < 5 )
	{
		tmp = get_next_line(fd);
//		printf("gnl	return	= %s",tmp);
		printf("%s",tmp);
		printf("|");
	}	

	printf("\nfd = %d\n",fd);
	free(tmp);
	if (close(fd) == -1)
	{
		ft_putstr("close() fails");
		return (1);
	}
	return (0);
}
