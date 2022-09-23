/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:09:18 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/23 12:33:58 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

void	eating(t_philo *philo)
{
	checking_dish(philo); //
	pthread_mutex_lock(philo->left);
	print_action(FORK, philo->info->start_time, philo->num, philo->info->printing_mutex);
	checking_dish(philo); //
	pthread_mutex_lock(philo->right);
	checking_dish(philo); //
	print_action(FORK, philo->info->start_time, philo->num, philo->info->printing_mutex);
	print_action(EAT, philo->info->start_time, philo->num, philo->info->printing_mutex);
	//pthread_mutex_lock(&(philo->checker));
	philo->last_eating = get_time();
	++(philo->amount_eat);
	//pthread_mutex_unlock(&(philo->checker));
	timer(get_time(), philo->info->time_eat);
	checking_dish(philo); //
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	sleeping(t_philo *philo)
{
	checking_dish(philo); //
	print_action(SLEEP, philo->info->start_time, philo->num, philo->info->printing_mutex);
	timer(get_time(), philo->info->time_sleep);
	checking_dish(philo); //
	print_action(THINK, philo->info->start_time, philo->num, philo->info->printing_mutex);
}
