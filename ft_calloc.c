/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:38:47 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/28 15:58:21 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = (char *)b;
	while (i < len)
		ptr[i++] = (unsigned char)c;
	return (b);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	_size;
	void	*_block;

	if (!count || !size)
		return (NULL);
	if (size > SIZE_MAX / count)
		return (NULL);
	_size = count * size;
	_block = malloc(_size);
	if (!_block)
		return (NULL);
	_memset(_block, 0, _size);
	return (_block);
}
