/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:02:29 by ndormoy           #+#    #+#             */
/*   Updated: 2021/11/22 16:55:50 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp1;
	unsigned char	*temp2;
	unsigned int	i;

	i = 0;
	temp1 = (unsigned char *)dest;
	temp2 = (unsigned char *)src;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (dest);
}
