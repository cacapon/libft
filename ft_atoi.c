/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttsubo <ttsubo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:46:32 by ttsubo            #+#    #+#             */
/*   Updated: 2024/10/28 18:00:49 by ttsubo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

static int	_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		has_sign;
	long	num;

	i = 0;
	sign = 1;
	has_sign = 0;
	num = 0;
	while (_isspace(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		has_sign = 1;
		i++;
	}
	if (has_sign && str[i - 1] == '-')
		sign = -1;
	while (_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * (int)num);
}
