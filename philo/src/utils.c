/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 19:22:41 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/27 18:26:09 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void	test(void)
{
	write(1, "HOLAA\n", 6);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	nb;

	i = 0;
	s = 1;
	nb = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\f' || str[i] == '\r'
		|| str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i++] - '0');
	}
	return ((int)(s * nb));
}

int	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->death_mutex);
	if (philo->data->dead)
	{
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (1);
	}
	pthread_mutex_lock(&philo->meal_mutex);
	if (get_time() - philo->last_meal_time >= philo->time_to_die)
	{
		if (!philo->data->dead)
		{
			printf("%ld %d died\n", get_time() - philo->data->start_time,
				philo->id);
			philo->data->dead = 1;
		}
		pthread_mutex_unlock(&philo->meal_mutex);
		pthread_mutex_unlock(&philo->data->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->meal_mutex);
	pthread_mutex_unlock(&philo->data->death_mutex);
	return (0);
}

int	get_time(void)
{
	static struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

void	print_message(const char *str, t_philo *philosopher)
{
	if (!check_death(philosopher))
	{
		pthread_mutex_lock(&philosopher->data->death_mutex);
		printf("%ld %d %s\n", get_time() - philosopher->data->start_time,
			philosopher->id, str);
		pthread_mutex_unlock(&philosopher->data->death_mutex);
	}
}

int	check_arguments(int argc, char **argv, int *args)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Wrong number of arguments\n");
		printf("Usage: ./philo [number_of_philosophers] [time_to_die] [time_to_eat] \
		[time_to_sleep] [number_of_times_each_philosopher_must_eat]\n");
		return (0);
	}
	if (ft_atoi(argv[1]) <= 0 || ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0 || (argc == 6 && ft_atoi(argv[5]) <= 0))
	{
		printf("Error: Invalid arguments\n");
		return (0);
	}
	args[0] = ft_atoi(argv[1]);
	args[1] = ft_atoi(argv[2]);
	args[2] = ft_atoi(argv[3]);
	args[3] = ft_atoi(argv[4]);
	args[4] = -1;
	if (argc == 6)
		args[4] = ft_atoi(argv[5]);
	return (1);
}
