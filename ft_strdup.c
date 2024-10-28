/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:12:30 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/25 13:24:57 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	char	*dstp;

	dst = (char *)malloc(sizeof(_strlen(src)+1));
	if (!dst)
		return (NULL);
	dstp = dst;
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dstp);
}
