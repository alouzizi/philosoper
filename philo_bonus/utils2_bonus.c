/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 08:32:29 by alouzizi          #+#    #+#             */
/*   Updated: 2022/07/02 11:55:36 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_sleep(int time)
{
	time_t	dtime;

	dtime = get_time();
	while (get_time() - dtime <= time)
		usleep(1);
}

void	*manger(void *arg)
{
	t_philo			*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (get_time() - philo->time > philo->data.t_die)
		{
			sem_wait(philo->print);
			printf("%ld philo %d died\n", get_time() - philo->time,
				philo->index);
			exit(0);
		}
		if (philo->ac == 6 && philo->n_eat == (philo->data.nb_eat + 1))
			exit(0);
	}
}

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print(t_philo *philo, int i)
{
	sem_wait(philo->print);
	printf("%ld philo %d has taken a fork\n", get_time() - philo->f_eat, i);
	printf("%ld philo %d has taken a fork\n", get_time() - philo->f_eat, i);
	printf("%ld philo %d is eating\n", get_time() - philo->f_eat, i);
	sem_post(philo->print);
}
