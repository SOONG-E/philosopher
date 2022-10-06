/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:55:04 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/06 16:36:46 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>
#include "philo.h"

MILLISEC	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	while (time.tv_usec < 0 || time.tv_sec < 0)
		gettimeofday(&time, 0);
	return (((MILLISEC)time.tv_sec * 1000 + (MILLISEC)time.tv_usec / 1000));
}

MILLISEC	get_gap(MILLISEC start)
{
	MILLISEC	now;

	now = get_time();
	return (now - start);
}

void	timer(MILLISEC start, MILLISEC gap)
{
	while (get_gap(start) < gap)
		usleep(100);
}
