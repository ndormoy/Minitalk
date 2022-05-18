/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:39:51 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/02 10:07:44 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_hex_min(unsigned int nb)
{
	static int		count;
	char			*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (nb > 16 - 1)
	{
		ft_print_hex_min(nb / 16);
		nb = nb % 16;
	}
	count++;
	ft_putchar(hex[nb % 16]);
	return (count);
}

int	ft_print_hex_maj(unsigned int nb)
{
	static int		count;
	char			*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (nb > 16 - 1)
	{
		ft_print_hex_maj(nb / 16);
		nb = nb % 16;
	}
	count++;
	ft_putchar(hex[nb % 16]);
	return (count);
}
