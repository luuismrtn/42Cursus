/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 03:33:00 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/27 18:18:47 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	p_takes_forks(t_philo *philo)
{
	if (philo->data->num_philosophers == 1)
		return (2);
	if (philo->id % 2 == 0)
		pthread_mutex_lock(philo->right_fork);
	else
		pthread_mutex_lock(philo->left_fork);
	if (!check_death(philo))
		print_message("has taken a fork", philo);
	if (philo->id % 2 == 0)
	{
		if (pthread_mutex_lock(philo->left_fork) != 0)
			return (pthread_mutex_unlock(philo->right_fork), 1);
		if (!check_death(philo))
			print_message("has taken a fork", philo);
	}
	else
	{
		if (pthread_mutex_lock(philo->right_fork) != 0)
			return (pthread_mutex_unlock(philo->left_fork), 1);
		if (!check_death(philo))
			print_message("has taken a fork", philo);
	}
	return (0);
}

void	p_sleep(t_philo *philo, int time)
{
	int	st_time;

	print_message("is sleeping", philo);
	st_time = get_time();
	while ((get_time() - st_time) < time && !philo->data->dead)
		usleep(50);
}

int	p_eat(t_philo *philo)
{
	print_message("is eating", philo);
	pthread_mutex_lock(&philo->meal_mutex);
	usleep(philo->time_to_eat * 1000);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

void	p_think(t_philo *philo)
{
	print_message("is thinking", philo);
}
