/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:55:04 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/13 23:35:08 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>

u_int64_t	get_time(void)
{
	struct timeval time;
	
	gettimeofday(&time, 0);
	while (time.tv_usec < 0 || time.tv_sec < 0)
		gettimeofday(&time, 0);
	return (((u_int64_t)time.tv_sec * 1000 + (u_int64_t)time.tv_usec / 1000));
}

u_int64_t	get_gap(u_int64_t	start)
{
	u_int64_t	now;
	
	now = get_time();
	return (now - start);
}
