/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:09:18 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/13 23:58:38 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <unistd.h>

void	print_action(int action, u_int64_t start, int num)
{
	if (action == FORK)
		printf("%llu %d has taken a fork\n", get_gap(start), num + 1);
	else if (action == EAT)
		printf("%llu %d is eating\n", get_gap(start), num + 1);
	else if (action == SLEEP)
		printf("%llu %d is sleeping\n", get_gap(start), num + 1);
	else
		printf("%llu %d is thinking\n", get_gap(start), num + 1);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock((philo->left));
	print_action(FORK, philo->info->start_time, philo->num);
	pthread_mutex_lock((philo->right));
	print_action(FORK, philo->info->start_time, philo->num);
	philo->last_eat = get_time();
	timer(philo->info->start_time, philo->info->time_eat);
	print_action(EAT, philo->info->start_time, philo->num);
	pthread_mutex_unlock((philo->left));
	pthread_mutex_unlock((philo->right));
}

void	sleeping(t_philo *philo)
{
	print_action(SLEEP, philo->info->start_time, philo->num);
	timer(philo->info->start_time, philo->info->time_sleep);
	print_action(THINK, philo->info->start_time, philo->num);
}
