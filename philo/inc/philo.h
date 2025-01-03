/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:20:20 by lumartin          #+#    #+#             */
/*   Updated: 2025/01/03 02:25:25 by lumartin         ###   ########.fr       */
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
	int				*s_forks;

}					t_data;

// PHILO_ACTIONS
void				p_sleep(t_philo *philo);
int					p_eat(t_philo *philo);
void				p_think(t_philo *philo);
int					p_takes_forks(t_philo *philo);

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

int					get_fork_index(int philosopher_id, int total_philosophers,
						int is_right);
void				release_forks(t_philo *philo, int right_idx, int left_idx);
int					take_fork(t_philo *philo, pthread_mutex_t *fork,
						int fork_idx);
void				release_fork(t_philo *philo, pthread_mutex_t *fork,
						int fork_idx);
void				assign_forks(t_philo *philo, pthread_mutex_t **first_fork,
						pthread_mutex_t **second_fork);
void				assign_indices(t_philo *philo, int *first_idx,
						int *second_idx);

// MAIN
void				*philosopher(void *arg);

#endif
