/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:38:40 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/15 20:12:42 by yujelee          ###   ########seoul.kr  */
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
		pthread_mutex_lock(&(philo->checker));
		pthread_mutex_lock(&(philo->info->writing));
		if (philo->amount_eat == philo->info->required_eat)
			++(philo->info->full_philos);
		pthread_mutex_unlock(&(philo->info->writing));
		pthread_mutex_unlock(&(philo->checker));
		eating(philo);
		sleeping(philo);
	}
}

void	monitoring(t_info *info, t_philo *philos)
{
	while (checking_all(philos) >= 0)
	{
		pthread_mutex_lock(&(info->writing));
		if (info->required_eat && info->full_philos == info->num)
			break ;
		pthread_mutex_unlock(&(info->writing));
	}
	//destroy_mutex(info, philos);
	// if (info->required_eat)
	// {
	// 	while (1)
	// 	{
	// 		if (info->full_philos == info->num)
	// 			break ;
	// 		if (checking_all(philos) < 0)
	// 			break ;
	// 	}
	// }
	// else
	// {
	// 	while (1)
	// 	{
	// 		if (checking_all(philos) < 0)
	// 			break ;
	// 	}
	// }
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
	usleep((info->time_eat *2 / 3) * 1000);
	i = -1;
	while (++i < info->num)
	{
		if (i % 2)
			pthread_create(&chairs[i], 0, philos_routine, &philos[i]);
	}
	monitoring(info, philos);
	i = -1;
	while (++i < info->num)
		pthread_detach(chairs[i]);
}

int	main(int ac, char **av)
{
	t_info info;
	t_philo		*philos;

	if (5 > ac || ac > 6)
		return (-1);
	if (parsing(ac, av, &info) < 0)
		return (-1);
	philos = setting_philo(&info);
	if (!philos)
		return (-1);
	philo(&info, philos);
	return (0);
}
