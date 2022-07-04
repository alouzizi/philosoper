/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:48:12 by alouzizi          #+#    #+#             */
/*   Updated: 2022/07/04 20:00:27 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	creat_philo(t_philo **t)
{
	int			i;
	pthread_t	thread;

	i = (*t)->data->nb_philo;
	(*t)->n_eat = 0;
	(*t)->p = malloc(sizeof(pthread_mutex_t));
	if (!(*t)->p)
		return (1);
	(*t)->t = malloc(sizeof(t_mutex) * i);
	if (!(*t)->t)
		return (1);
	pthread_mutex_init(&(*t)->p[0], NULL);
	i = -1;
	while (++i < (*t)->data->nb_philo)
	{
		(*t)->t[i].nb_eat = 0;
		if (pthread_create(&(*t)->t[i].p, NULL, &routin, *t) != 0)
			return (1);
		usleep(200);
	}
	pthread_create(&thread, NULL, &manger, *t);
	return ((int)pthread_join(thread, NULL));
}

void	*manger(void *arg)
{
	int		i;
	t_philo	*thraed;

	thraed = (t_philo *)arg;
	i = 0;
	while (1)
	{
		if (i == thraed->data->nb_philo)
			i = 0;
		if (get_time() - thraed->t[i].eat > thraed->data->t_die)
		{
			pthread_mutex_lock(&thraed->p[0]);
			printf("%ld philo %d died\n", get_time()
				- thraed->t[i].creat, i + 1);
			return (0);
		}
		if (thraed->arc == 6 && thraed->n_eat >= (thraed->data->nb_eat
				* thraed->data->nb_philo))
			return (0);
		i++;
	}
	return (0);
}

void	*routin(void *arg)
{
	t_philo		*philo;
	int			j;
	static int	i = 0;

	philo = (t_philo *)arg;
	i++;
	j = i;
	philo->t[j - 1].creat = get_time();
	philo->t[j - 1].eat = philo->t[j - 1].creat;
	while (1)
	{
		pthread_mutex_lock(&philo->data->forks[j - 1]);
		pthread_mutex_lock(&philo->p[0]);
		printf("%ld philo %d has taken a fork\n", get_time()
			- philo->t[j - 1].creat, j);
		pthread_mutex_unlock(&philo->p[0]);
		philo_routin(&philo, j);
	}
}

void	philo_routin(t_philo **philo, int j)
{
	pthread_mutex_lock(&(*philo)->data->forks[j % (*philo)->data->nb_philo]);
	pthread_mutex_lock(&(*philo)->p[0]);
	(*philo)->n_eat++;
	printf("%ld philo %d has taken a fork\n", get_time()
		- (*philo)->t[j - 1].creat, j);
	printf("%ld philo %d is eating\n", get_time() - (*philo)->t[j - 1].creat, j);
	pthread_mutex_unlock(&(*philo)->p[0]);
	(*philo)->t[j - 1].eat = get_time();
	ft_sleep((*philo)->data->t_eat);
	pthread_mutex_unlock(&(*philo)->data->forks[j % (*philo)->data->nb_philo]);
	pthread_mutex_unlock(&(*philo)->data->forks[j -1]);
	pthread_mutex_lock(&(*philo)->p[0]);
	printf("%ld philo %d is sleping\n", get_time()
		- (*philo)->t[j - 1].creat, j);
	pthread_mutex_unlock(&(*philo)->p[0]);
	ft_sleep((*philo)->data->t_sleep);
	pthread_mutex_lock(&(*philo)->p[0]);
	printf("%ld philo %d is thinking\n", get_time()
		- (*philo)->t[j - 1].creat, j);
	pthread_mutex_unlock(&(*philo)->p[0]);
}

int	main(int ac, char **av)
{
	t_philo	*t;
	int		i;

	i = 1;
	if (ac == 6 || ac == 5)
	{
		if (check_args(av))
			return (1);
		t = malloc(sizeof(t_philo));
		t->data = malloc(sizeof(t_data));
		if (!t->data || !t)
			return (1);
		if (get_data_by_args(av, &t->data, ac))
			return (1);
		t->arc = ac;
		i = creat_philo(&t);
	}
	return (i);
}
