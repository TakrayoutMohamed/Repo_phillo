/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:12:57 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/13 23:23:26 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*templst;

	temp = (*lst);
	*lst = (*lst)->next;
	temp->next = NULL;
	if (lst && del)
	{
		templst = *lst;
		while (templst)
		{
			temp = templst->next;
			ft_lstdelone(templst, del);
			templst = NULL;
			templst = temp;
		}
		*lst = NULL;
	}
}
