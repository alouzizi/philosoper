/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:57:14 by alouzizi          #+#    #+#             */
/*   Updated: 2022/07/03 08:40:36 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int ac, char **av)
{
	t_philo	*philo;

	if (ac == 6 || ac == 5)
	{
		philo = malloc(sizeof(t_philo));
		if (!philo)
			exit(1);
		philo->ac = ac;
		philo->index = 0;
		philo->n_eat = 0;
		sem_unlink("/sem");
		sem_unlink("/prin");
		check_args(av);
		get_data_by_args(av, &philo, ac);
		philo->ids = malloc(sizeof(int) * philo->data.nb_philo);
		if (!philo->ids)
			exit(1);
		creat_philo(&philo);
		kill_all_process(philo);
	}
	exit(1);
}

void	kill_all_process(t_philo *philo)
{
	int	k;
	int	i;
	int	protect;

	protect = waitpid(-1, &i, 0);
	k = philo->data.nb_philo;
	if (i == 0 || protect == -1)
	{
		while (k--)
			kill(philo->ids[k], SIGINT);
	}
	exit(0);
}
