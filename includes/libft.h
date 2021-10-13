/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:25:39 by guderram          #+#    #+#             */
/*   Updated: 2021/10/13 07:51:52 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <signal.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_pid(void);
int		ft_atoi(char *nptr);
void	ft_push_string(int pid, char *str);
void	ft_push_bit(int pid, char c);
void	ft_wait_sig(int sig);
void	*ft_memset(void *s, int c, size_t n);
void	ft_putstr(char *str);

#endif
