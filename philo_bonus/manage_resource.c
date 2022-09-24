/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_resource.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:54:41 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/24 17:12:38 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdlib.h>

// void	destroy_semapore(t_info *info, t_philo *philos)
// {
// //
// }

void	free_all(t_info *info, t_philo *philos)
{
	free(philos);
	free(info->philo_id);
}
