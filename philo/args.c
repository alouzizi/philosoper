/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 06:46:13 by alouzizi          #+#    #+#             */
/*   Updated: 2022/07/03 04:19:34 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i++]) <= 0)
		{
			printf("Erorre\n");
			return (1);
		}
	}
	return (0);
}

int	get_data_by_args(char **av, t_data **philo, int ac)
{
	int	i;

	if (ac == 6)
		(*philo)->nb_eat = ft_atoi(av[--ac]);
	if (ac == 5)
	{
		(*philo)->nb_philo = ft_atoi(av[1]);
		(*philo)->t_die = ft_atoi(av[2]);
		(*philo)->t_eat = ft_atoi(av[3]);
		(*philo)->t_sleep = ft_atoi(av[4]);
	}
	i = (*philo)->nb_philo;
	(*philo)->forks = malloc(sizeof(pthread_mutex_t) * (*philo)->nb_philo);
	if (!(*philo)->forks)
		return (1);
	while (i--)
		pthread_mutex_init(&(*philo)->forks[i], NULL);
	return (0);
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

time_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
