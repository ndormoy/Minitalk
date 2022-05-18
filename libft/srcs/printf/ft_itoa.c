/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:39:40 by ndormoy           #+#    #+#             */
/*   Updated: 2021/11/30 12:40:42 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strdup(const char *src)
{
	char			*dest;
	int				len;
	unsigned int	i;

	i = 0;
	len = ft_strlen ((char *)src);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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
