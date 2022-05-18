/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:40:19 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/02 10:06:59 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int	count_unsigned_len(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char			*itoa;
	unsigned int	len;

	if (n == 0)
		return (ft_strdup("0"));
	len = count_unsigned_len(n);
	itoa = malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	len--;
	while (n > 0)
	{
		itoa[len] = n % 10 + 48;
		n /= 10;
		len--;
	}
	return (itoa);
}
