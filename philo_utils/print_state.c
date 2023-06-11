/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:57:21 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/11 19:26:00 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

void	print_state(char c, t_list *lst)
{
	if (!lst->args->printable)
		return ;
	else if (c == 'f')
		printf("%ld %d has taken a fork\n", right_now() - lst->start_simul, lst->nbr);
	else if (c == 'F')//need to remove this one at the end it is only for debugging purpuse
		printf("%ld %d has taken next fork\n", right_now() - lst->start_simul, lst->nbr);
	else if (c == 'e')
		printf("%ld %d is eating\n", right_now() - lst->start_simul, lst->nbr);
	else if (c == 's')
		printf("%ld %d is sleeping\n", right_now() - lst->start_simul, lst->nbr);
	else if (c == 't')
		printf("%ld %d is thinking\n", right_now() - lst->start_simul, lst->nbr);
}
