/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:47:50 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/07 17:16:53 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	idx;
	int	ret;

	idx = 0;
	ret = 0;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		ret = ret * 10 + (str[idx] - 48);
		idx++;
		if ((ret & INT_MIN) != 0)
			exit(1);
	}
	if (!idx && !str[idx])
		exit(1);
	if (!('0' <= str[idx] && str[idx] <= '9') && str[idx])
		exit(1);
	return ((int)(ret));
}
