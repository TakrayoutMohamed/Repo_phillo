/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 13:15:40 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/08 16:59:55 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

/*return the number of millisecond in a given number of seconds*/
static unsigned long	convert_sec_to_millisec(unsigned long sec)
{
	return ((unsigned long) sec * 1000);
}

/*return the number of millisecond in a given number of microsecond*/
static unsigned long	convert_microsec_to_millisec(unsigned long microsec)
{
	return ((unsigned long) microsec / 1000);
}

/*return the time of now in seconds since the Epoch(Jan. 1, 1970 at 00:00:00)
* in milliseconds
*/
static unsigned long right_now(void)
{
	struct timeval	tv;
	unsigned long	t_now;

	gettimeofday(&tv, NULL);
	t_now = convert_sec_to_millisec(tv.tv_sec);
	t_now += convert_microsec_to_millisec(tv.tv_usec);
	return (t_now);
}

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
	p->last_meal = right_now();
	p->status	= AVAILABLE;
	p->next = NULL;
	return (p);
}
