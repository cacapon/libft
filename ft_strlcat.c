/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 09:59:27 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/02 13:06:36 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	d_l;
	size_t	s_l;

	d_l = (size_t)ft_strlen(dst);
	s_l = (size_t)ft_strlen(src);
	if (d_l >= dstsize)
		d_l = dstsize;
	if (d_l == dstsize)
		return (d_l + s_l);
	return (d_l + ft_strlcpy(dst + d_l, src, dstsize - d_l));
}
