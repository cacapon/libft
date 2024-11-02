/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:50:08 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/02 12:59:39 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// (n <= 0)... True:1 False:0
static int	_numlen(int n)
{
	int	len;

	len = (n <= 0);
	if (n < 0)
		n = -n;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		num;

	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = _numlen(n);
	s = (char *)malloc(len + (n < 0));
	if (!s)
		return (NULL);
	s[len - (n >= 0)] = '\0';
	if (n < 0)
		num = -n;
	while (num)
	{
		s[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
