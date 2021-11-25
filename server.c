/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 12:03:21 by tedison           #+#    #+#             */
/*   Updated: 2021/06/11 14:09:50 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

#include "minitalk.h"

void	signal_handler(int signal)
{
	static int			g_count = 7;
	static unsigned int	g_message = 0;

	if (signal == SIGUSR1)
	{
		g_message += (0 << g_count);
		g_count--;
	}
	if (signal == SIGUSR2)
	{
		g_message += (1 << g_count);
		g_count--;
	}
	if (g_count == -1)
	{
		ft_putchar(g_message);
		g_message = 0;
		g_count = 7;
	}
}

int	main(void)
{
	pid_t			pid;

	pid = getpid();
	ft_putnbr_base(pid, "0123456789");
	write(1, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
	{
		pause();
	}
}
