/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:38:33 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/13 23:32:55 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h> //지우기!!!!!!!!!!!!!!!!!!!

# define fork_mutex pthread_mutex_t

# define FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3

typedef struct s_info
{
	int		num;
	u_int64_t	time_die;
	u_int64_t	time_eat;
	u_int64_t	time_sleep;
	int		required_eat;
	int		full_philos;
	u_int64_t	start_time;
}	t_info;

typedef struct s_philo
{
	int				num;
	long long		last_eat;
	int				amount_eat;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	struct s_info	*info;
	
}	t_philo;

int	ft_atoi(char *str);
u_int64_t	get_time(void);
u_int64_t	get_gap(u_int64_t start);

void	parsing(int ac, char **av, t_info *info);

t_philo		*setting_philo(t_info *info);

void	eating(t_philo *philo);
void	sleeping(t_philo *philo);

#endif
