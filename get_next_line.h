/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:12:16 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/11 16:17:44 by tkulket          ###   ########.fr       */
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
size_t	check_newline(char *collector, char *newline);


/* Utility */
size_t	ft_strlen(char *str);
size_t	ft_find_newline(char *s, int c);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
char	*ft_strjoin(char *s1, char *s2);


void	*ft_memcpy(void *dst, const void *src, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_spiltsubstr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);
char	**ft_split(char *s, char *delimiter);

/* Libft */
size_t	ft_putstr(char *str);
void	ft_putnbr(int n);

#endif
