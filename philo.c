/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:35:52 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/11 20:50:31 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libphilo.h"
/*
static void	print_lst(t_list *lst)
{
	t_list	*tmp;
	int		breaker = lst->nbr;

	tmp = lst;
	printf("\n{----\n");
	while (lst != NULL)
	{
		printf("| nbr    = %d ",lst->nbr);
		printf("| mutex  = %p ",&(lst->own_fork));
		printf("| status = %d |\n",lst->status);
		printf("|side struct |\n");
		printf("\t||nbr_philosophers   = %lu\n",lst->args->nbr_philosophers);
		printf("\t||number_time_to_eat = %lu\n",lst->args->number_time_to_eat);
		printf("\t||time_to_die  	   = %lu\n",lst->args->time_to_die);
		printf("\t||time_to_eat  	   = %lu\n",lst->args->time_to_eat);
		printf("\t||time_to_sleep      = %lu\n",lst->args->time_to_sleep);
		printf("|end side struct |\n");
			lst = lst->next;
		if (lst->nbr == breaker)
			break ;
	}
	printf("\n----}\n");
	lst = tmp;
	printf("\n");
}
*/

int	main(int argc, char **argv)
{
	pthread_t		*thread;
	t_args			*args;
	t_list			*lst;
	unsigned int	i;

	// atexit(leakss);//8888ddddddd
	i = 0;
	lst = NULL;
	args = set_mutual_data(argc, argv);
	if (!is_valid_parsing(argc, argv, args))
	{
		return (free(args), 0);
	}
	while (i < args->nbr_philosophers)
	{
		thread = (pthread_t *)malloc(sizeof(pthread_t));
		if (!thread)
		{
			printf("we could not allocate to the thread in main()");
			exit(EXIT_FAILURE);
		}
		ft_lstadd_back(&lst, ft_lstnew(i + 1));
		ft_lstlast(lst)->args = args;
		if (pthread_create(thread, NULL, &eat_sleep_think, ft_lstlast(lst)))
		{
			printf("there is an error while creating the thread nbr %d\n",i+1);
			return (1);
		}
		if (pthread_detach(*thread))
		{
			printf("there is an error while detaching the thread nbr %d\n",i+1);
			return (1);
		}
		free(thread);
		// ptr = ptr->next;
		i++;
	}
	ft_lstlast(lst)->next = lst;
	i = 0;
	while (lst)
	{
		if (right_now() - lst->last_meal > lst->args->time_to_die)
		{
			// args->printable = 0;
			printf("\n%ld %d died\n", right_now() - lst->last_meal, lst->nbr);
			break ;
		}
		if (args->end_simul <= 0)
			break ;
		lst = lst->next;
		usleep(10);
	}
	// printf("\n************here is the list***************\n");
	// print_lst(lst);
	// exit(0);
	// here i will free all the alocated data
	free(args);
	ft_lstclear(&lst, del);
	return (0);
}
