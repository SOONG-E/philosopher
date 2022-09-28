/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:38:40 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/28 14:01:39 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>
#include <unistd.h>

void	philo(t_info *info, t_philo *philos)
{
	int	i;

	i = -1;
	sem_wait(info->speaker);
	info->start_time = get_time();
	while (++i < info->num)
	{
		philos[i].last_eating = info->start_time;
		info->philo_id[i] = fork();
		if (!info->philo_id[i])
		{
			separate_philo(&philos[i]);
			break;
		}
		else if (info->philo_id[i] < 0)
			exit (-1);
	}
	sem_post(info->speaker);
	if (info->philo_id[info->num - 1] > 0)
		wait_philos(info);
}

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philos;

	if (5 > ac || ac > 6)
		return (-1);
	if (parsing(ac, av, &info) < 0)
		return (-1);
	philos = setting_philo(&info);
	philo(&info, philos);
}
