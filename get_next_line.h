/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:16 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/20 21:00:00 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* GNL */
char	*get_next_line(int fd);

/* Utility */
int		ft_strlen(char *str);
int		ft_find_newline(char *str);
void	*ft_strncpy(char *dst, char *src, int len);
char	*ft_strdup(char *str, int len);
char	*ft_strjoin(char *dst, char *src);
#endif
