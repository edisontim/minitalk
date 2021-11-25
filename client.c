/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 18:40:48 by tedison           #+#    #+#             */
/*   Updated: 2021/06/11 14:07:56 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include "minitalk.h"

void	binary(char *str, unsigned int pid)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i] != '2')
	{
		if (str[i] == '0')
			kill(pid, SIGUSR1);
		if (str[i] == '1')
			kill(pid, SIGUSR2);
		usleep(60);
		i++;
	}
}

void	send_message(int pid, char *str)
{
	char			*binary_char;
	unsigned int	size;

	if (pid <= 0)
		return ;
	binary_char = NULL;
	binary_char = ft_convert_base(str, &size);
	binary(binary_char, pid);
	if (binary_char)
		free(binary_char);
}

int	main(int argc, char *argv[])
{
	if (argc != 3)
		return (0);
	if (argv[1] < 0)
		return (0);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}
