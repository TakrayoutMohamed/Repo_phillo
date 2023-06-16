/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:57:21 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/13 23:26:56 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

/*print's an output depend on the given character "c" 
* d : died
* k : end of the simulation prints nothinig
* f : has taken a fork
* e : eating
* s : sleeping
* t : thinking
*/
void	print_state(char c, t_list *lst, unsigned long time)
{
	pthread_mutex_lock(&lst->args->lock_output);
	if (c != 'd' && c != 'k')
		pthread_mutex_unlock(&lst->args->lock_output);
	if (c == 'd')
	{
		usleep(200);
		printf("%ld %d died\n", time, lst->nbr);
	}
	else if (c == 'f')
		printf("%ld %d has taken a fork\n", time, lst->nbr);
	else if (c == 'e')
		printf("%ld %d is eating\n", time, lst->nbr);
	else if (c == 's')
		printf("%ld %d is sleeping\n", time, lst->nbr);
	else if (c == 't')
		printf("%ld %d is thinking\n", time, lst->nbr);
}
