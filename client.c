/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:56:49 by hcherpre          #+#    #+#             */
/*   Updated: 2022/01/18 18:13:27 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_binaire(int pid, char *tab)
{
	int	i;
	int	j;

	i = 7;
	j = 0;
	while (tab[j] != '\0')
	{
		i = 7;
		while (i != -1)
		{
			if (((tab[j] >> i) & 1) == 1)
			{
				kill(pid, SIGUSR1);
				usleep(100);
			}
			else if (((tab[j] >> i) & 1) == 0)
			{
				kill(pid, SIGUSR2);
				usleep(100);
			}
			i--;
		}
		j++;
	}
	ft_end(pid, tab[j]);
}

void	ft_end(int pid, char c)
{
	int	i;

	i = 7;
	while (i != -1)
	{
		if (((c >> i) & 1) == 1)
		{
			kill(pid, SIGUSR1);
			usleep(1);
		}
		else if (((c >> i) & 1) == 0)
		{
			kill(pid, SIGUSR2);
			usleep(1);
		}
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	c;

	if (argc != 3)
	{
		write (2, "Please write two arguments !\n", 29);
		return (0);
	}
	if (!ft_isdigit(argv[1]))
		return (0);
	c = ft_atoi(argv[1]);
	ft_binaire(c, argv[2]);
	return (0);
}
