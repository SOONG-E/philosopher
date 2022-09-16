/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:09:18 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/16 13:53:32 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	eating(t_philo *philo)
{
	//checking_alive(philo);
	pthread_mutex_lock(philo->left);
	print_action(FORK, philo->info->start_time, philo->num, philo->info->info_mutex);
	//checking_alive(philo);
	pthread_mutex_lock(philo->right);
	print_action(FORK, philo->info->start_time, philo->num, philo->info->info_mutex);
	print_action(EAT, philo->info->start_time, philo->num, philo->info->info_mutex);
	pthread_mutex_lock(&(philo->checker));
	philo->last_eating = get_time();
	pthread_mutex_unlock(&(philo->checker));
	timer(get_time(), philo->info->time_eat);
	checking_dish(philo);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	sleeping(t_philo *philo)
{
	//checking_alive(philo);
	print_action(SLEEP, philo->info->start_time, philo->num, philo->info->info_mutex);
	timer(get_time(), philo->info->time_sleep);
	//checking_alive(philo);
	print_action(THINK, philo->info->start_time, philo->num, philo->info->info_mutex);
}
