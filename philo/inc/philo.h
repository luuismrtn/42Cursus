/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:20:20 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/22 20:43:49 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				time_to_eat;
	int				time_to_sleep;
	int				time_to_die;
	int				meals;
	int				time_without_eating;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	pthread_mutex_t	death_mutex;
	int				dead;
	long			start_time;
}					t_data;

int					ft_atoi(const char *str);

#endif
