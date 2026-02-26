/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:01:55 by marvin            #+#    #+#             */
/*   Updated: 2025/10/24 15:18:37 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	total;

	if (count == 0 || size == 0)
		total = 0;
	else
	{
		if (count > (size_t) - 1 / size)
			return (NULL);
		total = count * size;
	}
	ptr = malloc(total);
	if (!ptr)
		return (NULL);
	if (total > 0)
		ft_bzero(ptr, total);
	return (ptr);
}
