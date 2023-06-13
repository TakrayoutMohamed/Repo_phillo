/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:15:40 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/13 23:23:41 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

t_list	*ft_lstnew(int nbr)
{
	t_list			*p;

	p = (t_list *)malloc(sizeof(t_list));
	if (!p)
		return (printf("ERROR : allocation new lst in ft_lstnew()\n"), NULL);
	p->nbr = nbr;
	if (pthread_mutex_init(&p->own_fork, NULL))
	{
		printf("ERROR : initialisation of mutex in ft_lstnew() nbr %d\n", nbr);
		return (NULL);
	}
	p->next = NULL;
	return (p);
}
