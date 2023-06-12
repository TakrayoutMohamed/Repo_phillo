/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:57:07 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/12 22:45:46 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

static bool	eat(t_list *lst)
{
	if (pthread_mutex_lock(&lst->own_fork) != 0)
	{
		printf("\nERROR : locking the mutex 1 eat() nbr %d\n",lst->nbr);
		return (false);
	}
	print_state('f', lst);
	if (pthread_mutex_lock(&lst->next->own_fork))
	{
		printf("\nERROR : locking the mutex 2 eat() nbr %d\n",lst->nbr);
		return (false);
	}
	print_state('F', lst);//here need to change the F with f or just remove it
	print_state('e', lst);
	lst->last_meal = right_now();
	ft_usleep(lst->args->time_to_eat);
	if (pthread_mutex_unlock(&lst->next->own_fork) != 0)
	{
		printf("\nERROR : unlocking the mutex 2 eat() nbr %d\n",lst->nbr);
		return (false);
	}
	if (pthread_mutex_unlock(&lst->own_fork) != 0)
	{
		printf("\nERROR : unlocking the mutex 1 eat() nbr %d\n",lst->nbr);
		return (false);
	}
	return (true);
}

static void	sleep_think(t_list *lst)
{
	print_state('s', lst);
	ft_usleep(lst->args->time_to_sleep);
	print_state('t', lst);
}

/*return true if the philosopher still need to eat and false if 
**an error occurred
*/
static bool	eaten_enough(t_list *lst)
{
	pthread_mutex_t	mutex;

	if (lst->args->number_time_to_eat >= lst->nbr_time_eaten)
		return (true);
	if (pthread_mutex_init(&mutex, NULL))
	{
		printf("\nERROR : locking mutex eaten_enough() nbr %d\n",lst->nbr);
		return (false);
	}
	// if (pthread_mutex_lock(&mutex) != 0)
	// {
	// 	printf("\nERROR : locking mutex eaten_enough() nbr %d\n",lst->nbr);
	// 	return (false);
	// }
		(lst->args->end_simul)--;
		printf("\noooooooooooooooooooooooooo end simu = %d nbr = %d\n", lst->args->end_simul, lst->nbr);
		//at end need to remove the above line
	// if (pthread_mutex_unlock(&mutex) != 0)
	// {
	// 	printf("\nERROR : unlocking mutex eaten_enough() nbr %d\n",lst->nbr);
	// 	return (false);
	// }
	return (true);
}

void	*eat_sleep_think(void *args)
{
	t_list	*lst;

	lst = (t_list*)args;	
	if (lst->nbr & 1)
		usleep(100);
	while (1)
	{
		if (!eat(lst))
			return (NULL);
		lst->nbr_time_eaten = lst->nbr_time_eaten + 1;
		sleep_think(lst);
		if (lst->args->number_time_to_eat)
		{
			if (!eaten_enough(lst))
				return (NULL);
		}
	}
	return (NULL);
}
