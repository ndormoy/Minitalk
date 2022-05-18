/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:26:32 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/05 18:58:24 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "ft_printf.h"

char	*ft_strjoin_letter(char *s1, char c)
{
	char			*dest;
	size_t			len_dest;
	unsigned int	i;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1 && !c)
		return (NULL);
	len_dest = ft_strlen((char *)s1) + 1;
	dest = (char *)malloc(sizeof(char) * (len_dest + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
		*dest++ = s1[i++];
	i = 0;
	if (c)
		*dest++ = c;
	*dest = '\0';
	free(s1);
	return (dest - len_dest);
}

void	sig_handler(int signal)
{
	static char	c = 0;
	static int	len = 7;
	static char	*msg = NULL;

	if (signal == SIGUSR2)
	{
		c += (1 << len);
		len--;
	}
	else
		len--;
	if (len < 0)
	{
		if (c == '\0')
		{
			ft_printf("%s\n", msg);
			free(msg);
			msg = NULL;
		}
		else
			msg = ft_strjoin_letter(msg, c);
		c = 0;
		len = 7;
	}
}

int	main(void)
{
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	ft_printf("%d\n", getpid());
	while (1)
	{
	}
	return (0);
}
