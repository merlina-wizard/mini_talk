/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamerlin <mamerlin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 15:50:18 by mamerlin          #+#    #+#             */
/*   Updated: 2024/04/30 17:08:41 by mamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mini.h"

int	send_signal(int pid, char c)
{
	int	i;
	int	res;

	i = 8;
	while (i--)
	{
		if ((c >> i) & 1)
			res = kill(pid, SIGUSR1);
		else
			res = kill(pid, SIGUSR2);
		if (res == -1)
			return (res);
		usleep(100);
	}
	return (res);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 1)
		return (0);
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		if (send_signal(pid, argv[2][i]) == -1)
		{
			write(1, "Error\n", 6);
			exit(0);
		}
		i++;
	}
	if (send_signal(pid, '\0') == -1)
		write(1, "Error", 5);
}
