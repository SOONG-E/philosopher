/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:47:27 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/06 17:23:40 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	count_len(int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num /= 10;
		++len;
	}
	return (len);
}

char	*ft_itoa(int num)
{
	char	*ret;
	int		len;

	len = count_len(num);
	ret = (char *)malloc((len + 1) * sizeof(char));
	if (!ret)
		exit(-1);
	ret[len] = 0;
	while (--len >= 0)
	{
		ret[len] = (num % 10) + '0';
		num /= 10;
	}
	return (ret);
}
