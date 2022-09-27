/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 16:42:33 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/27 19:57:24 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <sys/stat.h>
#include <pthread.h>
#include <unistd.h>

void	*philos_routine(void	*arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->num % 2)
		usleep((philo->info->time_eat / 2 ) * 1000);
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
			exit(-1);
		}
	}
}

void	separate_philo(t_philo *philo)
{
	pthread_t	chair;
	
	//philo->pen = sem_open("writing", O_CREAT, S_IRWXU, 1);
	pthread_create(&chair, 0, philos_routine, philo);
	monitoring(philo, chair);
}

/*
프로세스 다 생성되기 전까지 잠궈두기
세마포어 이름 다 달라야함 itoa
*/