/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:09:18 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/12 20:45:53 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

u_int64_t	get_gap(u_int64_t	start)
{
	u_int64_t	now;
	
	now = get_time();
	return (now - start);
}

void	eating(t_philo *philo)
{
	printf("philo_num: %d\n", philo->num);
	printf("philo_eat & sleep: %llu %llu\n", philo->info->time_eat, philo->info->time_sleep);
	pthread_mutex_lock((philo->left));
	printf("%llu %d has taken a fork\n", get_gap(philo->info->start_time), philo->num + 1);
	pthread_mutex_lock((philo->right));
	printf("%llu %d has taken a fork\n", get_gap(philo->info->start_time), philo->num + 1);
	philo->last_eat = get_time();
	usleep(philo->info->time_eat);
	printf("%llu %d is eating\n", get_gap(philo->info->start_time), philo->num + 1);
	pthread_mutex_unlock((philo->left));
	pthread_mutex_unlock((philo->right));
}

void	sleeping(t_philo *philo)
{
	printf("%llu %d is sleeping\n", get_gap(philo->info->start_time), philo->num + 1);
	usleep(philo->info->time_sleep);
	printf("%llu %d is thinking\n", get_gap(philo->info->start_time), philo->num + 1);
}
