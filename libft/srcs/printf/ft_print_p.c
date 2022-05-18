/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:40:01 by ndormoy           #+#    #+#             */
/*   Updated: 2021/11/30 12:41:38 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hexa_p(unsigned long nb)
{
	static int		count;
	char			*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (nb > 16 - 1)
	{
		ft_hexa_p(nb / 16);
		nb = nb % 16;
	}
	count++;
	ft_putchar(hex[nb % 16]);
	return (count);
}

int	ft_print_p(unsigned long n)
{
	int	length;

	length = 0;
	ft_putstr("0x");
	length = ft_hexa_p(n);
	return (length + 2);
}
