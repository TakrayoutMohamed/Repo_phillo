/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:15:40 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/11 19:40:37 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

t_list	*ft_lstnew(int nbr)
{
	t_list			*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
	{
		printf("we could not allocate to p in ft_lstnew()\n");
		exit(EXIT_FAILURE);
	}
	if (!p)
		return (NULL);
	p->nbr = nbr;
	if (pthread_mutex_init(&p->own_fork, NULL) != 0)
	{
		printf("there is an error while trying to init the mutex nbr %d\n",nbr);
		exit(EXIT_FAILURE);
	}
	p->last_meal = right_now();
	p->status	= AVAILABLE;
	p->next = NULL;
	return (p);
}
