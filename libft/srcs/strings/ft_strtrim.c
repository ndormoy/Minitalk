/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:07:15 by ndormoy           #+#    #+#             */
/*   Updated: 2021/11/22 11:18:01 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	is_set(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	end;
	unsigned int	start;
	char			*dest;

	start = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	end = (unsigned int)ft_strlen(s1);
	while (is_set(s1[start], set) == 0)
		start++;
	if (start == end)
	{
		dest = ft_strdup("");
		if (!dest)
			return (NULL);
		return (dest);
	}
	while (is_set(s1[end - 1], set) == 0)
		end--;
	dest = ft_substr(s1, start, end - start);
	return (dest);
}
