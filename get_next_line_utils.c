/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:11:29 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/08 20:58:22 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;
 
 	if(!str)
	{
		write(1,"str() fails\n",12);
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

size_t	ft_putstr(char *str)
{
	int	len;

	len = write(1, str, ft_strlen(str));
	return (len);
}

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = n * -1;
		ft_putnbr(n);
	}
	else if (n >= 10)
	{
		ft_putnbr((n / 10));
		n = (n % 10) + '0';
		write (1, &n, 1);
	}
	else
	{
		n = (n % 10) + '0';
		write (1, &n, 1);
	}
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
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	tmp = malloc(sizeof(char) * (i + j + 1));
	if (!tmp)
		return (NULL);
	ft_memcpy(tmp, s1, i);
	ft_memcpy(tmp + i, s2, j);
	tmp[i + j] = '\0';
	return (tmp);
}
