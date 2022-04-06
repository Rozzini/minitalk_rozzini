/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:40:03 by mraspors          #+#    #+#             */
/*   Updated: 2022/03/20 21:10:37 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft/libft.h"

void	ft_print(char *s)
{
	int		*a;
	int		i;
	int		sum;
	char	c;

	a = (int [8]){1, 2, 4, 8, 16, 32, 64, 128};
	sum = 0;
	i = 0;
	while (i < 8)
	{
		if (s[i] == '1')
			sum += a[i];
		i++;
	}
	c = sum;
	write(1, &c, 1);
}

void	sig_handler(int sig)
{
	static char	str[8];
	static int	i;

	if (i == 7)
	{
		str[i] = ((sig - 30) + '0');
		ft_print(str);
		i = 0;
		return ;
	}
	str[i] = ((sig - 30) + '0');
	i++;
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		sleep(0);
	return (0);
}
