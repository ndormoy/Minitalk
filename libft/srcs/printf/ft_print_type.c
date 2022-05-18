/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:40:09 by ndormoy           #+#    #+#             */
/*   Updated: 2021/11/30 12:41:49 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_print_char(char c)
{
	ft_putchar(c);
	return (1);
}

int	ft_print_str(char *str)
{
	size_t	length;

	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	length = 0;
	ft_putstr(str);
	length = ft_strlen(str);
	return (length);
}

int	ft_print_int(int a)
{
	size_t	length;
	char	*ret;

	length = 0;
	ret = ft_itoa(a);
	length = ft_print_str(ret);
	free(ret);
	return (length);
}

int	ft_print_unsigned_int(unsigned int a)
{
	size_t	length;
	char	*ret;

	length = 0;
	ret = ft_unsigned_itoa(a);
	length = ft_print_str(ret);
	free(ret);
	return (length);
}
