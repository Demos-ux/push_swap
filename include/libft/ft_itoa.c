/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 19:31:13 by dsisli            #+#    #+#             */
/*   Updated: 2025/10/24 14:43:08 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	calculate_length_and_sign(int n, size_t *len, int *is_negative)
{
	long	num;
	long	temp;

	num = n;
	*len = 0;
	*is_negative = 0;
	if (num < 0)
	{
		*is_negative = 1;
		num = -num;
		(*len)++;
	}
	if (num == 0)
		(*len) = 1;
	else
	{
		temp = num;
		while (temp > 0)
		{
			(*len)++;
			temp /= 10;
		}
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	len;
	int		is_negative;

	num = calculate_length_and_sign(n, &len, &is_negative);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	else
	{
		while (num > 0)
		{
			str[--len] = (num % 10) + '0';
			num /= 10;
		}
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
