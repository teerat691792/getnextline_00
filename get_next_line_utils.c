/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:11:29 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/10 17:27:21 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;
 
 	if(!str)
	{
//		write(1,"strlen() fails\n",15);
		return(0);
	}
	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;
	char	a;
	int		i;

	a = (char)c;
	tmp = (char *)s;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == a)
			return ((char *)tmp + i);
		i++;
	}
	if (!a && tmp[i] == '\0')
	{
		return ((char *)tmp + i);
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (d == s || n == 0)
		return (dst);
	if (!d && !s)
		return (0);
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*tmp;

//	if (!s1 || !s2)
//		return (0);
	if (!s2)
		return (0);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	tmp = malloc(sizeof(char) * (i + j + 1));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, s1, i);
	ft_memcpy(tmp + i, s2, j);
	tmp[i + j] = '\0';
	if(s1)
		free(s1);
//	if (s2)
//		free(s2);
	return (tmp);
}


void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}


void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*tmp;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (0);
	tmp = malloc(size * count);
	if (!tmp)
		return (0);
	ft_bzero(tmp, count * size);
	return (tmp);
}

char	*ft_splitsubstr(char *s, unsigned int start, size_t len)
{
	char			*tmp;
	unsigned int	i;

	if (start > (size_t)ft_strlen(s))
		return (ft_calloc(1, 1));
	if (ft_strlen(s) - start < len)
		len = (size_t)ft_strlen(s + start);
	tmp = malloc(sizeof(*s) * len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	if (*needle == 0)
		return ((char *)haystack);
	if (*haystack == 0)
		return (0);
	i = 0;
	j = 0;
	tmp = (char *)haystack;
	while (tmp[i] != '\0' && i < len)
	{
		while (tmp[i + j] == needle[j] && needle[j] && i + j < len)
		{
			j++;
		}
		if (needle[j] == '\0')
			return (tmp + i);
		else
			j = 0;
		i++;
	}
	return (0);
}


size_t	ft_countsplit(char *s, char *delimiter)
{
/*
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	if (!s)
		return (count);
	while (s[i])
	{
		if (s[i] != c && s[i + 1] == c)
			count++;
		else if (s[i + 1] == '\0' && count == 0 && s[i] == c)
			return (0);
		else if (s[i + 1] == '\0' && count == 0)
			count++;
		else if (s[i + 1] == '\0' && s[i] != c)
			count++;
		i++;
	}

	return (count);

*/
	return (ft_strlen(ft_strnstr(s, delimiter, ft_strlen(s))));
}


char	**ft_split(char *s, char *delimiter)
{
	char	**tmp;
	size_t	count;
	size_t	b;
	size_t	i;
	int		c = '\n';

	if (!s)
		return (NULL);
	count = ft_countsplit(s, delimiter);
	if (count == 0)
		return (NULL);
	tmp = (char **)malloc(sizeof(char *) * (count + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < count)
	{
		if (s[0] == c)
			s = ft_strchr(s, c) + 1;
		b = ft_strlen(s) - ft_strlen(ft_strchr(s, c));
		tmp[i] = ft_splitsubstr(s, 0, b);
		s = ft_strchr(s, c) + 1;
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}
