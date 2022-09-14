/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:04:32 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/14 13:06:34 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

fork_mutex	*prepare_forks(t_info info)
{
	fork_mutex *forks;
	int	i;
	
	i = -1;
	forks = (fork_mutex *)malloc(info.num * sizeof(fork_mutex));
	if (!forks)
		exit(-1);
	while (++i < info.num)
		pthread_mutex_init(&forks[i], 0);
	return (forks);
}

t_philo	*init_philo(t_info *info, fork_mutex *forks)
{
	t_philo		*philos;
	int			i;

	philos = (t_philo *)malloc(info->num * sizeof(t_philo));
	if (!philos)
		exit(-1);
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

t_philo		*setting_philo(t_info *info)
{
	fork_mutex	*forks;
	t_philo		*philos;

	forks = prepare_forks(*info);
	philos = init_philo(info, forks);
	return (philos);
}

void	parsing(int ac, char **av, t_info *info)
{
	info->num = ft_atoi(av[1]);
	info->time_die = ft_atoi(av[2]);
	info->time_eat = ft_atoi(av[3]);
	info->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		info->required_eat = ft_atoi(av[5]);
	else
		info->required_eat = 0;
	if (info->num < 0 || info->time_die < 0 ||info->time_eat < 0
		|| info->time_sleep < 0 || info->required_eat < 0)
		exit(-1);
	info->full_philos = 0;
	pthread_mutex_init(&(info->writing), 0);
	info->who_died = 0;
}
