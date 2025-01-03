/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 03:33:00 by lumartin          #+#    #+#             */
/*   Updated: 2025/01/03 02:26:17 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	get_fork_index(int philosopher_id, int total_philosophers, int is_right)
{
	if (is_right)
		return ((philosopher_id - 1 + total_philosophers) % total_philosophers);
	return ((philosopher_id - 2 + total_philosophers) % total_philosophers);
}

int	p_takes_forks(t_philo *philo)
{
	pthread_mutex_t	*first_fork;
	pthread_mutex_t	*second_fork;
	int				first_idx;
	int				second_idx;

	assign_forks(philo, &first_fork, &second_fork);
	assign_indices(philo, &first_idx, &second_idx);
	if (philo->data->num_philosophers == 1)
		return (2);
	while (!take_fork(philo, first_fork, first_idx))
		usleep(100);
	while (!take_fork(philo, second_fork, second_idx))
	{
		if (check_death(philo))
		{
			release_fork(philo, first_fork, first_idx);
			return (1);
		}
		usleep(100);
	}
	return (0);
}

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
	long	start_time;
	int		right_idx;
	int		left_idx;

	start_time = get_time();
	right_idx = get_fork_index(philo->id, philo->data->num_philosophers, 1);
	left_idx = get_fork_index(philo->id, philo->data->num_philosophers, 0);
	print_message("is eating", philo);
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	while ((get_time() - start_time) < philo->time_to_eat)
	{
		if (check_death(philo))
		{
			release_forks(philo, right_idx, left_idx);
			return (0);
		}
		usleep(100);
	}
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	release_forks(philo, right_idx, left_idx);
	return (1);
}

void	p_think(t_philo *philo)
{
	print_message("is thinking", philo);
}
