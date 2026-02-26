/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 23:02:39 by marvin            #+#    #+#             */
/*   Updated: 2025/10/16 12:23:28 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dup;

	len = 0;
	while (s1[len])
		len++;
	dup = (char *)malloc((len + 1));
	if (!dup)
		return (0);
	ft_strlcpy(dup, (char *)s1, len + 1);
	return (dup);
}
