/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lchee-ti <lchee-ti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:26:01 by lchee-ti          #+#    #+#             */
/*   Updated: 2024/12/15 17:33:04 by lchee-ti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void    *print_message(void *arg)
{
    int thread_id;

    thread_id = *((int *)arg);
    printf("Hello from thread %d!\n", thread_id);

    return (NULL);
}

int main(void)
{
    pthread_t   threads[5];
    int         thread_ids[5];
    int         i;

    i = 0;
    while (i < 5)
    {
        thread_ids[i] = i;
        
        if (pthread_create(&threads[i], NULL, print_message, &thread_ids[i]) != 0)
        {
            perror("Failed to create threads.");
            return (EXIT_FAILURE);
        }
        i++;
    }
    i = 0;
    while (i < 5)
    {
        if (pthread_join(threads[i], NULL) != 0)
        {
            perror("Failed to join threads.");
            return (EXIT_FAILURE);
        }
        i++;
    }
    return (EXIT_SUCCESS);
}
