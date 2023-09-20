/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:56:46 by hcherpre          #+#    #+#             */
/*   Updated: 2022/01/18 18:09:23 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar_fd(char c)
{
	write(1, &c, 1);
}

static void	ft_min(void)
{
	ft_putchar_fd('-');
	ft_putchar_fd('2');
	ft_putchar_fd('1');
	ft_putchar_fd('4');
	ft_putchar_fd('7');
	ft_putchar_fd('4');
	ft_putchar_fd('8');
	ft_putchar_fd('3');
	ft_putchar_fd('6');
	ft_putchar_fd('4');
	ft_putchar_fd('8');
}

void	ft_putnbr_fd(int n)
{
	if (n == -2147483648)
	{
		ft_min();
	}
	if (-2147483647 <= n && n < 0)
	{
		ft_putchar_fd('-');
		ft_putnbr_fd(n * (-1));
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10);
		ft_putnbr_fd(n % 10);
	}
	else if (n < 10 && n >= 0)
	{
		ft_putchar_fd((n + '0'));
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	nb;

	i = 0;
	neg = 1;
	nb = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}

int	ft_isdigit(char *tab)
{
	int	i;

	i = 0;
	if (tab[i] == '\0')
	{
		write (2, "Please write a correct PID !\n", 29);
		return (0);
	}
	while (tab[i])
	{
		if (tab[i] < 48 || tab[i] > 57)
		{
			write (2, "Please write a correct PID !\n", 29);
			return (0);
		}
		i++;
	}
	return (1);
}
