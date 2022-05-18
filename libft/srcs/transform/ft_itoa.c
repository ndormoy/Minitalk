/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:01:46 by ndormoy           #+#    #+#             */
/*   Updated: 2021/11/22 11:12:13 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	count_len(long n_new)
{
	unsigned int	i;

	i = 0;
	if (n_new < 0)
	{
		n_new *= -1;
		i++;
	}
	while (n_new > 0)
	{
		n_new /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*itoa;
	unsigned int	len;
	long			n_new;

	n_new = n;
	if (n_new == 0)
		return (ft_strdup("0"));
	len = count_len(n_new);
	itoa = malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	len--;
	if (n_new < 0)
	{
		n_new *= -1;
		itoa[0] = '-';
	}
	while (n_new > 0)
	{
		itoa[len] = n_new % 10 + 48;
		n_new /= 10;
		len--;
	}
	return (itoa);
}
