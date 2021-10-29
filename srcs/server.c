/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 07:35:34 by guderram          #+#    #+#             */
/*   Updated: 2021/10/13 08:00:21 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_pid(void)
{
	int	pid;

	pid = getpid();
	if (pid > 0)
	{
		ft_putnbr(pid);
		ft_putstr("\n");
	}
}

void	ft_wait_sig(int sig)
{
	static char	c;
	static int	i;

	if (--i == -1)
	{
		i = 6;
		c = 0;
	}
	if (sig == SIGUSR1)
	{
		c |= (1 << i);
	}
	if (i == 0)
	{
		ft_putchar(c);
	}
}

int	main(int argc, char **argv)
{
	argv[0] = NULL;
	if (argc != 1)
	{
		ft_putstr("Erreur : ./server ne prend pas d'argument !\n");
		return (-1);
	}
	ft_pid();
	signal(SIGUSR1, ft_wait_sig);
	signal(SIGUSR2, ft_wait_sig);
	while (1)
	{
	}
	return (0);
}
