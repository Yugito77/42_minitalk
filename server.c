/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:56:53 by hcherpre          #+#    #+#             */
/*   Updated: 2022/01/18 18:12:37 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_sig(int sig_id)
{
	static char	c = 0;
	static int	nb = 128;

	if (sig_id == SIGUSR1)
	{
		c += nb;
		nb /= 2;
	}
	else if (sig_id == SIGUSR2)
		nb /= 2;
	if (nb < 1)
	{
		if (c == 0)
			write(1, "\n", 1);
		write(1, &c, 1);
		c = 0;
		nb = 128;
	}
}

int	main(void)
{
	write (1, "SERVER PID: ", 12);
	ft_putnbr_fd(getpid());
	write (1, "\n", 1);
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	while (1)
		pause();
	return (0);
}
