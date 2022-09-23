/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:40:39 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/23 12:34:11 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

void	checking_dish(t_philo *philo)
{
	if (checking_alive(philo) < 0)
	{
		pthread_mutex_lock(&(philo->info->info_mutex));
		philo->info->who_died = 1;
		pthread_mutex_unlock(&(philo->info->info_mutex));
		return ;
	}
	if (!philo->info->required_eat)
		return ;
	//else
	//	++(philo->amount_eat);
	if (philo->amount_eat == philo->info->required_eat)
	{
		pthread_mutex_lock(&(philo->info->info_mutex));
		++(philo->info->full_philos);
		pthread_mutex_unlock(&(philo->info->info_mutex));
	}
}

int	checking_alive(t_philo *philo)
{
	if (get_time() - philo->last_eating > philo->info->time_die)
	{
		print_action(DIE, philo->info->start_time, philo->num, philo->info->info_mutex);
		return (-1);
	}
	return (0);
}

/*
int	checking_all(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].info->num)
	{
		if (checking_alive(&philos[i]) < 0)
			return (-1);	
	}
	return (0);
}
*/

void	print_action(int action, u_int64_t start, int num, pthread_mutex_t mutex)
{
	
	pthread_mutex_lock(&mutex);
	if (action == DIE)
	{
		printf("%llu %d died\n", get_gap(start), num + 1);
		pthread_mutex_unlock(&mutex);
		return ;
	}
	if (action == FORK)
		printf("%llu %d has taken a fork\n", get_gap(start), num + 1);
	else if (action == EAT)
		printf("%llu %d is eating\n", get_gap(start), num + 1);
	else if (action == SLEEP)
		printf("%llu %d is sleeping\n", get_gap(start), num + 1);
	else
		printf("%llu %d is thinking\n", get_gap(start), num + 1);
	pthread_mutex_unlock(&mutex);
}
