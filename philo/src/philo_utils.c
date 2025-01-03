/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 02:13:48 by lumartin          #+#    #+#             */
/*   Updated: 2025/01/03 02:23:36 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	release_forks(t_philo *philo, int right_idx, int left_idx)
{
	pthread_mutex_lock(&philo->data->forks_mutex);
	philo->data->s_forks[right_idx] = 0;
	philo->data->s_forks[left_idx] = 0;
	pthread_mutex_unlock(&philo->data->forks_mutex);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}

int	take_fork(t_philo *philo, pthread_mutex_t *fork, int fork_idx)
{
	if (check_death(philo))
		return (1);
	pthread_mutex_lock(&philo->data->forks_mutex);
	if (philo->data->s_forks[fork_idx] == 0)
	{
		philo->data->s_forks[fork_idx] = 1;
		pthread_mutex_unlock(&philo->data->forks_mutex);
		pthread_mutex_lock(fork);
		print_message("has taken a fork", philo);
		return (1);
	}
	pthread_mutex_unlock(&philo->data->forks_mutex);
	return (0);
}

void	release_fork(t_philo *philo, pthread_mutex_t *fork, int fork_idx)
{
	pthread_mutex_lock(&philo->data->forks_mutex);
	philo->data->s_forks[fork_idx] = 0;
	pthread_mutex_unlock(&philo->data->forks_mutex);
	pthread_mutex_unlock(fork);
}

void	assign_forks(t_philo *philo, pthread_mutex_t **first_fork,
		pthread_mutex_t **second_fork)
{
	if (philo->id % 2 == 0)
	{
		*first_fork = philo->right_fork;
		*second_fork = philo->left_fork;
	}
	else
	{
		*first_fork = philo->left_fork;
		*second_fork = philo->right_fork;
	}
}

void	assign_indices(t_philo *philo, int *first_idx, int *second_idx)
{
	if (philo->id % 2 == 0)
	{
		*first_idx = get_fork_index(philo->id, philo->data->num_philosophers,
				1);
		*second_idx = get_fork_index(philo->id, philo->data->num_philosophers,
				0);
	}
	else
	{
		*first_idx = get_fork_index(philo->id, philo->data->num_philosophers,
				0);
		*second_idx = get_fork_index(philo->id, philo->data->num_philosophers,
				1);
	}
}
