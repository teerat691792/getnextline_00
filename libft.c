/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkulket <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:44:38 by tkulket           #+#    #+#             */
/*   Updated: 2023/02/09 21:51:05 by tkulket          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
