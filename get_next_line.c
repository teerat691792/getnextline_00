/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:08:19 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/08 20:57:15 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
//	char		*tmp;
	int			result;
	static int	counter;
	static char	*collector;
	//char		*ptr;
	

	//ptr = collector;
	buffer = malloc(sizeof 1 + 1);
	if (!buffer)
		return (NULL);
	while ((result = read(fd, buffer, 1)) && *buffer != '\n')
	{
		if (result == -1)
			write(1, "read() fails\n", 13);
		buffer[result] = '\0';
//		write(1, "\n", 1);
//		ft_putstr("result = ");
//		ft_putnbr(result);
		counter += result;
		
//		write(1, "\n", 1);
//		ft_putstr("buffer = ");
		ft_putstr(buffer);
		collector = ft_strjoin(collector, buffer);
//		write(1, "\n", 1);
	}
	
	ft_putstr("\n\n************\n");
	ft_putstr("counter = ");
	ft_putnbr(counter);
	write(1, "\n", 1);
/*
//end file read
	tmp = malloc(sizeof (char ) * result + 1);
	if (!tmp)
		return (NULL);
	result = read(fd, tmp, counter);
*/
	//ft_putstr("ptr = ");
	//ft_putstr(ptr);
	//write(1, "\n", 1);
	printf("----%s----\n",collector);
	return (collector);
}
