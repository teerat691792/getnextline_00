/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:08:19 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/10 17:16:28 by tkulket          ###   ########.fr       */
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
	
	printf("buffersize	= %d\n",BUFFER_SIZE);
	buffer = malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while ((result = read(fd, buffer, BUFFER_SIZE)) && *buffer != '\n')
	{
		if (result == -1)
		{
			write(1, "read() fails\n", 13);
			return (NULL);
		}
		buffer[result] = '\0';
		counter += result;
		collector = ft_strjoin(collector, buffer);
		if (check_newline(collector, "\n"))
		{
			printf("counter inside check_newline	= %d\n",counter);
			if (buffer)
				free(buffer);
			return (collector);
		}
	}
	printf("counter	= %d\n",counter);
	if (buffer)
		free(buffer);
	return (collector);
}
