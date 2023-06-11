/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_sleep_think.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:57:07 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/11 19:29:25 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

static void	eat(t_list *lst)
{
	if (pthread_mutex_lock(&lst->own_fork) != 0)
	{
		printf("\nERROR : locking the mutex 1 eat() nbr %d\n",lst->nbr);
		exit(EXIT_FAILURE);
	}
	print_state('f', lst);
	if (pthread_mutex_lock(&lst->next->own_fork))
	{
		printf("\nERROR : locking the mutex 2 eat() nbr %d\n",lst->nbr);
		exit(EXIT_FAILURE);
	}
	print_state('F', lst);//here need to change the F with f or just remove it
	print_state('e', lst);
	ft_usleep(lst->args->time_to_eat);
	lst->last_meal = right_now();
	lst->nbr_time_eaten += 1;
	if (pthread_mutex_unlock(&lst->next->own_fork) != 0)
	{
		printf("\nERROR : unlocking the mutex 2 eat() nbr %d\n",lst->nbr);
		exit(EXIT_FAILURE);
	}
	if (pthread_mutex_unlock(&lst->own_fork) != 0)
	{
		printf("\nERROR : unlocking the mutex 1 eat() nbr %d\n",lst->nbr);
		exit(EXIT_FAILURE);
	}
}

static void	sleep_think(t_list *lst)
{
	print_state('s', lst);
	ft_usleep(lst->args->time_to_sleep);
	print_state('t', lst);
}

static void	eaten_enough(t_list *lst)
{
	if (!(lst->args->number_time_to_eat < lst->nbr_time_eaten))
		return ;
	if (pthread_mutex_lock(&lst->own_fork) != 0)
	{
		printf("\nERROR : locking mutex eaten_enough() nbr %d\n",lst->nbr);
		exit(EXIT_FAILURE);
	}
		lst->args->end_simul--;
		printf("\noooooooooooooooooooooooooo nbr = %d\n",lst->nbr);//at end need to remove this one
	if (pthread_mutex_unlock(&lst->own_fork) != 0)
	{
		printf("\nERROR : unlocking mutex eaten_enough() nbr %d\n",lst->nbr);
		exit(EXIT_FAILURE);
	}
}

void	*eat_sleep_think(void *args)
{
	t_list	*lst;

	lst = (t_list*)args;
	lst->last_meal = right_now();
	lst->start_simul = right_now();
	usleep(50);
	if (lst->nbr & 1)
		usleep(50);
	while (1)
	{
		eat(lst);
		sleep_think(lst);
		if (lst->args->number_time_to_eat)
			eaten_enough(lst);
	}
	return (NULL);
}
