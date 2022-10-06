/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:38:40 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/06 16:22:49 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <unistd.h>

void	*philos_routine(void	*arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	//while (!someone_dead(philo->info))
	while (1)
	{
		eating(philo);
		sleeping(philo);
	}
	return (0);
}

void	monitoring(t_philo *philos, pthread_t *chairs)
{
	int	i;
	
	while (1)
	{
		if (checking_all(philos) < 0 || someone_dead(philos[0].info))
			break ;
	}
	//if (philos[0].info->num > 1)
	//{
		i = -1;
		while (++i < philos[0].info->num)
			pthread_detach(chairs[i]);
	//}
	//else
	//	pthread_detach(chairs[0]);
	
}

void	philo(t_info *info, t_philo *philos, pthread_t *chairs)
{
	int	i;

	chairs = (pthread_t *)malloc((info->num) * sizeof(pthread_t));
	if (!chairs)
		return ;
	i = -1;
	info->start_time = get_time();
	while (++i < info->num)
	{
		pthread_mutex_lock(&(info->philo_mutex));
		philos[i].last_eating = info->start_time;
		pthread_mutex_unlock(&(info->philo_mutex));
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
	monitoring(philos, chairs);
}

int	main(int ac, char **av)
{
	t_info		info;
	t_philo		*philos;
	pthread_t	*chairs;

	if (5 > ac || ac > 6)
		return (-1);
	if (parsing(ac, av, &info) < 0)
		return (-1);
	philos = setting_philo(&info);
	if (!philos)
		return (-1);
	chairs = 0;
	philo(&info, philos, chairs);
	free_all(&info, philos, chairs);
	return (0);
}
