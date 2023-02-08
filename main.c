/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:49:56 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/08 20:54:35 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
 
//#define BUFF_SIZE 20
#define READFILE "abcd"

int main(void)
{

//	int		result;
//	char	buffer[BUFF_SIZE + 1];
	char	*tmp;

	int		fd;
	fd = open(READFILE, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open () fails\n");
		return (1);
	}
	tmp = get_next_line(fd);	
	ft_putstr(tmp);
//	get_next_line(fd);	

	write (1,"\n",1);
	write (1,"\n",1);
	ft_putstr("fd = ");
	ft_putnbr(fd);
	write(1,"\n",1);
	if (close(fd) == -1)
	{
		ft_putstr("close() fails");
		return (1);
	}
	return (0);
}
