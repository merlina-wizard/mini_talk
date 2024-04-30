/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:50:14 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/30 17:07:21 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

void	receive_signal(int i)
{
	static int				n = 0;
	static unsigned char	c = 0;

	c |= (i == SIGUSR1);
	n++;
	if (n == 8)
	{
		write(1, &c, 1);
		if (!c)
			write(1, "\n", 1);
		c = 0;
		n = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	write(1, "Waiting for signals...\n", 23);
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
	{
		pause();
	}
}
