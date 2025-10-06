/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 17:49:39 by cbitca            #+#    #+#             */
/*   Updated: 2025/08/31 17:49:40 by cbitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_PHILO 200

# define ERROR "Error\n"
# define ERR_ARG_NUM "Wrong number of arguments.\n"
# define ERR_ARG_WRG "The arguments contain, wrong value.\n"

typedef struct s_data
{
	int		n_of_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		n_time;
	int		*dead;
}	t_data;

typedef struct s_philo
{
	int				id;
	pthread_t	thread;
	pthread_mutex_t	*mtx_philo;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*meal;
	t_data *data;
}	t_philo;

typedef struct s_procces
{
	/* data */
}	t_procces;

// procces
void	procces(t_data *data);

// Utilits
int	ft_atoi(const char *nptr);
int	check_argv(char **argv);
int	check_data(t_data *data);

// Init
t_data	*init_data(char **argv);
void	init_forks(pthread_mutex_t *fork, t_data *data);
void	init_philo(t_philo *philo, t_data *data);

// Exit
int	print_error(char *error);
int	exit_proc(t_data *data, char *error);

#endif