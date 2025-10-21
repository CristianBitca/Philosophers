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

// Check given arguments if all of the are numbers.
int	check_argv(char **argv)
{
	int	i;
	int	j;

	j = 0;
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if ('0' >= argv[j][i] && '9' <= argv[j][i])
				return (exit_proc(NULL, ERR_ARG_WRG));
			i++;
		}
		j++;
	}
	return (0);
}

// Check the struct data if all the number are not over the specified limits.
int	check_data(t_data *data)
{
	if (data->n_philo > 200 || data->n_philo <= 0)
		return (print_error(ERR_ARG_WRG));
	if (data->time_die <= 60)
		return (print_error(ERR_ARG_WRG));
	if (data->time_eat <= 60)
		return (print_error(ERR_ARG_WRG));
	if (data->time_sleep <= 60)
		return (print_error(ERR_ARG_WRG));
	return (0);
}

// Converts string to int
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

// Return current time.
long	current_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

// Print a log line in the terminal.
void	print_log(char *str, t_philo *philo, t_data *data)
{
	long	time;

	time = current_time() - data->start;
	pthread_mutex_lock(&data->write);
	printf("%ld %d %s", time, philo->id, str);
	pthread_mutex_unlock(&data->write);
}