/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:54:41 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/16 13:53:37 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_mutex(t_info *info, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < info->num)
	{
		pthread_mutex_destroy(&(philos[i].checker));
		pthread_mutex_destroy(philos[i].right);
	}
	pthread_mutex_destroy(&(info->info_mutex));
}
