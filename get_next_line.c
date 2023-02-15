/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:08:19 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/15 17:04:00 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_find_newline(char *collector)
{
	size_t	nl;

	nl = 0;
	while(collector[nl] != '\n')
		nl++;
	return (nl + 1);
}

char	*ft_return_buffersize(char *collector)
{
	char	*tmp;
	int		len;
	
	if (!collector)
		return (NULL);
	len = (int)ft_find_newline(collector);
//	if (BUFFER_SIZE < len)
//		len = BUFFER_SIZE ;
	tmp = malloc(sizeof(char) *(len + 1));
	if (!tmp)
	{
//		write(1,"malloc(tmp) to return fail\n",27);
		return (NULL);
	}
	ft_memmove(tmp, collector, len);
	tmp[len] = '\0';
	return (tmp);
}

char	*ft_shorten_remain(char* collector)
{
	int len;
	int nl;
	int old;

	if (!collector)
		return (NULL);
	len = 0;
	old = (int)ft_strlen(collector);
	nl = (int)ft_find_newline(collector);
//	if (BUFFER_SIZE < old)
//		len = BUFFER_SIZE;	
//	else if (len == 0)
//		return (NULL);
//	if (nl == 1)
//		len = 1;
//	else if (nl < BUFFER_SIZE)
//		len = nl;
	ft_memmove(collector, (collector + nl), old - nl);
	collector[old - nl] = '\0';
	if (*collector == '\0')
		return (NULL);
	return (collector);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			result;
	int			counter;
	static char	*collector;
	char		*ret;
	int			nl;
	
//	printf("****buffersize	= %d*****",BUFFER_SIZE);
	if (BUFFER_SIZE < 1 || fd == -1)
		return (NULL);
	buffer = malloc(sizeof(char) *(BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
/*	
	if (collector == NULL)
	{
		printf("re malloc Collector\n");
		collector = malloc(1);
		collector[0] = '\0';
	}
*/
	counter = 0;
	result = 1;
	nl = 0;
	while (counter == 0 || result != 0)
	{
		result = read(fd, buffer, BUFFER_SIZE);
		if (result == -1)
		{
//			write(1, "read() fails\n", 13);
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

//		printf("collector at repeat	= %zu :%s",repeat, collector);
//		printf("buffer at repeat	= %zu :%s",repeat, buffer);
	}
//	printf("#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#\n");
//	printf("**bytes counter	=%d**",counter);

	ret  = ft_return_buffersize(collector);
	collector = ft_shorten_remain(collector); //should input remaining = length of collector - buffer
	if (ft_strlen(collector) == 0)
	{
		free(collector);
		collector = NULL;
	}
	free(buffer);
//	printf("***ret		return	=%s***",ret);
//	printf("***collector	remain	=%s***",collector);
	return (ret);
}
