/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   procces.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:49:44 by cbitca            #+#    #+#             */
/*   Updated: 2025/08/31 19:49:45 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void*	routine(void* arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	if (data->n_philo == 1)
		usleep(data->time_die * 1000);
	while (1)
	{
		if (check_forks(philo))
		{
			eatting(philo, data);
			sleeping(philo, data);
		}
		else
			thinking(philo, data);
	}
	pthread_exit(NULL);
	(void)data;
}

int	procces(t_data *data)
{
	t_philo	philo[MAX_PHILO];

	init_philo(&philo[0], data);
	if (init_thread(&philo[0], data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
