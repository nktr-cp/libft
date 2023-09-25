/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knishiok <knishiok@student.42.jp>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:42:35 by knishiok          #+#    #+#             */
/*   Updated: 2023/09/24 22:27:03 by knishiok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n, int base_size)
{
	int	digit;

	digit = 0;
	if (n == 0)
		digit++;
	while (n)
	{
		n /= base_size;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	long long	lnb;
	int			is_negative;
	int			digit;
	char		*result;

	lnb = n;
	is_negative = n < 0;
	digit = digit_count(n, 10);
	result = (char *)malloc(sizeof(char) * (digit + is_negative + 1));
	if (result == NULL)
		return (result);
	result[digit + is_negative] = '\0';
	if (is_negative)
	{
		result[0] = '-';
		lnb *= -1;
	}
	while (digit--)
	{
		result[is_negative + digit] = lnb % 10 + '0';
		lnb /= 10;
	}
	return (result);
}
