/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherpre <hcherpre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:56:55 by hcherpre          #+#    #+#             */
/*   Updated: 2022/01/18 17:49:44 by hcherpre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

/*******************CLIENT************************/

void	ft_end(int pid, char c);
void	ft_binaire(int pid, char *tab);
int		ft_atoi(const char *str);
int		ft_isdigit(char *tab);

/*******************SERVEUR************************/

void	ft_putchar_fd(char c);
void	ft_putnbr_fd(int n);

#endif