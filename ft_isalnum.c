/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:42:55 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/28 13:55:38 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_is_lower(int c)
{
	return ('a' <= c && c <= 'z');
}

static int	_is_upper(int c)
{
	return ('A' <= c && c <= 'Z');
}

static int	_isalpha(int c)
{
	return (_is_lower(c) || _is_upper(c));
}

static int	_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isalnum(int c)
{
	return (_isalpha(c) || _isdigit(c));
}
