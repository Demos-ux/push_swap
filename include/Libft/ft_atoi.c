/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:01:24 by marvin            #+#    #+#             */
/*   Updated: 2025/10/16 16:47:53 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (sign == 1 && result > 2147483647)
			return (2147483647);
		if (sign == -1 && result > 2147483648)
			return (-2147483648);
		i++;
	}
	return ((int)(result * sign));
}

// int main(void)
// {
// 	const char	*str1 = "2147483647";
// 	const char	*str2 = "22147483647";

// 	printf("Converted number: %d\n", ft_atoi(str1));
// 	printf("Converted number: %d\n", ft_atoi(str2));
// 	return (0);
// }
