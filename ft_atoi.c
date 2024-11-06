/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:46:32 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/06 14:34:25 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION:
		Converts the passed string to an int.
		ARGS:
			str: String to be converted to an integer
	IN:
		str:	str consists of the following three parts
			space	: any number
			+ or -	: only 1
			0-9		: any number
	OUT:
		normal:			INT_MIN	<= int(value) <= INT_MAX
		overflow:		INT_MAX
		underflow:		INT_MIN
		str is NULL:	0
		else:			0
*/

#include "libft.h"
#define IMAX INT_MAX
#define IMIN INT_MIN

//	Find out if it is space.
//	The following characters are considered spaces in ascii code.
//		'\t':9	'\n':10	'\v':11	'\f':12	'\r':13	' ':32
static int	_isspace(int c)
{
	return ((9 <= c && c <= 13) || c == 32);
}

//	Check for overflow in the next calculations.
static int	_is_next_overflow(int num, int degit)
{
	return ((num > IMAX / 10) || (num == IMAX / 10 && degit > 7));
}

//	Check for underflow in the next calculations.
static int	_is_next_underflow(int num, int degit)
{
	return ((num < IMIN / 10) || (num == IMIN / 10 && degit < -8));
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;
	int	degit;

	if (str == NULL)
		return (0);
	sign = 1;
	num = 0;
	while (_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		degit = *str - '0';
		if (_is_next_overflow(sign * num, sign * degit))
			return (IMAX);
		if (_is_next_underflow(sign * num, sign * degit))
			return (IMIN);
		num = num * 10 + degit;
		str++;
	}
	return (sign * num);
}
