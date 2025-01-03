/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:38:04 by lumartin          #+#    #+#             */
/*   Updated: 2025/01/03 02:25:33 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

static void	initialize_philosophers(t_philo **philosophers,
		pthread_mutex_t *forks, int *args, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philosophers)
	{
		philosophers[i] = malloc(sizeof(t_philo));
		if (!philosophers[i])
			return ;
		memset(philosophers[i], 0, sizeof(t_philo));
		philosophers[i]->id = i + 1;
		philosophers[i]->time_to_die = args[1];
		philosophers[i]->time_to_eat = args[2];
		philosophers[i]->time_to_sleep = args[3];
		philosophers[i]->meals = args[4];
		philosophers[i]->data = data;
		philosophers[i]->left_fork = &forks[i];
		if (i == data->num_philosophers - 1)
			philosophers[i]->right_fork = &forks[0];
		else
			philosophers[i]->right_fork = &forks[i + 1];
		pthread_mutex_init(&philosophers[i]->meal_mutex, NULL);
		i++;
	}
}

void	*philosopher(void *arg)
{
	t_philo	*philo;
	int		meals;

	philo = (t_philo *)arg;
	meals = 0;
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->meal_mutex);
	while (!check_death(philo))
	{
		p_think(philo);
		if (p_takes_forks(philo) == 2)
			usleep(philo->time_to_die * 1000);
		meals += p_eat(philo);
		if (philo->meals != -1 && meals >= philo->meals)
			return (NULL);
		p_sleep(philo);
	}
	return (NULL);
}

static void	destroy_forks(pthread_mutex_t *forks, int num_philosophers)
{
	int	i;

	i = -1;
	while (++i < num_philosophers)
		pthread_mutex_destroy(&forks[i]);
}

int	main(int argc, char **argv)
{
	t_philo			**philosophers;
	pthread_mutex_t	*forks;
	t_data			data;
	pthread_t		*threads;
	int				*args;

	args = malloc(sizeof(int) * 5);
	if (!check_arguments(argc, argv, args))
		return (free(args), 1);
	philosophers = malloc(sizeof(t_philo *) * args[0]);
	threads = malloc(sizeof(pthread_t) * args[0]);
	forks = malloc(sizeof(pthread_mutex_t) * args[0]);
	if (!philosophers || !threads || !forks)
		return (free(args), printf("Error: Memory allocation failed\n"), 1);
	init_forks(forks, args[0]);
	init_data(&data, args[0]);
	initialize_philosophers(philosophers, forks, args, &data);
	thread_create_and_join(threads, philosophers, args[0]);
	cleanup_philosophers(philosophers, args[0]);
	destroy_forks(forks, args[0]);
	pthread_mutex_destroy(&data.death_mutex);
	return (free_all(philosophers, forks, threads, args), 0);
}
