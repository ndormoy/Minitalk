/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:40:13 by ndormoy           #+#    #+#             */
/*   Updated: 2021/12/02 11:10:03 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_format(va_list ap, char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += ft_print_char((char)va_arg(ap, int));
	else if (format == 's')
		length += ft_print_str((char *)va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		length += ft_print_int((int)va_arg(ap, int));
	else if (format == 'p')
		length += ft_print_p(va_arg(ap, unsigned long));
	else if (format == '%')
		length += ft_putchar_percent();
	else if (format == 'x')
		length += ft_print_hex_min((va_arg(ap, unsigned int)));
	else if (format == 'X')
		length += ft_print_hex_maj((va_arg(ap, unsigned int)));
	else if (format == 'u')
		length += ft_print_unsigned_int((unsigned int)va_arg(ap, unsigned int));
	return (length);
}

int	ft_process_flag(va_list ap, const char *format)
{
	int		length;
	int		i;

	i = 0;
	length = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			length += ft_format(ap, format[i]);
		}
		else
			length += ft_print_char(format[i]);
		i++;
	}
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		length;

	length = 0;
	va_start (ap, format);
	length = ft_process_flag(ap, format);
	va_end(ap);
	return (length);
}
