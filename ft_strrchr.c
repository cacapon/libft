/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:12:21 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/05 19:28:18 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Created with reference to musl.
char	*ft_strrchr(const char *s, int c)
{
	size_t	n;

	n = ft_strlen(s) + 1;
	c = (unsigned char)c;
	while (n--)
		if (s[n] == c)
			return (char *)(s + n);
	return (0);
}
