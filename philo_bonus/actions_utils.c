/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:40:39 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/24 17:12:30 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>

void	checking_dish(t_philo *philo)
{
	if (!philo->info->required_eat)
		return ;
	else
		++(philo->amount_eat);
	if (philo->amount_eat == philo->info->required_eat)
		exit(-2);
}

int	checking_alive(t_philo *philo)
{
	sem_wait(philo->pen);
	if (get_time() - philo->last_eating > philo->info->time_die)
	{
		sem_post(philo->pen);
		print_action(DIE, philo, philo->info);
		exit (-1);
	}
	else
		sem_post(philo->pen);
	return (0);
}

int	print_action(int action, t_philo *philo, t_info *info)
{
	sem_wait(info->speaker);
	// if (philo->info->end_flag)
	// {
	// 	pthread_mutex_unlock(&(info->info_mutex));
	// 	return (-1);
	// }
	if (action == DIE)
	{
		printf("%llu %d died\n", get_gap(info->start_time), philo->num + 1);
		sem_wait(info->speaker);
		return (-1);
	}
	if (action == FORK)
		printf("%llu %d has taken a fork\n", get_gap(info->start_time), \
		philo->num + 1);
	else if (action == EAT)
		printf("%llu %d is eating\n", get_gap(info->start_time), philo->num + 1);
	else if (action == SLEEP)
		printf("%llu %d is sleeping\n", get_gap(info->start_time), \
		philo->num + 1);
	else if (action == THINK)
		printf("%llu %d is thinking\n", get_gap(info->start_time), \
		philo->num + 1);
	sem_wait(info->speaker);
	return (0);
}
