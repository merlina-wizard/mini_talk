/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:50:18 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/30 17:35:23 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

int	send_signal(int pid, char c, int i)
{
	int	res;

	while (i--)
	{
		if ((c >> i) & 1)
			res = kill(pid, SIGUSR1);
		else
			res = kill(pid, SIGUSR2);
		if (res == -1)
			return (res);
		usleep(200);
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			if (send_signal(pid, argv[2][i], 8) == -1)
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			i++;
		}
		if (send_signal(pid, '\0', 8) == -1)
			write(1, "Error", 5);
	}
	else
		write(1, "Error\n", 6);
}
