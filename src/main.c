/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:48:44 by cbitca            #+#    #+#             */
/*   Updated: 2025/08/31 17:48:46 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (check_argv(argc, &argv[1]))
		return (free(data), EXIT_FAILURE);
	else if (init_data(argv, data))
		return (exit_proc(data, NULL));
	else if (procces(data))
		return(free_forks(data), exit_proc(data, NULL));
	free_forks(data);
	free(data);
	return (EXIT_SUCCESS);
}
