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
		free(data->forks);
	free(data);
	if (error)
		print_error(error);
	return (EXIT_FAILURE);
}
