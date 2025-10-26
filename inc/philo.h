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

// Error message.
# define ERROR "Error\n"
# define ERR_ARG_NUM "Wrong number of arguments.\n"
# define ERR_ARG_WRG "The arguments contain, wrong value.\n"

// Log message.
# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DEAD "died\n"

typedef struct s_data
{
	int				n_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				n_time;
	int				flag_n_time;
	long			start;
	int				dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	write;
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

// philo
void	smart_usleep(long ms, t_philo *philo, t_data *data);
int	check_forks(t_philo *philo);
void	eatting(t_philo *philo, t_data *data);
void	sleeping(t_philo *philo, t_data *data);
void	thinking(t_philo *philo, t_data *data);

// monitor
void	monitor(t_philo *philo, t_data *data);
int	check_meals(t_philo *philo, t_data *data);
int	check_dead(t_philo *philo, t_data *data);

// Utilits
int		ft_atoi(const char *nptr);
int		check_argv(char **argv);
int		check_data(t_data *data);
long	current_time(void);
void	print_log(char *str, t_philo *philo, t_data *data);


// Init
int	init_data(char **argv, t_data *data);
void	init_philo(t_philo *philo, t_data *data);
int	init_thread(t_philo *philo, t_data *data);

// Exit
int		print_error(char *error);
int		exit_proc(t_data *data, char *error);

#endif