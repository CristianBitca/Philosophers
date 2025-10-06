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

t_data	*init_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->n_of_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->n_time = ft_atoi(argv[5]);
	else
		data->n_time = -1;
	return (data);
}

void	init_forks(pthread_mutex_t *fork, t_data *data)
{
	int	i;

	i = 1;
	while (i <= data->n_of_philo)
	{
		pthread_mutex_init(&fork[i], NULL);
		i++;
	}
}

void	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 1;
	while (philo && i <= data->n_of_philo)
	{
		philo->id = i;
		philo->data = data;
		if(pthread_mutex_init(philo->write , NULL))
			printf("Mutex write was init for philo %d", philo->id);
		philo++;
		i++;
	}
}