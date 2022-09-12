/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:47:50 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/12 14:32:33 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

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
			return (-1);
	}
	if (!idx && !str[idx])
		return (-1);
	if (!('0' <= str[idx] && str[idx] <= '9') && str[idx])
		return (-1);
	return ((int)(ret));
}
