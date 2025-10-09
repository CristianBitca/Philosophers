/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:18:07 by cbitca            #+#    #+#             */
/*   Updated: 2025/09/23 19:18:10 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_time(t_data *data)
{
	struct timeval	tv;

	data->start = gettimeofday(&tv, NULL);
}

void	init_forks(t_data *data)
{
	pthread_mutex_t		forks[MAX_PHILO];
	int					i;

	i = 1;
	data->forks = forks;
	while (i <= data->n_philo)
		pthread_mutex_init(&forks[i++], NULL);
}

t_data	*init_data(char **argv)
{
	t_data		*data;

	data = malloc(sizeof(t_data));
	data->n_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_time = ft_atoi(argv[5]);
	else
		data->n_time = -1;
	init_time(data);
	data->dead = 0;
	init_forks(data);
	pthread_mutex_init(&data->write, NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->meal_check, NULL);
	return (data);
}

void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 1;
	while (philo && i <= data->n_philo)
	{
		philo->id = i;
		philo->data = data;
		philo++;
		i++;
	}
}
