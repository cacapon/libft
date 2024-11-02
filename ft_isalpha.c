/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:27:37 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/02 12:58:40 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_islower(int c)
{
	return ('a' <= c && c <= 'z');
}

static int	_isupper(int c)
{
	return ('A' <= c && c <= 'Z');
}

int	ft_isalpha(int c)
{
	return (_islower(c) || _isupper(c));
}
