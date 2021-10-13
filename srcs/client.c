/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 07:35:42 by guderram          #+#    #+#             */
/*   Updated: 2021/10/13 07:55:19 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_push_bit(int pid, char c)
{
	int	i;

	i = 6;
	while (i >= 0)
	{
		if (c & (1 << i))
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		i--;
		usleep(1000);
	}
}

void	ft_push_string(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] > 0 && str[i] < 127)
	{
		ft_push_bit(pid, str[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	pid = 0;
	if (argc == 3 && argv[1])
		pid = ft_atoi(argv[1]);
	if (argc != 3 || pid <= 0)
	{
		write(1, "Erreur : ./client prend [pid] ", 30);
		write(1, "ainsi que [string] en arguments !\n", 35);
		return (-1);
	}
	ft_push_string(pid, argv[2]);
	return (0);
}
