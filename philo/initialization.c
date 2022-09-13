/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:04:32 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/13 21:10:32 by yujelee          ###   ########seoul.kr  */
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
		pthread_mutex_init(&forks[i],NULL);
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
