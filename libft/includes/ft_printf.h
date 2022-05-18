/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:27:54 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/05 17:18:23 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_process_flag(va_list ap, const char *format);
size_t	ft_strlen(const char *str);
int		ft_format(va_list ap, char format);
int		ft_print_int(int a);
char	*ft_itoa(int n);
char	*ft_strdup(const char *src);
int		ft_print_hex_min(unsigned int nb);
int		ft_print_hex_maj(unsigned int nb);
int		ft_putchar_percent(void);
int		ft_print_unsigned_int(unsigned int a);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_print_p(unsigned long n);
int		ft_hexa_p(unsigned long nb);

#endif