/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:15:40 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/06 19:43:25 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

t_list	*ft_lstnew(int nbr, pthread_mutex_t mutex)
{
	t_list	*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	p->nbr = nbr;
	if (pthread_mutex_init(&mutex, NULL) != 0)
	{
		printf("there is an error while trying to init the mutex nbr %d\n",nbr);
		return (NULL);
	}
	p->own_fork = mutex;
	p->status	= AVAILABLE;
	p->next = NULL;
	return (p);
}
