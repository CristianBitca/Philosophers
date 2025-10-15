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
	int				n_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_time;
	long			start;
	int				dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	think;
	pthread_mutex_t	death;
	pthread_mutex_t	eat;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				meals;
	long			last_meal;
	pthread_t		thread;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	t_data			*data;
}	t_philo;

// procces
int	procces(t_data *data);
void*	routine(void* arg);

// Utilits
int		ft_atoi(const char *nptr);
int		check_argv(char **argv);
int		check_data(t_data *data);

// Init
t_data	*init_data(char **argv);
void	init_philo(t_philo *philo, t_data *data);
int	init_thread(t_philo *philo, t_data *data);

// Exit
int		print_error(char *error);
int		exit_proc(t_data *data, char *error);

#endif