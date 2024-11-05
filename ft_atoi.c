/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:46:32 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/05 18:39:05 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define IMAX INT_MAX
#define IMIN INT_MIN

static int	_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

// Behavior in case of atoi over/underflow is undefined.
// Therefore, INTMAX/INTMIN is returned by referring to the strtol specification.
int	ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int	degit;

	sign = 1;
	num = 0;
	while (_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '-')
		sign = -1;
	while (ft_isdigit(*str))
	{
		degit = *str - '0';
		if ((num > IMAX / 10) || (num == IMAX / 10 && digit > IMAX % 10))
			return (IMAX);
		if ((num < IMIN / 10) || (num == IMIN / 10 && digit < -(IMIN % 10)))
			return (IMIN);
		num = num * 10 + (sign * digit);
		str++;
	}
	return (num);
}
