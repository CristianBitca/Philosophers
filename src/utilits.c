/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 18:18:30 by cbitca            #+#    #+#             */
/*   Updated: 2025/08/31 18:18:32 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	check_argv(char **argv)
{
	int	i;

	while (*argv)
	{
		i = 0;
		while (*argv[i])
		{
			if ('0' <= *argv[i] && '9' >= *argv[i])
				return (1);
			i++;
		}
		argv++;
	}
	return (0);
}

int	check_data(t_data *data)
{
	if (data->n_philo > 200 || data->n_philo == 0)
		return (print_error(ERR_ARG_WRG));
	if (data->time_die <= 60)
		return (print_error(ERR_ARG_WRG));
	if (data->time_eat <= 60)
		return (print_error(ERR_ARG_WRG));
	if (data->time_sleep <= 60)
		return (print_error(ERR_ARG_WRG));
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || ('\t' <= nptr[i] && '\r' >= nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while ('0' <= nptr[i] && '9' >= nptr[i])
	{
		result = result * 10 + nptr[i] - '0';
		i++;
	}
	return (result * sign);
}
