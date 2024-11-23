/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_retlen.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 21:08:33 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/23 17:51:29 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes the letter c to the file descriptor
 *
 * @param c			: character
 * @param fd 		: file descriptor
 * @return size_t	: char length.
 */
size_t	ft_putchar_fd_retlen(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (ft_isascii(c));
}
