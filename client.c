/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 22:39:54 by mraspors          #+#    #+#             */
/*   Updated: 2022/03/23 18:52:38 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

static int	ft_errors(int argc, char **argv)
{
	int	i;

	if (argc != 3)
		return (1);
	i = -1;
	while (argv[1][++i])
	{
		if (!ft_strchr("0123456789", argv[1][i]))
			return (1);
	}
	return (0);
}

static void	ft_send_bin(unsigned char c, pid_t pid)
{
	int	i;
	int	bin;

	i = 0;
	while (i < 8)
	{
		bin = c & 0x1;
		if (bin == 0)
			kill(pid, 30);
		else
			kill(pid, 31);
		c = c >> 1;
		i++;
		usleep(150);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	int		i;

	i = 0;
	if (ft_errors(argc, argv))
		return (-1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (-1);
	str = argv[2];
	while (str[i] != '\0')
	{
		ft_send_bin(str[i], pid);
		i++;
		sleep(0);
	}
	return (0);
}
