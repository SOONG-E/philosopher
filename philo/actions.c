/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:09:18 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/06 16:19:22 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	if (print_action(FORK, philo, philo->info) < 0)
		return (-1);
	pthread_mutex_lock(philo->right);
	if (print_action(FORK, philo, philo->info) < 0)
		return (-1);
	if (print_action(EAT, philo, philo->info) < 0)
		return (-1);
	pthread_mutex_lock(&(philo->info->philo_mutex));
	philo->last_eating = get_time();
	pthread_mutex_unlock(&(philo->info->philo_mutex));
	timer(get_time(), philo->info->time_eat);
	if (checking_dish(philo) < 0)
		return (-2);
	return (0);
}

int	sleeping(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	if (print_action(SLEEP, philo, philo->info) < 0)
		return (-1);
	timer(get_time(), philo->info->time_sleep);
	if (print_action(THINK, philo, philo->info) < 0)
		return (-1);
	return (0);
}
