/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 19:03:24 by cbitca            #+#    #+#             */
/*   Updated: 2025/09/23 19:03:25 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	free_forks(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}

// Print an error.
int	print_error(char *error)
{
	printf(ERROR);
	printf("%s", error);
	return (EXIT_FAILURE);
}

// Exit the procces and free all data, if the string error wasn't specifed doesn't execute print_error function.
int	exit_proc(t_data *data, char *error)
{
	if (!data->forks)
		free_forks(data);
	free(data);
	if (error)
		print_error(error);
	return (EXIT_FAILURE);
}
