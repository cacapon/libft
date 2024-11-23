/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:50:08 by ttsubo            #+#    #+#             */
/*   Updated: 2024/11/23 16:10:38 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief utoaを再帰で処理するための内部関数
 *
 * @param [in]	value	: 変換する値
 * @param [out]	str		: 変換した値を格納する文字列
 * @param [out]	index 	: 処理している現在のインデックス
 */
static void	_utoa_recursive(unsigned int u_num, char *str, int *index)
{
	if (u_num >= 10)
		_utoa_recursive(u_num / 10, str, index);
	str[(*index)++] = (u_num % 10) + '0';
}

/**
 * @brief unsigned intのvalueを文字列に変換します。
 *
 * @param value		: 変換対象の値
 * @param dst		: 変換後の文字列を格納する文字列用の領域
 * @return char*	: 変換後の文字列の先頭ポインタ
 * @note	自作関数のためmallocの許可がありません。
 * 			dstを渡す必要があります。
 */
char	*ft_utoa(unsigned int u_num, char *dst)
{
	int	index;

	if (!dst)
		return (NULL);
	index = 0;
	_utoa_recursive(u_num, dst, &index);
	dst[index] = '\0';
	return (dst);
}
