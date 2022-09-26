/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:04:32 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/26 15:57:58 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

t_philo *setting_philo(t_info *info)
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
		philos[i].pen = sem_open("writing", O_CREAT, S_IRWXU, 1);
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
	if (info->num < 0 || info->time_die < 0 || info->time_eat < 0
		|| info->time_sleep < 0 || info->required_eat < 0)
		exit(-1);
	info->philo_id = (int *)malloc(info->num * sizeof(int));
	if (!info->philo_id)
		exit(-1);
	memset(info->philo_id, -1, info->num);
	info->forks = sem_open("forks", O_CREAT, S_IRWXU, info->num);
	info->speaker = sem_open("speaker", O_CREAT, S_IRWXU, 1);
	return (0);
}
