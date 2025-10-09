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

	if (argc == 5 || argc == 6)
	{
		if (check_argv(argv))
			data = init_data(argv);
		if (check_data(data))
			return (exit_proc(data, NULL));
		procces(data);
	}
	else
		return (print_error(ERR_ARG_NUM));
	exit_proc(data, 0);
	printf("Done\n");
	return (EXIT_SUCCESS);
}
