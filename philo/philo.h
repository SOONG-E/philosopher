/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:38:33 by yujelee           #+#    #+#             */
/*   Updated: 2022/09/23 19:27:43 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <pthread.h>

# define FORK_MUTEX pthread_mutex_t
# define MILLISEC	unsigned long long

# define FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3
# define DIE	4

typedef struct s_info
{
	int				num;
	MILLISEC		time_die;
	MILLISEC		time_eat;
	MILLISEC		time_sleep;
	int				required_eat;
	int				full_philos;
	int				end_flag;
	pthread_mutex_t	info_mutex;
	pthread_mutex_t	philo_mutex;
	MILLISEC		start_time;
	FORK_MUTEX		*forks;
}	t_info;

typedef struct s_philo
{
	int				num;
	MILLISEC		last_eating;
	int				amount_eat;
	FORK_MUTEX		*left;
	FORK_MUTEX		*right;
	struct s_info	*info;
}	t_philo;

int			ft_atoi(char *str);
MILLISEC	get_time(void);
MILLISEC	get_gap(MILLISEC start);
int			timer(MILLISEC start, MILLISEC gap, t_philo *philo);

int			parsing(int ac, char **av, t_info *info);

t_philo		*setting_philo(t_info *info);

int			print_action(int action, t_philo *philo, t_info *info);

int			eating(t_philo *philo);
int			sleeping(t_philo *philo);

int			checking_dish(t_philo *philo);
int			checking_alive(t_philo *philo);
int			checking_all(t_philo *philos);

int			someone_dead(t_info *info);

void		destroy_mutex(t_info *info, t_philo *philos);
void		free_all(t_info *info, t_philo *philos, pthread_t *chairs);

#endif
