/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:08:19 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/15 23:56:07 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_find_newline(char *collector)
{
	size_t	nl;
	size_t	len;

	if (!collector)
	{
//		printf("ffffffffff");
		collector = NULL;
		free(collector);
		return (0);
	}
	nl = 0;
	len = ft_strlen(collector);
	while(collector[nl] != '\n' && nl < len)
	{
		if (nl > len)
			return (-1);
		nl++;
	}
	return (nl + 1);
}

char	*ft_return_buffersize(char *collector)
{
	char	*tmp;
	int		len;
	
	if (!collector)
	{
//		printf("eeeeeeeeee");
		collector = NULL;
		free(collector);
		return (NULL);
	}
	len = (int)ft_find_newline(collector);
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
	{
//		printf("ddddddddd");
		collector = NULL;
		free(collector);
		return (NULL);
	}
	len = 0;
	old = (int)ft_strlen(collector);
	nl = (int)ft_find_newline(collector);
	if (nl > old)
	{
//		printf(" no_nl in shorten");
		nl = 0;
		collector = NULL;
		free(collector);
		return (NULL);
	}
	ft_memmove(collector, (collector + nl), old - nl);
	collector[old - nl] = '\0';
	if (*collector == '\0')
	{
//		printf("cccccccccc");
		collector = NULL;
		free(collector);
		return (NULL);
	}
	return (collector);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	int			result;
//	int			counter;
	static char	*collector;
	char		*ret;
	int			nl;
//	size_t		repeat;
	
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
//	repeat = 0;
//	counter = 0;
	result = 1;
	nl = 0;
//	while (counter == 0 || result != 0)
	while (result != 0)
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
		collector = ft_strjoin(collector, buffer);
//		counter += result;
		nl = (int)ft_find_newline(collector) ;
		if (nl <= (int)ft_strlen(collector) && nl != 0)
		{
//			printf("newline() found in collecttor\n");
			break;
		}
		
//		printf("collector at repeat	= %zu :%s\n",repeat, collector);
//		printf("buffer at repeat	= %zu :%s",repeat, buffer);
//		repeat++;
	}
//	printf("#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#_#\n");
//	printf("**bytes counter	=%d**",counter);

	free(buffer);
	ret  = ft_return_buffersize(collector);
//	printf("addr ret is : %p, addr collector is : %p\n",ret,collector);
//	printf("ret before : %s\n",ret);
//	printf("col before : %s\n",collector);
	collector = ft_strdup(collector + ft_find_newline(collector));
	//collector = ft_shorten_remain(collector); //should input remaining = length 
//	printf("ret after  : %s\n",ret);
//	printf("col after  : %s\n",collector);
//	printf("ret2 : %s",ret);
//	printf("addr ret is : %p, addr collector is : %p\n",ret,collector);
	if (!ft_strlen(collector))
	{
//		printf("bbbbbbbbbbb");
		collector = NULL;
		free(collector);
	}
//	printf("***ret		return	=%s***",ret);
//printf("***collector	remain	=%s***",collector);
	return (ret);
}
