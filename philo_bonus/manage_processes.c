/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:14:29 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/07 18:07:33 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <signal.h>
#include <unistd.h>

void	kill_them(t_info *info, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		kill(info->philo_id[i], 9);
}

int	get_exitcode(int status)
{
	return (status >> 8 & 0x000000ff);
}

void	wait_philos(t_info *info)
{
	int	status;
	int	full_philos;

	full_philos = 0;
	sem_post(info->speaker);
	waitpid(-1, &status, 0);
	while (1)
	{
		if (get_exitcode(status) == 1)
		{
			kill_them(info, info->num);
			return ;
		}
		else if (get_exitcode(status) == 2)
			++(full_philos);
		if (full_philos == info->num)
			break ;
		waitpid(-1, &status, 0);
	}
}
