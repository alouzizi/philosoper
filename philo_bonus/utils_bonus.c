/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 06:20:41 by alouzizi          #+#    #+#             */
/*   Updated: 2022/07/03 08:40:56 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i++]) <= 0)
		{
			printf("Erorre\n");
			exit(1);
		}
	}
}

void	get_data_by_args(char **av, t_philo **philo, int ac)
{
	t_data	*data;

	(*philo)->forks = malloc(sizeof(sem_t));
	if (!(*philo)->forks)
		exit(1);
	(*philo)->print = malloc(sizeof(sem_t));
	if (!(*philo)->print)
		exit(1);
	data = &(*philo)->data;
	if (ac == 6)
		data->nb_eat = ft_atoi(av[--ac]);
	if (ac == 5)
	{
		data->nb_philo = ft_atoi(av[1]);
		data->t_die = ft_atoi(av[2]);
		data->t_eat = ft_atoi(av[3]);
		data->t_sleep = ft_atoi(av[4]);
	}
}

void	creat_philo(t_philo	**t)
{
	int	i;
	int	id;
	int	j;

	j = 0;
	i = ((*t)->data.nb_philo / 2);
	if (i < 1)
	{
		printf("%d philo %d died\n", 0, i + 1);
		exit(1);
	}
	(*t)->print = sem_open("/prin", O_CREAT | O_EXCL, S_IRWXU, 1);
	(*t)->forks = sem_open("/sem", O_CREAT | O_EXCL, S_IRWXU, i);
	id = 1;
	i = (*t)->data.nb_philo;
	while (id != 0 && i--)
	{
		id = fork();
		if (id > 0)
			(*t)->ids[j++] = id;
		if (id == 0)
			routin(*t);
		if (id != 1)
			(*t)->index++;
	}
}

void	routin(t_philo *philo)
{
	pthread_t	thread;
	int			i;

	philo->time = get_time();
	philo->f_eat = get_time();
	philo->n_eat = 0;
	philo->index += 1;
	i = philo->index;
	pthread_create(&thread, NULL, &manger, philo);
	while (philo->data.nb_philo >= 0)
	{
		sem_wait(philo->forks);
		print(philo, i);
		philo->n_eat++;
		philo->time = get_time();
		ft_sleep(philo->data.t_eat);
		sem_post(philo->forks);
		sem_wait(philo->print);
		printf("%ld philo %d is sleping\n", get_time() - philo->f_eat, i);
		sem_post(philo->print);
		ft_sleep(philo->data.t_sleep);
		sem_wait(philo->print);
		printf("%ld philo %d is thinking\n", get_time() - philo->f_eat, i);
		sem_post(philo->print);
	}
}

int	ft_atoi(const char *str)
{
	int	s;
	int	i;
	int	n;

	i = 0;
	s = 1;
	n = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= 48 && str[i] <= 57)
			n = n * 10 + (str[i] - 48);
		else
			return (0);
		i++;
	}
	return (n * s);
}
