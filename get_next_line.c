/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:08:19 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/11 16:44:54 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	check_newline(char *collector, char *newline)
{
	if (ft_split(collector, newline))
		return (1);
	else
		return (0);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			result;
	static int	counter;
	static char	*collector;
	size_t		index;
	size_t		repeat;
	char		*tmp;
	
//	printf("	buffersize	= %d\n",BUFFER_SIZE);
	if (BUFFER_SIZE < 1 || fd == -1)
		return (NULL);
	buffer = malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
//	read by buffer size
	repeat = 0;
	counter = 0;
	result = 0;
	while (counter == 0 || read(fd, buffer, 1))
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
			write(1, "read() fails\n", 13);
			free(buffer);
			return (NULL);
		}
		if (result == 0)
		{
//			write(1, "End of file (EOF)\n", 18);
			break;
		}
		buffer[result] = '\0';
		counter += result;
		collector = ft_strjoin(collector, buffer);

		repeat++;
//		printf("collector at repeat	= %zu :%s",repeat, collector);
//		printf("buffer at repeat	= %zu :%s",repeat, buffer);
	}
//	printf("#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#\n");
//	printf("	counter	=%d\n\n",counter);

//find newline in collector
/*
	if (counter == 0)
	{
//		write(1,"file empty\n",11);
		free(buffer);
		return (NULL);
	}
*/
//	index = ft_find_newline(collector, '\n');
//	if (index > BUFFER_SIZE)
		index = BUFFER_SIZE;
//	printf("newline index	=%zu\n",index);

//copy begining  till '\n' to return
	tmp = malloc(sizeof(char) *(index + 1));
	if (!tmp)
	{
//		write(1,"malloc(tmp) to return fail\n",27);
		return (NULL);
	}
	ft_memmove(tmp, collector, index + 1);

//memmove '\n' till end to static variable
	ft_memmove(collector, (collector + index + 1), ft_strlen(collector) - index);

	free(buffer);
//	printf("collector	remain	=%s",collector);
//	printf("tmp		return	=%s",tmp);
	return (tmp);
}
