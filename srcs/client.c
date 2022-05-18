/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndormoy <ndormoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:26:28 by ndormoy           #+#    #+#             */
/*   Updated: 2022/01/05 17:03:42 by ndormoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
}

int	ft_send_msg(char **argv, int size)
{
	int				i;
	int				j;

	i = 0;
	while (i <= size)
	{
		j = 7;
		while (j >= 0)
		{
			if (((argv[2][i] >> j) & 1) == 0)
			{
				if (kill(ft_atoi(argv[1]), SIGUSR1) == -1)
					return (-1);
			}
			else
				if (kill(ft_atoi(argv[1]), SIGUSR2) == -1)
					return (-1);
			usleep(500);
			j--;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int				size;

	if (argc == 3)
	{
		size = ft_strlen(argv[2]);
		if (ft_send_msg(argv, size) == -1)
		{
			ft_error("Something went wrong while sending the message\n");
			exit(0);
		}		
		else
			ft_printf("Message sent\n");
	}
	else
		ft_printf("Wrong numbers of arguments\n");
	return (0);
}
