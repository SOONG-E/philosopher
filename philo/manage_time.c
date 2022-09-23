/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:55:04 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/23 15:02:36 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "philo.h"

millisec	get_time(void)
{
	struct timeval time;
	
	gettimeofday(&time, 0);
	while (time.tv_usec < 0 || time.tv_sec < 0)
		gettimeofday(&time, 0);
	return (((u_int64_t)time.tv_sec * 1000 + (u_int64_t)time.tv_usec / 1000));
}

millisec	get_gap(millisec start)
{
	millisec	now;
	
	now = get_time();
	return (now - start);
}

int	timer(millisec start, millisec gap, t_philo *philo)
{
	usleep(gap * 700);
	while (get_gap(start) < gap)
	{
		if (checking_alive(philo) < 0)
			return (-1);
		usleep(100);
	}
	return (0);
}