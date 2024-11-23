/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 18:35:30 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/23 18:36:07 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief itohを再帰で処理するための内部関数。
 *
 * @param u_num 	: 渡された符号なし整数
 * @param hex_str 	: 符号なし整数を格納する文字列
 * @param index 	:
 * @param is_upper 	: 大文字にするかを判定するフラグ 1で有効
 */
static void	_itoh_recursive(unsigned int u_num, char *hex_str,
		unsigned int *index, int is_upper)
{
	unsigned int	hex;
	const char		*upper_hex = "0123456789ABCDEF";
	const char		*lower_hex = "0123456789abcdef";

	hex = 16;
	if (u_num >= hex)
		_itoh_recursive(u_num / hex, hex_str, index, is_upper);
	if (is_upper)
		hex_str[(*index)++] = upper_hex[(u_num % hex)];
	else
		hex_str[(*index)++] = lower_hex[(u_num % hex)];
}

/**
 * @brief 整数を１６進数形式の文字列に変換します。
 *
 * @param num		: 変換する整数
 * @param hex_str	: 変換する文字列を格納する文字列領域
 * @param is_upper	: 大文字表記にするかのフラグ 1だと有効
 * @return char*	: 変換後の文字列の先頭ポインタ
 */
char	*ft_itoh(int num, char *hex_str, int is_upper)
{
	unsigned int	index;
	unsigned int	u_num;

	index = 0;
	u_num = (unsigned int)num;
	if (is_upper == 1)
		_itoh_recursive(u_num, hex_str, &index, is_upper);
	else
		_itoh_recursive(u_num, hex_str, &index, is_upper);
	hex_str[index] = '\0';
	return (hex_str);
}
