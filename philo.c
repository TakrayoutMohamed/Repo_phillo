/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:35:52 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/04 18:11:25 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libphilo.h"

void	print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	printf("\n{----\n");
	while (lst != NULL)
	{
		printf("| nbr    = %d ",lst->nbr);
		printf("| mutex  = %p ",&(lst->own_fork));
		printf("| status = %d |\n",lst->status);
		lst = lst->next;
	}
	printf("\n----}\n");
	lst = tmp;
	printf("\n");
}

void	*sleep_think_eat(void *args)
{
	t_list	*lst = (t_list*)args;

	printf("\n| nbr    = %d ",lst->nbr);
	printf("| mutex  = %p ",&(lst->own_fork));
	printf("| status = %d |\n",lst->status);
	// write(1, "here is the function pointer ", 31);
	// printf("  %d \n",ft_lstsize(lst));
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t		thread[4];
	int				i;
	pthread_mutex_t	mutex[4];
	t_list			*lst;
	
	i = 0;
	lst = NULL;
	(void) argc;
	(void) argv;
	// printf("the address of the i = %p\n",&i);
	//here check the parsing is ok or not
	while (i < 4)
	{
		ft_lstadd_back(&lst, ft_lstnew(i + 1, mutex[i]));
		if (pthread_create(&thread[i], NULL, &sleep_think_eat, ft_lstlast(lst)) != 0)
		{
			printf("there is an error while creating the thread nbr %d\n",i+1);
			return (1);
		}
		i++;
	}
	// ft_lstlast(lst)->next = lst;
	i = 0;
	while (i < 4)
	{
		printf("the %d thread begin \n", i);
		if (pthread_join(thread[i], NULL) != 0)
		{
			printf("there is an error while joining the thread nbr %d\n",i+1);
			return (1);
		}
		printf("the %d thread end \n", i);
		i++;
	}
	printf("\n************here is the list***************\n");
	print_lst(lst);
}
