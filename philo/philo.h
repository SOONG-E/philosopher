/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:38:33 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/23 17:44:58 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h> //지우기!!!!!!!!!!!!!!!!!!!

# define fork_mutex pthread_mutex_t
# define millisec	unsigned long long

# define FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3
# define DIE	4

typedef struct s_info
{
	int				num;
	millisec		time_die;
	millisec		time_eat;
	millisec		time_sleep;
	int				required_eat;
	int				full_philos;
	int				end_flag;
	pthread_mutex_t	info_mutex;
	pthread_mutex_t	philo_mutex;
	millisec		start_time;
	fork_mutex		*forks;
}	t_info;

typedef struct s_philo
{
	int				num;
	millisec		last_eating;
	int				amount_eat;
	fork_mutex		*left;
	fork_mutex		*right;
	struct s_info	*info;
}	t_philo;

int			ft_atoi(char *str);
millisec	get_time(void);
millisec	get_gap(millisec start);
int			timer(millisec start, millisec gap, t_philo *philo);

int			parsing(int ac, char **av, t_info *info);

t_philo		*setting_philo(t_info *info);

int			print_action(int action, t_philo *philo);

int			eating(t_philo *philo);
int			sleeping(t_philo *philo);

int			checking_dish(t_philo *philo);
int			checking_alive(t_philo *philo);
int			checking_all(t_philo *philos);

void		destroy_mutex(t_info *info, t_philo *philos);
void		free_all(t_info *info, t_philo *philos);

#endif
