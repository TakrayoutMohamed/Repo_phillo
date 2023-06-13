/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:35:52 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/13 23:27:38 by mohtakra         ###   ########.fr       */
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

bool	create_linked_list(t_list **lst, t_args *args)
{
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < args->nbr_philosophers)
	{
		tmp = ft_lstnew(i + 1);
		if (!tmp)
		{
			printf("ERROR : creation of the new node nbr %d\n", i + 1);
			return (false);
		}
		ft_lstadd_back(lst, tmp);
		ft_lstlast(*lst)->args = args;
		i++;
	}
	ft_lstlast(*lst)->next = *lst;
	return (true);
}

bool	create_threads(t_list *lst, t_args *args)
{
	pthread_t		thread;
	int				i;

	i = 0;
	while (i < args->nbr_philosophers)
	{
		lst->start_simul = right_now();
		lst->last_meal = right_now();
		if (pthread_create(&thread, NULL, &eat_sleep_think, lst))
		{
			printf("ERROR : creation of the new thread %d\n", i + 1);
			return (false);
		}
		if (pthread_detach(thread))
		{
			printf("ERROR : detach the thread %d\n", i + 1);
			return (false);
		}
		lst = lst->next;
		i++;
	}
	return (true);
}

// static void leakss(void)
// {
// 	system("leaks philo");
// }

int	main(int argc, char **argv)
{
	t_args	*args;
	t_list	*lst;

	// atexit(leakss);//8888ddddddd
	lst = NULL;
	args = set_mutual_data(argc, argv);
	if (!args)
		return (1);
	if (!is_valid_parsing(argc, argv, args))
		return (free(args), 1);
	if (!create_linked_list(&lst, args))
		return (ft_lstclear(&lst, del), free(args), 1);
	if (!create_threads(lst, args))
		return (free(args), ft_lstclear(&lst, del), 1);
	while (args->end_simul > 0)
	{
		if (right_now() - lst->last_meal > (unsigned long) args->time_to_die)
			return (print_state('d', lst, right_now() - lst->last_meal), 0);
		lst = lst->next;
		usleep(10);
	}
	return (print_state('k', lst, right_now() - lst->last_meal), 0);
}

// printf("\n************here is the list***************\n");
// print_lst(lst);
// free(args);
// ft_lstclear(&lst, del);