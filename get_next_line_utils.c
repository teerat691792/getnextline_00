/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:14:37 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/16 23:48:06 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int	len;
	
	if (!str)
		return (0);
	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_find_newline(char *str)
{
	int	len;
	int	i;
	
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] == '\n')
			return (i + 1);//index  if + 1 == len
		if (!str)
			return (0);
		i++;
	}
	return (-1);
}

char	*ft_strdup(char *str, int len)
{
	char	*tmp;
	int		i;

	if (!str || len == 0)
		return (NULL);
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}

	tmp[i] = 0;
	return(tmp);
}
char	*ft_strdup_free(char *str, int len)
{
	char	*tmp;
	int		i;

	if (!str || len == 0)
		return (NULL);
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
//	if (str)
	free(str);
	return(tmp);
}
char	*ft_strjoin(char *dst, char *src)
{
	char	*tmp;
	int		lendst;
	int		lensrc;
	int		i;
	int		j;

	if (!src)
		return (dst);
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	tmp = malloc(sizeof(char) * (lendst + lensrc + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	j = 0;
	while (i < lendst )
	{
		tmp[i] = dst[i];
		i++;
	}
	while (j < lensrc )
	{
		tmp[i + j] = src[j];
		j++;
	}
	tmp[i + j] = '\0';
//	free(src);
	free(dst);
	return (tmp);
}
