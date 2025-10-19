/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 19:32:20 by cbitca            #+#    #+#             */
/*   Updated: 2025/08/31 19:32:22 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_forks(t_philo *philo)
{
	if (!philo->l_fork->__data.__lock && !philo->r_fork->__data.__lock)
		return (1);
	return (0);	
}

void	eatting(t_philo *philo, t_data *data)
{
	pthread_mutex_lock(philo->l_fork);
	print_log(FORK, philo, data);
	pthread_mutex_lock(philo->r_fork);
	print_log(FORK, philo, data);
	philo->meals++;
	philo->last_meal = current_time();
	print_log(EAT, philo, data);
	usleep(data->time_eat * 1000);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo, t_data *data)
{
	print_log(SLEEP, philo, data);
	usleep(data->time_sleep * 1000);
}

void	thinking(t_philo *philo, t_data *data)
{
	print_log(THINK, philo, data);
	while (!check_forks(philo))
		usleep(1);
}