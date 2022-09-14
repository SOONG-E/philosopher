/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:38:40 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/14 17:28:11 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

void	*philos_routine(void	*arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	while(1)
	{
		if (philo->amount_eat == philo->info->required_eat)
			++(philo->info->full_philos);
		eating(philo);
		sleeping(philo);
	}
}

void	monitoring(t_info *info, t_philo *philos)
{
	if (info->required_eat)
	{
		while (1)
		{
			if (info->full_philos == info->num)
				break ;
			if (info->who_died)
				break ;
			checking_all(philos);
		}
	}
	else
	{
		while (1)
		{
			if (info->who_died)
				break ;
			checking_all(philos);
		}
	}
	exit(1);
}

void	philo(t_info *info, t_philo *philos)
{
	pthread_t		*chairs; 
	int				i;

	chairs = (pthread_t *)malloc((info->num) * sizeof(pthread_t));
	i = -1;
	info->start_time = get_time();
	while (++i < info->num)
	{
		philos[i].last_eating = info->start_time;
		if (!(i % 2))
			pthread_create(&chairs[i], 0, philos_routine, &philos[i]);
	}
	usleep((info->time_eat / 2) * 1000);
	i = -1;
	while (++i < info->num)
	{
		if (i % 2)
			pthread_create(&chairs[i], 0, philos_routine, &philos[i]);
	}
	monitoring(info, philos);
	i = -1;
	while (++i < info->num)
		pthread_join(chairs[i], 0);
}

int	main(int ac, char **av)
{
	t_info info;
	t_philo		*philos;

	if (ac < 5)
		return (-1);
	parsing(ac, av, &info);
	philos = setting_philo(&info);
	philo(&info, philos);
}
