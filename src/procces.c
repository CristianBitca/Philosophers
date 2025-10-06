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

	data = (t_data *)arg;
	pthread_exit(NULL);
	(void)data;
}

void	procces(t_data *data)
{
	// t_philo	*tmp;
	t_philo	philo[MAX_PHILO];
	pthread_mutex_t	forks[MAX_PHILO];

	init_forks(&forks[1], data);
	init_philo(&philo[1], data);
	// tmp = &philo[1];
	// while (tmp->id && tmp->id <= data->n_of_philo)
	// {
	// 	printf("%d\n", tmp->id);
	// 	tmp++;
	// }
}
