/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:13:18 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/16 23:48:04 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_trim_remain(char *collector, int nl)
{
	char	*result;
	int		old;
	int		i;
	int 	len;

	old = ft_strlen(collector);
	len = old - nl;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = collector[i + nl];
		i++;
	}
	result[i + nl] = '\0';
//	free(collector);
//	collector = NULL;
	return (result);
}

char	*ft_line_return(char *collector, int nl)
{
	char	*result;
	
	result = ft_strdup(collector, nl);
	
	return (result);
}

/*
static char	*ft_read_text(int fd)
{
	int		byte;
	char	*collector;
	char	*join;
	char	*buffer;
	int		nl;
	int		len;

	if (BUFFER_SIZE < 1 || fd == -1)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte = 1;
	while (byte != 0)
	{
		byte  = read(fd, buffer, BUFFER_SIZE);
		buffer[byte] = '\0'; 
		if (!collector)
		{
			printf("null collector\n");
			collector = ft_strdup(buffer,ft_strlen(buffer));
		}
		else
		{
			len = ft_strlen(collector);
			printf("	len :%d\n",len);
			join = ft_strdup(collector, len);
			collector = ft_strjoin(join, buffer);
		}
		nl = ft_find_newline(buffer);
		if (nl > 0)
			break;
	}
//	if (buffer)
		free(buffer);
	return (collector);
}
*/

char	*get_next_line(int fd)
{
	char		*result;
	static char 	*collector;
	int			nl;
//	char		*tmp;

	
//	collector = ft_read_text(fd);

	int		byte;
	char	*join;
	char	*buffer;
	int		len;

	if (BUFFER_SIZE < 1 || fd == -1)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	byte = 1;
	while (byte != 0)
	{
		byte  = read(fd, buffer, BUFFER_SIZE);
		buffer[byte] = '\0'; 
		if (!collector)
		{
			printf("null collector\n");
			collector = ft_strdup(buffer,ft_strlen(buffer));
		}
		else
		{
			len = ft_strlen(collector);
			printf("	len :%d\n",len);
			join = ft_strdup(collector, len);
			collector = ft_strjoin(join, buffer);
		}
		nl = ft_find_newline(buffer);
		if (nl > 0)
			break;
	}
//	if (buffer)
		free(buffer);

	// copy expected return
	nl = ft_find_newline(collector);
	result = ft_line_return(collector, nl);

	// cut unexpected remain out

//	tmp = ft_strdup(collector, ft_strlen(collector));
	collector = ft_trim_remain(collector, nl);
//	if (*collector == '\0') // free if no remain
//		free(collector);
	printf("	collector before return :%s\n",collector);
	return (result);
}
