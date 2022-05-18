/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:06:58 by ndormoy           #+#    #+#             */
/*   Updated: 2021/11/22 11:17:54 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!*to_find)
		return ((char *)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] && to_find[j] && (i + j < len)
			&& str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == 0)
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
