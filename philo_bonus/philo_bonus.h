/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 08:23:44 by alouzizi          #+#    #+#             */
/*   Updated: 2022/07/03 08:33:54 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/time.h>
# include <sys/stat.h>
# include <semaphore.h>
# include <signal.h>

typedef struct data{
	int				nb_philo;
	int				t_eat;
	int				t_die;
	int				t_sleep;
	int				nb_eat;
}t_data;

typedef struct philo{
	t_data		data;
	sem_t		*forks;
	sem_t		*print;
	int			*ids;
	int			n_eat;
	int			index;
	int			ac;
	int			fraxte;
	time_t		time;
	time_t		last_eat;
	time_t		f_eat;
}t_philo;

void	check_args(char **av);
void	get_data_by_args(char **av, t_philo **philo, int ac);
void	creat_philo(t_philo	**t);
int		ft_atoi(const char *str);
time_t	get_time(void);
void	ft_sleep(int time);
void	routin(t_philo *philo);
void	*manger(void *arg);
void	kill_all_process(t_philo *philo);
void	print(t_philo *philo, int i);
#endif
