/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:46:27 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/12 17:17:06 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

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
}
