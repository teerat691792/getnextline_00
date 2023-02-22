/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:14:37 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/20 16:00:59 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
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

	if (!str)
		return (0);
	len = ft_strlen(str);
	i = 0;
	while (i < len)
	{
		if (str[i] == '\n' )
			return (i + 1);
		if (!str)
			return (0);
		i++;
	}
	return (-1);
}

void	*ft_strncpy(char *dst, char *src, int len)
{
	int	i;

	if (!src || len == 0)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(char *str, int len)
{
	char	*tmp;

	if (!str || len == 0)
		return (NULL);
	tmp = malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	ft_strncpy(tmp, str, len);
	return (tmp);
}

char	*ft_strjoin(char *dst, char *src)
{
	char	*tmp;
	int		lendst;
	int		lensrc;

	lensrc = ft_strlen(src);
	if (lensrc == 0)
		return (dst);
	lendst = ft_strlen(dst);
	tmp = malloc(sizeof(char) * (lensrc + lendst + 1));
	if (!tmp)
		return (NULL);
	ft_strncpy(tmp, dst, lendst);
	ft_strncpy(tmp + lendst, src, lensrc);
	free (dst);
	return (tmp);
}
