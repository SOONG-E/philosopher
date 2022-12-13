/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:04:32 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/09 21:04:36 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

t_philo	*setting_philo(t_info *info)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(info->num * sizeof(t_philo));
	if (!philos)
		exit(-1);
	i = -1;
	while (++i < info->num)
	{
		philos[i].num = i;
		philos[i].amount_eat = 0;
		philos[i].info = info;
		philos[i].forks = info->forks;
		philos[i].pen_num = ft_itoa(i);
		sem_unlink(philos[i].pen_num);
		philos[i].pen = sem_open(philos[i].pen_num, O_CREAT, 0777, 1);
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
	{
		info->required_eat = ft_atoi(av[5]);
		if (!(info->required_eat))
			exit(-1);
	}
	else
		info->required_eat = 0;
	info->philo_id = (int *)malloc(info->num * sizeof(int));
	if (!info->philo_id)
		exit(-1);
	memset(info->philo_id, -1, info->num);
	sem_unlink("forks");
	info->forks = sem_open("forks", O_CREAT, 0644, info->num);
	sem_unlink("speaker");
	info->speaker = sem_open("speaker", O_CREAT, 0644, 1);
	return (0);
}
