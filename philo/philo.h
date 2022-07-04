/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:48:35 by alouzizi          #+#    #+#             */
/*   Updated: 2022/07/04 19:47:01 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

typedef struct data{
	pthread_mutex_t	*forks;
	int				nb_philo;
	int				t_eat;
	int				t_die;
	int				t_sleep;
	int				nb_eat;
}t_data;

typedef struct mutex{
	pthread_t	p;
	time_t		eat;
	time_t		creat;
	int			nb_eat;
}t_mutex;

typedef struct philo{
	pthread_mutex_t	*p;
	t_data			*data;
	t_mutex			*t;
	int				n_eat;
	int				arc;
}t_philo;

int		check_args(char **av);
int		ft_atoi(const char *str);
int		get_data_by_args(char **av, t_data **philo, int ac);
int		creat_philo(t_philo **t);
void	*routin(void *arg);
time_t	get_time(void);
void	ft_sleep(int time);
void	*manger(void *arg);
void	philo_routin(t_philo **philo, int j);
#endif