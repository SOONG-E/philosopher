/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yujelee <yujelee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:38:33 by yujelee           #+#    #+#             */
/*   Updated: 2022/10/07 14:50:40 by yujelee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <semaphore.h>
# include <stdlib.h>
#include <stdio.h>

# define MILLISEC	unsigned long long

# define FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3
# define DIE	4

typedef struct s_info
{
	int				num;
	int				*philo_id;
	MILLISEC		time_die;
	MILLISEC		time_eat;
	MILLISEC		time_sleep;
	int				required_eat;
	MILLISEC		start_time;
	sem_t			*forks;
	sem_t			*speaker;
}	t_info;

typedef struct s_philo
{
	int				num;
	MILLISEC		last_eating;
	int				amount_eat;
	struct s_info	*info;
	sem_t			*forks;
	sem_t			*pen;
	char			*pen_num;
}	t_philo;

int			ft_atoi(char *str);
char		*ft_itoa(int num);
int			parsing(int ac, char **av, t_info *info);
t_philo		*setting_philo(t_info *info);

void		kill_them(t_info *info, int num);
void		wait_philos(t_info *info);

void		separate_philo(t_philo *philo);

void		checking_dish(t_philo *philo);
int			checking_alive(t_philo *philo);
void		print_action(int action, t_philo *philo, t_info *info);

void		eating(t_philo *philo);
void		sleeping(t_philo *philo);

MILLISEC	get_time(void);
MILLISEC	get_gap(MILLISEC start);
void		timer(MILLISEC start, MILLISEC gap);

void		free_all(t_info *info, t_philo *philos);

#endif
