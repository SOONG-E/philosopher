/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:42:33 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/07 15:40:59 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <sys/stat.h>
#include <pthread.h>
#include <unistd.h>

void	*philos_routine(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->num % 2)
		usleep(100);
	while (1)
	{
		eating(philo);
		sleeping(philo);
	}
}

void	monitoring(t_philo *philo, pthread_t chair)
{
	while (1)
	{
		if (checking_alive(philo) < 0)
		{
			pthread_detach(chair);
			exit(1);
		}
	}
}

void	separate_philo(t_philo *philo)
{
	pthread_t	chair;

	sem_wait(philo->info->speaker);
	sem_post(philo->info->speaker);
	pthread_create(&chair, 0, philos_routine, philo);
	monitoring(philo, chair);
}
