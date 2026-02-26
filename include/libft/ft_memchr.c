/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 22:57:08 by marvin            #+#    #+#             */
/*   Updated: 2025/10/16 14:36:25 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)c)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	const char	str[] = "Hello, world!";
// 	int			c = 'w';
// 	size_t		n = 13;
// 	char		*result;

// 	result = (char *)ft_memchr(str, c, n);
// 	if (result != NULL)
// 	{
// 		printf("Character '%c' found at position: %ld\n", c, result - str);
// 	}
// 	else
// 	{
// 		printf("Character '%c' not found in the first %zu bytes.\n", c, n);
// 	}
// 	return (0);
// }
