/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:38:47 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/02 12:57:36 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	_size;
	void	*_block;

	if (size > SIZE_MAX / count)
		return (NULL);
	_size = count * size;
	_block = malloc(_size);
	if (!_block)
		return (NULL);
	ft_memset(_block, 0, _size);
	return (_block);
}
