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
	if (argc == 5 || argc == 6)
	{
		if (check_argv(&argv[1]))
			return (exit_proc(NULL, NULL));
		if (init_data(argv, data))
			return (exit_proc(NULL, NULL));
		if (check_data(data))
			return (exit_proc(data, NULL));
		if (procces(data))
			return(exit_proc(data, NULL));
	}
	else
		return (print_error(ERR_ARG_NUM));
	exit_proc(data, NULL);
	printf("Done\n");
	return (EXIT_SUCCESS);
}
