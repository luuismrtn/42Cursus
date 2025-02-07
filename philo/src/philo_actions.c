/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 03:33:00 by lumartin          #+#    #+#             */
/*   Updated: 2025/02/07 18:18:20 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	p_sleep(t_philo *philo)
{
	long	start_time;

	start_time = get_time();
	print_message("is sleeping", philo);
	while ((get_time() - start_time) < philo->time_to_sleep
		&& !philo->data->dead)
	{
		usleep(100);
		if (check_death(philo))
			break ;
	}
}

int	p_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_message("has taken a fork", philo);
	if (philo->data->num_philosophers == 1)
	{
		usleep(philo->time_to_die * 1000);
		return (2);
	}
	pthread_mutex_lock(philo->right_fork);
	print_message("has taken a fork", philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	print_message("is eating", philo);
	usleep(philo->time_to_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

void	p_think(t_philo *philo)
{
	print_message("is thinking", philo);
}
