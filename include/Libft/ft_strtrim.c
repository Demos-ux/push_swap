/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsisli <dsisli@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 17:44:14 by dsisli            #+#    #+#             */
/*   Updated: 2025/10/17 19:23:14 by dsisli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		end;
	char	*str;
	int		len;
	int		start;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (end < 0)
		return (ft_strdup(""));
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (end >= 0 && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	if (len <= 0)
		return (ft_strdup(""));
	str = ft_substr(s1, start, len);
	if (!str)
	{
		return (NULL);
	}
	return (str);
}

// int main(void)
// {
// 	const char	*s1 = "sssttHello, World!ttss";
// 	const char	*set = "st";
// 	char		*result;

// 	result = ft_strtrim(s1, set);
// 	if (result != NULL)
// 	{
// 		printf("Trimmed string: '%s'\n", result);
// 		free(result);
// 	}
// 	else
// 	{
// 		printf("Memory allocation failed.\n");
// 	}
// 	return (0);
// }
