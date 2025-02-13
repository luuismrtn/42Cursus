/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 03:33:00 by lumartin          #+#    #+#             */
/*   Updated: 2025/02/13 16:46:07 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	only_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo);
	smart_sleep(philo->time_to_die, philo);
}

void	p_sleep(t_philo *philo)
{
	long	start_time;

	start_time = get_time();
	print_message("is sleeping", philo);
	smart_sleep(philo->time_to_sleep, philo);
}

int	p_eat(t_philo *philo)
{
	if (philo->data->num_philosophers == 1)
		return (only_one_philo(philo), 2);
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	print_message("is eating", philo);
	smart_sleep(philo->time_to_eat, philo);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

void	smart_sleep(int time, t_philo *philo)
{
	long	start_time;

	start_time = get_time();
	while ((get_time() - start_time) < time && !philo->data->dead)
	{
		usleep(50);
		if (check_death(philo))
			break ;
	}
}

int	death_checker(t_philo **p, int num_philosophers)
{
	int	i;

	i = 0;
	while (1)
	{
		i = i % num_philosophers;
		pthread_mutex_lock(&p[i]->data->death_mutex);
		if (p[i]->data->dead)
			return (pthread_mutex_unlock(&p[i]->data->death_mutex), 0);
		pthread_mutex_lock(&p[i]->meal_mutex);
		if (get_time() - p[i]->last_meal_time >= p[i]->time_to_die
			&& !p[i]->data->dead)
		{
			printf("%ld %d died\n", get_time() - p[i]->data->start_time,
				p[i]->id);
			p[i]->data->dead = 1;
			return (pthread_mutex_unlock(&p[i]->meal_mutex),
				pthread_mutex_unlock(&p[i]->data->death_mutex), 0);
		}
		pthread_mutex_unlock(&p[i]->meal_mutex);
		pthread_mutex_unlock(&p[i]->data->death_mutex);
		smart_sleep(50, p[i]);
		i++;
	}
	return (0);
}
