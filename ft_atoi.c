/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:46:32 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/05 17:21:35 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

// TODO:llong_max/minのオーバーフロー対策を入れる
int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	num;

	i = 0;
	sign = 1;
	num = 0;
	while (_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * (int)num);
}
