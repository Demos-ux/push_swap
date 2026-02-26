/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:43:14 by marvin            #+#    #+#             */
/*   Updated: 2025/10/16 11:58:08 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

// int main()
// {
// 	const char str[] = "Hello, world!";
// 	size_t length;

// 	length = ft_strlen(NULL);
// 	// printf("Length of the string is: %zu\n", length);
// }
