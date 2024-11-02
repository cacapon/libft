/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:50:08 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/02 15:08:37 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_count_digits(int n)
{
	int	count;

	if (n < 0)
		n = -n;
	if (n == 0)
		return (1);
	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				len;
	unsigned int	num;

	num = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = _count_digits(n) + (n < 0);
	s = (char *)malloc(len + 1);
	if (!s)
		return (NULL);
	ft_memset(s, 0, (len + 1) * sizeof(char));
	if (n < 0)
		num = -n;
	while (num > 0)
	{
		s[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		s[0] = '-';
	return (s);
}
