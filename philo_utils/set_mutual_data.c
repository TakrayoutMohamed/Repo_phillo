/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mutual_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:58:57 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/14 21:51:42 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

t_args	*set_mutual_data(int argc, char **argv)
{
	t_args	*args;

	args = (t_args *)malloc(sizeof(t_args));
	if (!args)
		return (printf("ERROR : alloct_args in set_metual_data().\n"), NULL);
	if (pthread_mutex_init(&args->lock_output, NULL))
		return (printf("ERROR : initia mutex in set_metual_data() 1.\n"), NULL);
	if (pthread_mutex_init(&args->lock_increment, NULL))
		return (printf("ERROR : initia mutex in set_metual_data() 2.\n"), NULL);
	if (pthread_mutex_init(&args->lock_decrement, NULL))
		return (printf("ERROR : initia mutex in set_metual_data() 2.\n"), NULL);
	if (pthread_mutex_init(&args->lock_time, NULL))
		return (printf("ERROR : initia mutex in set_metual_data() 2.\n"), NULL);
	args->nbr_philosophers = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->end_simul = args->nbr_philosophers;
	args->is_dead = false;
	if (argc == 6)
		args->number_time_to_eat = ft_atoi(argv[5]);
	else
		args->number_time_to_eat = 0;
	return (args);
}
