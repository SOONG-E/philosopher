/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 15:22:47 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/07 16:58:35 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	eating(t_philo *philo)
{
	sem_wait(philo->forks);
	print_action(FORK, philo, philo->info);
	sem_wait(philo->forks);
	print_action(FORK, philo, philo->info);
	print_action(EAT, philo, philo->info);
	sem_wait(philo->pen);
	philo->last_eating = get_time();
	sem_post(philo->pen);
	timer(get_time(), philo->info->time_eat);
	checking_dish(philo);
}

void	sleeping(t_philo *philo)
{
	sem_post(philo->forks);
	sem_post(philo->forks);
	print_action(SLEEP, philo, philo->info);
	timer(get_time(), philo->info->time_sleep);
	print_action(THINK, philo, philo->info);
}
