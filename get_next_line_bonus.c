/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:13:18 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/16 23:48:04 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_trim_remain(char *collector, int nl)
{
	char	*result;
	int		old;
	int		i;
	int		len;

	if (!collector)
		return (NULL);
	old = ft_strlen(collector);
	len = old - nl;
	if (len == 0)
	{
		free(collector);
		return (NULL);
	}
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = collector[i + nl];
		i++;
	}
	result[i] = '\0';
	if (*result == '\0')
		result = NULL;
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

char	*get_next_line(int fd)
{
	char		*result;
	static char	*collector;
	int			nl;
	int			byte;
	char		*buffer;

	if (fd < 0)
		return (NULL);
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte = 1;  // 1 bytebefore 
	while (byte != 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		buffer[byte] = '\0';
		if (byte == -1)
		{
			free(buffer);
			return (NULL);
		}
		if (!collector)
			collector = ft_strdup(buffer, byte);
		else
			collector = ft_strjoin(collector, buffer);
		nl = ft_find_newline(buffer);
		if (nl > 0 || byte == 0)
			break ;
	}
	free(buffer);
	nl = ft_find_newline(collector);
	if (nl == -1)
		nl = ft_strlen(collector);
	result = ft_line_return(collector, nl);
	collector = ft_trim_remain(collector, nl);
	return (result);
}
