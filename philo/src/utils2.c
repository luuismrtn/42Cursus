/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:12:58 by lumartin          #+#    #+#             */
/*   Updated: 2025/02/07 18:17:52 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	init_forks(pthread_mutex_t *forks, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_data(t_data *data, int num_philosophers)
{
	memset(data, 0, sizeof(t_data));
	pthread_mutex_init(&data->death_mutex, NULL);
	data->start_time = get_time();
	data->num_philosophers = num_philosophers;
}

void	thread_create_and_join(pthread_t *threads, t_philo **philosophers,
		int num_philosophers)
{
	int	i;

	i = -1;
	while (++i < num_philosophers)
		pthread_create(&threads[i], NULL, philosopher, philosophers[i]);
	i = -1;
	while (++i < num_philosophers)
		pthread_join(threads[i], NULL);
}

void	cleanup_philosophers(t_philo **philosophers, int num_philosophers)
{
	int	i;

	i = 0;
	while (i < num_philosophers)
	{
		pthread_mutex_destroy(philosophers[i]->left_fork);
		pthread_mutex_destroy(&philosophers[i]->meal_mutex);
		free(philosophers[i]);
		i++;
	}
}

void	free_all(t_philo **philosophers, pthread_mutex_t *forks,
		pthread_t *threads, int *args)
{
	free(philosophers);
	free(forks);
	free(threads);
	free(args);
}
