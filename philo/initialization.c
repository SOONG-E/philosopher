/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:04:32 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/07 17:57:13 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>
#include <limits.h>

pthread_mutex_t	*prepare_forks(t_info info)
{
	pthread_mutex_t	*forks;
	int				i;

	i = -1;
	forks = (pthread_mutex_t *)malloc(info.num * sizeof(pthread_mutex_t));
	if (!forks)
		return (0);
	while (++i < info.num)
		pthread_mutex_init(&forks[i], 0);
	return (forks);
}

t_philo	*init_philo(t_info *info, pthread_mutex_t *forks)
{
	t_philo		*philos;
	int			i;

	philos = (t_philo *)malloc(info->num * sizeof(t_philo));
	if (!philos)
		return (0);
	i = -1;
	while (++i < info->num)
	{
		philos[i].num = i;
		philos[i].amount_eat = 0;
		philos[i].left = &(forks[(i + 1) % info->num]);
		philos[i].right = &(forks[i]);
		philos[i].info = info;
	}
	return (philos);
}

t_philo	*setting_philo(t_info *info)
{
	t_philo		*philos;

	info->forks = prepare_forks(*info);
	if (!info->forks)
		return (0);
	philos = init_philo(info, info->forks);
	if (!philos)
	{
		free(info->forks);
		return (0);
	}
	return (philos);
}

int	parsing(int ac, char **av, t_info *info)
{
	info->num = ft_atoi(av[1]);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->required_eat = ft_atoi(av[5]);
	else
		info->required_eat = 0;
	if (info->num < 0 || info->time_die > INT_MAX
		|| info->time_eat > INT_MAX
		|| info->time_sleep > INT_MAX
		|| info->required_eat < 0)
		return (-1);
	info->full_philos = 0;
	info->end_flag = 0;
	info->forks = 0;
	pthread_mutex_init(&(info->info_mutex), 0);
	pthread_mutex_init(&(info->philo_mutex), 0);
	return (0);
}
