/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:09:18 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/23 17:03:42 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

int	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	if (print_action(FORK, philo) < 0)
		return (-1);
	pthread_mutex_lock(philo->right);
	if (print_action(FORK, philo) < 0)
		return (-1);
	if (print_action(EAT, philo) < 0)
		return (-1);
	philo->last_eating = get_time();
	if (timer(get_time(), philo->info->time_eat, philo) < 0)
		return (-1);
	if (checking_dish(philo) < 0)
		return (-1);
	return (0);
}

int	sleeping(t_philo *philo)
{
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	if (print_action(SLEEP, philo) < 0)
		return (-1);
	if (timer(get_time(), philo->info->time_sleep, philo) < 0)
		return (-1);
	checking_alive(philo);
	if (print_action(THINK, philo) < 0)
		return (-1);
	return (0);
}
