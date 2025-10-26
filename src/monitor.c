/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 20:14:17 by cbitca            #+#    #+#             */
/*   Updated: 2025/10/15 20:14:19 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_philo *philo, t_data *data)
{
	if (philo->meals == data->n_time)
	{
		pthread_mutex_lock(&data->death);
		data->dead = 1;
		pthread_mutex_unlock(&data->death);
		return (0);
	}
	return (1);
}

int	check_dead(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(&data->death);
	if (data->dead == 1)
	{
		pthread_mutex_unlock(&data->death);
		pthread_mutex_unlock(&data->write);
		pthread_mutex_unlock(&data->eat);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (0);
	}
	pthread_mutex_unlock(&data->death);
	return (1);
}

void	monitor(t_philo *philo, t_data *data)
{
	int	i;

	if (data->n_philo <= 1)
	{
		print_log(DEAD, philo, data);
		data->dead = 1;
	}
	while (!data->dead)
	{
		i = 0;
		while (i < data->n_philo && !data->dead)
		{
			if ((current_time() - philo[i].last_meal) >= data->time_die
				&& philo[i].last_meal)
			{
				if (philo[i].meals != data->n_time)
					print_log(DEAD, philo, data);
				data->dead = 1;
			}
			i++;
		}
		usleep(1000);
	}
}
