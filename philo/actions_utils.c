/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:40:39 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/14 19:59:42 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

void	checking_dish(t_philo *philo)
{
	if (!philo->info->required_eat)
		return ;
	else
		++(philo->amount_eat);
	if (philo->amount_eat == philo->info->required_eat)
	{
		pthread_mutex_lock(&(philo->info->writing));
		++(philo->info->full_philos);
		pthread_mutex_unlock(&(philo->info->writing));
	}
}

void	checking_alive(t_philo *philo)
{
	if (get_time() - philo->last_eating > philo->info->time_die)
	{
		philo->info->who_died = 1;
		print_action(DIE, philo->info->start_time, philo->num, philo->info->printing);
		exit(-1);
	}
}

void	checking_all(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].info->num)
		checking_alive(&philos[i]);
}

void	print_action(int action, u_int64_t start, int num, pthread_mutex_t mutex)
{
	pthread_mutex_lock(&mutex);
	if (action == FORK)
		printf("%llu %d has taken a fork\n", get_gap(start), num + 1);
	else if (action == EAT)
		printf("%llu %d is eating\n", get_gap(start), num + 1);
	else if (action == SLEEP)
		printf("%llu %d is sleeping\n", get_gap(start), num + 1);
	else if (action == THINK)
		printf("%llu %d is thinking\n", get_gap(start), num + 1);
	else
		printf("%llu %d died\n", get_gap(start), num + 1);
	pthread_mutex_unlock(&mutex);
}
