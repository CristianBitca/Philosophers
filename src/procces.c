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

void	eat(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	printf("Philo nr %d is eating\n", philo->id);
	usleep(data->time_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	printf("Philo nr %d is sleeping\n", philo->id);
	usleep(data->time_sleep * 1000);
}

void	thinking(t_philo *philo)
{
	while (1)
	{
		printf("Philos nr %d is thinking\n", philo->id);
		if (!philo->l_fork || !philo->r_fork)
			usleep(1);
		else
			break;
	}
}

void*	routine(void* arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	while (1)
	{
		if (philo->l_fork || philo->r_fork)
			eat(philo, data);
		else
			thinking(philo);
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
