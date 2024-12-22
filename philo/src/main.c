/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumartin <lumartin@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 18:38:04 by lumartin          #+#    #+#             */
/*   Updated: 2024/12/22 21:01:03 by lumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long get_timestamp(long start_time)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000) - start_time;
}

void initialize_philo(t_philo **philo, int id, int *args, t_philo **philosophers, int num_philosophers)
{
    *philo = malloc(sizeof(t_philo));
    (*philo)->id = id;
    (*philo)->time_to_eat = args[1];
    (*philo)->time_to_sleep = args[2];
    (*philo)->time_to_die = args[3];
    (*philo)->meals = args[4];
    (*philo)->time_without_eating = 0;

    pthread_mutex_init(&(*philo)->left_fork, NULL);
    pthread_mutex_init(&(*philo)->right_fork, NULL);

    // Asignar tenedores en una mesa redonda
    if (id == 1)
    {
        (*philo)->left_fork = philosophers[num_philosophers - 1]->right_fork;
        (*philo)->right_fork = philosophers[id]->left_fork;
    }
    else if (id == num_philosophers)
    {
        (*philo)->left_fork = philosophers[id - 2]->right_fork;
        (*philo)->right_fork = philosophers[0]->left_fork;
    }
    else
    {
        (*philo)->left_fork = philosophers[id - 1]->right_fork;
        (*philo)->right_fork = philosophers[id]->left_fork;
    }
}

void *philosopher(void *arg)
{
    t_philo *philo;
    int meals = 0;
    long last_meal_time;
    t_data *data;

    philo = (t_philo *)arg;
    data = philo->data;
    last_meal_time = get_timestamp(data->start_time);

    while (1)
    {
        pthread_mutex_lock(&data->death_mutex);
        if (data->dead)
        {
            pthread_mutex_unlock(&data->death_mutex);
            break;
        }
        pthread_mutex_unlock(&data->death_mutex);

        // Pensar
        printf("%ld %d is thinking\n", get_timestamp(data->start_time), philo->id);

        // Tomar tenedores
        pthread_mutex_lock(&philo->left_fork);
        printf("%ld %d has taken a fork\n", get_timestamp(data->start_time), philo->id);
        pthread_mutex_lock(&philo->right_fork);
        printf("%ld %d has taken a fork\n", get_timestamp(data->start_time), philo->id);

        // Comer
        printf("%ld %d is eating\n", get_timestamp(data->start_time), philo->id);
        last_meal_time = get_timestamp(data->start_time);
        usleep(philo->time_to_eat * 1000);
        meals++;

        if (philo->meals != -1 && meals >= philo->meals)
        {
            printf("%ld %d has finished eating\n", get_timestamp(data->start_time), philo->id);
            break;
        }

        // Soltar tenedores
        pthread_mutex_unlock(&philo->left_fork);
        pthread_mutex_unlock(&philo->right_fork);

        // Dormir
        printf("%ld %d is sleeping\n", get_timestamp(data->start_time), philo->id);
        usleep(philo->time_to_sleep * 1000);

        // Verificar si ha muerto
        if (get_timestamp(data->start_time) - last_meal_time >= philo->time_to_die)
        {
            pthread_mutex_lock(&data->death_mutex);
            if (!data->dead)
            {
                printf("%ld %d died\n", get_timestamp(data->start_time), philo->id);
                data->dead = 1;
            }
            pthread_mutex_unlock(&data->death_mutex);
            break;
        }
    }

    pthread_mutex_unlock(&philo->left_fork);
    pthread_mutex_unlock(&philo->right_fork);
    free(philo);
    return (NULL);
}

void initialize_threads(int num_philosophers, int *args)
{
    pthread_t *threads;
    t_philo **philosophers;
    t_data data;
    int i;

    data.dead = 0;
    data.start_time = get_timestamp(0);
    pthread_mutex_init(&data.death_mutex, NULL);

    threads = malloc(sizeof(pthread_t) * num_philosophers);
    philosophers = malloc(sizeof(t_philo *) * num_philosophers);

    for (i = 0; i < num_philosophers; i++)
    {
        initialize_philo(&philosophers[i], i + 1, args, philosophers, num_philosophers);
        philosophers[i]->data = &data;
        pthread_create(&threads[i], NULL, philosopher, philosophers[i]);
    }

    for (i = 0; i < num_philosophers; i++)
    {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&data.death_mutex);
    free(threads);
    free(philosophers);
}

int main(int argc, char **argv)
{
    int *args;

    if (argc != 5 && argc != 6)
    {
        printf("Error: Wrong number of arguments\n");
        return (1);
    }

    args = malloc(sizeof(int) * 5);
    args[0] = atoi(argv[1]); // Número de filósofos
    args[1] = atoi(argv[2]); // Tiempo para comer
    args[2] = atoi(argv[3]); // Tiempo para dormir
    args[3] = atoi(argv[4]); // Tiempo para morir
    if (argc == 6)
        args[4] = atoi(argv[5]); // Número de comidas
    else
        args[4] = -1;

    initialize_threads(args[0], args);
    free(args);
    return (0);
}
