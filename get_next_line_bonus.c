/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:58:00 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/20 20:58:12 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_trim_remain(char *collector, int nl)
{
	char	*result;
	int		len;

	if (!collector)
		return (NULL);
	len = ft_strlen(collector) - nl;
	if (len == 0)
	{
		free(collector);
		return (NULL);
	}
	result = ft_strdup(collector + nl, len);
	free(collector);
	return (result);
}

char	*ft_line_return(char *collector, int nl)
{
	char	*result;

	result = ft_strdup(collector, nl);
	if (!result)
		return (NULL);
	return (result);
}

static char	*ft_read_buffer(int fd, char *buffer, char *collector)
{
	int		byte;

	byte = 1;
	while (byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte] = '\0';
		if (!collector)
			collector = ft_strdup(buffer, byte);
		else
			collector = ft_strjoin(collector, buffer);
		if (ft_find_newline(buffer) > 0)
			break ;
	}
	free(buffer);
	return (collector);
}

//read_single_line()  or manage multiple opened-files

char	*get_next_line(int fd)
{
	char		*result;
	static char	*collector[FOPEN_MAX];
	int			nl;
	char		*buffer;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	collector[fd] = ft_read_buffer(fd, buffer, collector[fd]);
	nl = ft_find_newline(collector[fd]);
	if (nl == -1)
		nl = ft_strlen(collector[fd]);
	result = ft_line_return(collector[fd], nl);
	collector[fd] = ft_trim_remain(collector[fd], nl);
	return (result);
}
