/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:09:18 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/06 16:43:28 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_action(FORK, philo, philo->info);
	pthread_mutex_lock(philo->right);
	print_action(FORK, philo, philo->info);
	print_action(EAT, philo, philo->info);
	pthread_mutex_lock(&(philo->info->philo_mutex));
	philo->last_eating = get_time();
	pthread_mutex_unlock(&(philo->info->philo_mutex));
	checking_dish(philo);
	timer(get_time(), philo->info->time_eat);
}

void	sleeping(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	print_action(SLEEP, philo, philo->info);
	timer(get_time(), philo->info->time_sleep);
	print_action(THINK, philo, philo->info);
}
