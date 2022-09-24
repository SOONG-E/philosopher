/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_processes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 17:14:29 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/24 17:14:57 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <signal.h>

void	kill_them(t_info *info)
{
	int i;

	i = -1;
	while (++i < info->num)
		if (kill(info->philo_id[i], 9) < 0)
			--i;
}

void	wait_philos(t_info *info)
{
	int flag;
	int	philo_id;
	int full_philos;

	full_philos = 0;
	philo_id = waitpid(-1, &flag, 0);
	while (1)
	{
		if (flag == -1)
			kill_them(info);
		else if (flag == -2)
			++full_philos;
		if (full_philos == info->num)
			break;
		flag = waitpid(-1, &flag, 0);
	}
}