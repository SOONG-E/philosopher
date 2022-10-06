/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_resource.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:54:41 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/06 14:24:20 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>

void	free_all(t_info *info, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < info->num)
	{
		sem_close(philos[i].pen);
		sem_unlink(philos[i].pen_num);
		free(philos[i].pen_num);
	}
	sem_close(info->forks);
	sem_close(info->speaker);
	sem_unlink("forks");
	sem_unlink("speaker");
	free(philos);
	free(info->philo_id);
}
