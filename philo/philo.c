/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:38:40 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/12 20:50:35 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <sys/time.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

fork_mutex	*prepare_forks(t_info info)
{
	fork_mutex *forks;
	int	i;
	
	i = -1;
	forks = (fork_mutex *)malloc(info.num * sizeof(fork_mutex));
	if (!forks)
		exit(-1);
	while (++i < info.num)
		pthread_mutex_init(&forks[i],NULL);
	return (forks);
}

t_philo	*init_philo(t_info *info, fork_mutex *forks)
{
	t_philo		*philos;
	int			i;

	philos = (t_philo *)malloc(info->num * sizeof(t_philo));
	if (!philos)
		exit(-1);
	i = -1;
	while (++i < info->num)
	{
		philos[i].num = i;
		philos[i].amount_eat = 0;
		philos[i].left = &(forks[(i + 1) % info->num]);
		philos[i].right = &(forks[i]);
		philos[i].info = info;
	}
	return (philos);
}

void	*philos_routine(void	*philo)
{
	while(1)
	{
		eating(philo);
		sleeping(philo);
	}
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
		if (!(i % 2))
			pthread_create(&chairs[i], 0, philos_routine, &philos[i]);
		//usleep(100);
	}
	i = -1;
	while (++i < info->num)
	{
		if (i % 2)
			pthread_create(&chairs[i], 0, philos_routine, &philos[i]);
	}
	i = -1;
	while (++i < info->num)
		pthread_join(chairs[i], 0);
}
#include <stdio.h>
void	setting_philo(t_info *info)
{
	fork_mutex	*forks;
	t_philo		*philos;

	forks = prepare_forks(*info);
	philos = init_philo(info, forks);
	philo(info, philos);
	///////////////
	int	i = 0;
	while (i < 5)
	{
		printf("philo_start[%d] : %llu\n", i,philos[i].info->time_die);
		printf("philo_start[%d] : %llu\n", i,philos[i].info->time_sleep);
		i++;
	}
	/////////
}

int	main(int ac, char **av)
{
	t_info info;

	if (ac < 5)
		return (-1);
	parsing(ac, av, &info);
	setting_philo(&info);
}
