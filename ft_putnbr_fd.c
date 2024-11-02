/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:08:33 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/02 13:00:48 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_pow10(int n)
{
	int	i;
	int	return_value;

	if (n < 0)
		return (0);
	if (n == 0)
		return (1);
	else if (n == 1)
		return (10);
	i = 1;
	return_value = 10;
	while (i < n)
	{
		return_value *= 10;
		i++;
	}
	return (return_value);
}

static int	_get_digit(int nb)
{
	int	digit;

	digit = 1;
	while (nb >= 10 || nb <= -10)
	{
		nb = nb / 10;
		digit++;
	}
	return (digit);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	digit;
	int	num;

	num = 0;
	digit = _get_digit(n);
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
	}
	while (digit > 0)
	{
		num = n / _pow10(digit - 1) % 10;
		if (num < 0)
		{
			num = -num;
		}
		ft_putchar_fd(('0' + num), fd);
		digit--;
	}
}
