/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:20:20 by lumartin          #+#    #+#             */
/*   Updated: 2025/02/07 18:18:40 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				meals;
	pthread_mutex_t	meal_mutex;
	long			last_meal_time;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	pthread_mutex_t	death_mutex;
	int				dead;
	long			start_time;
	int				num_philosophers;
	pthread_mutex_t	forks_mutex;

}					t_data;

// PHILO_ACTIONS
void				p_sleep(t_philo *philo);
int					p_eat(t_philo *philo);
void				p_think(t_philo *philo);

// UTILS
void				init_forks(pthread_mutex_t *forks, int num_philosophers);
void				thread_create_and_join(pthread_t *threads,
						t_philo **philosophers, int num_philosophers);
void				free_all(t_philo **philosophers, pthread_mutex_t *forks,
						pthread_t *threads, int *args);
void				init_data(t_data *data, int num_philosophers);
int					ft_atoi(const char *str);
void				cleanup_philosophers(t_philo **philosophers,
						int num_philosophers);
int					check_death(t_philo *philo);
int					get_time(void);
int					check_arguments(int argc, char **argv, int *args);
void				print_message(const char *str, t_philo *philosopher);

// MAIN
void				*philosopher(void *arg);

#endif
