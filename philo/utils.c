/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alouzizi <alouzizi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:48:35 by alouzizi          #+#    #+#             */
/*   Updated: 2022/07/02 10:12:53 by alouzizi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int time)
{
	time_t	dtime;

	dtime = get_time();
	while (get_time() - dtime <= time)
		usleep(1);
}

void	free_all(t_philo **philo)
{
	t_philo	*temp;

	temp = *philo;
	free(temp->t);
	free(temp->data->forks);
	free(temp->data);
	free(temp);
	*philo = NULL;
}
