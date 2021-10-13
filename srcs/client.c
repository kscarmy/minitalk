/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 07:35:42 by guderram          #+#    #+#             */
/*   Updated: 2021/10/13 07:37:47 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_push_bit(int pid, char c)
{
	int i;

	i = 6;
	// printf("'%c' ", c);
	// printf("|");
	while (i >= 0)
	{
		if (c & (1 << i))
		{
			// printf("1");
			kill(pid, SIGUSR1);
		}
		else
		{
			// printf("0");
			kill(pid, SIGUSR2);
		}
		i--;
		usleep(1000);
	}
	// printf("|\n");
}

void	ft_push_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] > 0 && str[i] < 127) // > 31 ne prend pas les \n en compte !!
	{
		ft_push_bit(pid, str[i]);
		// kill(pid, SIGUSR1);
		i++;
	}
	// i = 0; // A LAISSER SUR MON GIT HUB
	// while (i < 7) 	// Permet d inclure le caractere de fin (ascii 127)
	// {				// non obligatoire, fonctionne sans.
	// 	kill(pid, SIGUSR1);
	// 	i++;
	// 	usleep(1000);
	// }
}

int	main(int argc, char **argv)
{
	int pid;

	pid = 0;
	if (argc == 3 && argv[1])
		pid = ft_atoi(argv[1]);
	if (argc != 3 || pid <= 0)
	{
		write(1, "Erreur : ./client prend [pid] ainsi que [string] en arguments !\n", 65);
		return (-1);
	}
	// pid = ft_atoi(argv[1]);
	ft_push_string(pid, argv[2]);
	// printf("%s %d\n", argv[1], pid);
	return (0);
}