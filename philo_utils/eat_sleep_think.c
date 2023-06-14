/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:57:07 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/14 22:56:59 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

static bool	eat(t_list *lst)
{
	if (pthread_mutex_lock(&lst->own_fork) != 0)
		return (printf("\nERROR : locking the mutex 1 eat()\n"), false);
	print_state('f', lst, right_now() - lst->start_simul);
	if (pthread_mutex_lock(&lst->next->own_fork))
		return (printf("\nERROR : locking the mutex 2 eat()\n"), false);
	print_state('f', lst, right_now() - lst->start_simul);
	print_state('e', lst, right_now() - lst->start_simul);
	pthread_mutex_lock(&lst->args->lock_time);
	lst->last_meal = right_now();
	pthread_mutex_unlock(&lst->args->lock_time);
	ft_usleep(lst->args->time_to_eat);
	if (pthread_mutex_unlock(&lst->next->own_fork) != 0)
		return (printf("\nERROR : unlocking the mutex 2 eat()\n"), false);
	if (pthread_mutex_unlock(&lst->own_fork) != 0)
		return (printf("\nERROR : unlocking the mutex 1 eat()\n"), false);
	return (true);
}

static void	sleep_think(t_list *lst)
{
	ft_usleep(lst->args->time_to_sleep);
	print_state('s', lst, right_now() - lst->start_simul);
	print_state('t', lst, right_now() - lst->start_simul);
}

/*return true if the philosopher still need to eat and false if 
* an error occurred
*/
static bool	eaten_enough(t_list *lst)
{
	if (lst->args->number_time_to_eat >= lst->nbr_time_eaten)
		return (true);
	pthread_mutex_lock(&lst->args->lock_decrement);
	(lst->args->end_simul)--;
	pthread_mutex_unlock(&lst->args->lock_decrement);
	return (true);
}

void	*eat_sleep_think(void *args)
{
	t_list	*lst;

	lst = (t_list *)args;
	if (lst->nbr & 1)
		usleep(100);
	while (1)
	{
		if (!eat(lst))
			return (NULL);
		pthread_mutex_lock(&lst->args->lock_increment);
		lst->nbr_time_eaten++;
		pthread_mutex_unlock(&lst->args->lock_increment);
		sleep_think(lst);
		if (lst->args->number_time_to_eat)
		{
			if (!eaten_enough(lst))
				return (NULL);
		}
	}
	return (NULL);
}
