/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:40:39 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/23 17:20:44 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>

int	checking_dish(t_philo *philo)
{
	if (!philo->info->required_eat)
		return (0);
	else
		++(philo->amount_eat);
	if (philo->amount_eat == philo->info->required_eat)
	{
		pthread_mutex_lock(&(philo->info->info_mutex));
		++(philo->info->full_philos);
		philo->info->end_flag = 2;
		pthread_mutex_unlock(&(philo->info->info_mutex));
		return (-1);
	}
	return (0);
}

int	someone_dead(t_info *info)
{
	pthread_mutex_lock(&(info->info_mutex));
	if (info->end_flag)
	{
		pthread_mutex_unlock(&(info->info_mutex));
		return (-1);
	}
	pthread_mutex_unlock(&(info->info_mutex));
	return (0);
}

int	checking_alive(t_philo *philo)
{
	if (someone_dead(philo->info) < 0)
		return (-1);
	pthread_mutex_lock(&(philo->info->philo_mutex));
	if (get_time() - philo->last_eating > philo->info->time_die)
	{
		pthread_mutex_unlock(&(philo->info->philo_mutex));
		print_action(DIE, philo);
		pthread_mutex_lock(&(philo->info->info_mutex));
		philo->info->end_flag = 1;
		pthread_mutex_unlock(&(philo->info->info_mutex));
		return (-1);
	}
	else
		pthread_mutex_unlock(&(philo->info->philo_mutex));
	return (0);
}

int	checking_all(t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < philos[0].info->num)
	{
		if (checking_alive((&philos[i])) < 0)
			return (-1);	
	}
	return (0);
}

int	print_action(int action, t_philo *philo)
{
	pthread_mutex_lock(&(philo->info->info_mutex));
	if (philo->info->end_flag)
	{
		pthread_mutex_unlock(&(philo->info->info_mutex));
		return (-1);
	}
	if (action == DIE)
	{
		printf("%llu %d died\n", get_gap(philo->info->start_time), philo->num + 1);
		pthread_mutex_unlock(&(philo->info->info_mutex));
		return (-1);
	}
	if (action == FORK)
		printf("%llu %d has taken a fork\n", get_gap(philo->info->start_time), philo->num + 1);
	else if (action == EAT)
		printf("%llu %d is eating\n", get_gap(philo->info->start_time), philo->num + 1);
	else if (action == SLEEP)
		printf("%llu %d is sleeping\n", get_gap(philo->info->start_time), philo->num + 1);
	else if (action == THINK)
		printf("%llu %d is thinking\n", get_gap(philo->info->start_time), philo->num + 1);
	pthread_mutex_unlock(&(philo->info->info_mutex));
	return (0);
}
