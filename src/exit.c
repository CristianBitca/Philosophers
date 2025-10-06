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

int	print_error(char *error)
{
	printf(ERROR);
	printf("%s", error);
	return (EXIT_FAILURE);
}

int	exit_proc(t_data *data, char *error)
{
	free(data);
	if (error)
		print_error(error);
	return (EXIT_FAILURE);
}
