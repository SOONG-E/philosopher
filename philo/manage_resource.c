/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_resource.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:54:41 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/23 17:45:15 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

void	destroy_mutex(t_info *info, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < info->num)
		pthread_mutex_destroy(philos[i].right);
	pthread_mutex_destroy(&(info->info_mutex));
	pthread_mutex_destroy(&(info->philo_mutex));
}

void	free_all(t_info *info, t_philo *philos)
{
	free(info->forks);
	free(philos);
}