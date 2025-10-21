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

void	smart_usleep(long ms, t_philo *philo, t_data *data)
{
	long int	start;

	start = current_time();
	while (current_time() - start < ms && check_dead(philo, data))
		usleep(500);
}

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
	pthread_mutex_unlock(&data->eat);
	print_log(EAT, philo, data);
	smart_usleep(data->time_eat, philo, data);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	sleeping(t_philo *philo, t_data *data)
{
	if (!check_dead(philo, data))
		return ;
	print_log(SLEEP, philo, data);
	smart_usleep(data->time_sleep, philo, data);
}

void	thinking(t_philo *philo, t_data *data)
{
	if (!check_dead(philo, data))
		return ;
	print_log(THINK, philo, data);

}