/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:35:52 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/06 23:11:21 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libphilo.h"

void	print_lst(t_list *lst)
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
		lst = lst->next;
		if (lst->nbr == breaker)
			break ;
	}
	printf("\n----}\n");
	lst = tmp;
	printf("\n");
}


/*return the number of millisecond in a given number of seconds*/
double	convert_sec_to_millisec(int sec)
{
	return ((double) sec * 1000);
}

/*return the number of millisecond in a given number of microsecond*/
double	convert_microsec_to_millisec(int microsec)
{
	return ((double) microsec / 1000);
}

/*return the number of microsecond in a given number of millisecond*/
double	convert_millisec_to_microsec(int millisec)
{
	return ((double) millisec * 1000);
}

/*return the time of now in seconds since the Epoch(Jan. 1, 1970 at 00:00:00)
* in milliseconds
*/
double right_now(void)
{
	struct timeval	tv;
	double			t_now;

	gettimeofday(&tv, NULL);
	t_now = convert_sec_to_millisec(tv.tv_sec);
	t_now += convert_microsec_to_millisec(tv.tv_usec);
	return (t_now);
}

// void	eat(t_list *lst, double ts)
// {

// }

void	*sleep_think_eat(void *args)
{
	t_list	*lst;
	// struct timeval t;

	lst = (t_list*)args;
	// gettimeofday(&t, NULL);
	// printf("here is the test for the use of sec to milli : %ld s = %f millisec\n",t.tv_sec, convert_sec_to_millisec(t.tv_sec));
	// printf("here is the test for the use of micro to milli : %d us = %f millisec\n",t.tv_usec, convert_microsec_to_millisec(t.tv_usec));
	lst->last_meal = right_now();
	lst->start_simu = right_now();
	lst->status = AVAILABLE;
	// printf("the new last meal is %f \n",lst->last_meal);
	// sleep(2);
	if (lst->nbr % 2 != 0)
	{
		usleep(100);
	}
	while (right_now() - lst->last_meal <= 215 )
	{
		{
			// if (lst->status == AVAILABLE && lst->next->status == AVAILABLE)
			{
				pthread_mutex_lock(&lst->own_fork);
				// lst->status = NO_AVAILABLE;
				printf("\n%f %d has taken his fork\n", right_now() - lst->last_meal, lst->nbr);
				// if (lst->next->status == AVAILABLE)
				{
					pthread_mutex_lock(&lst->next->own_fork);
					printf("\n%f %d has taken next fork\n", right_now() - lst->last_meal, lst->nbr);
					// lst->next->status = NO_AVAILABLE;
					printf("\n%f %d has START eating\n", right_now() - lst->last_meal, lst->nbr);
					usleep(convert_millisec_to_microsec(100));
					lst->last_meal = right_now();
					printf("\n%f %d has END eating\n", right_now() - lst->last_meal, lst->nbr);
					// lst->status = AVAILABLE;
					pthread_mutex_unlock(&lst->own_fork);
					// lst->next->status = AVAILABLE;
					pthread_mutex_unlock(&lst->next->own_fork);

					printf("\n%f %d has START sleeping\n", right_now() - lst->last_meal, lst->nbr);
					usleep(convert_millisec_to_microsec(100));
					printf("\n%f %d has END sleeping\n", right_now() - lst->last_meal, lst->nbr);
					printf("\n%f %d has START thinking\n", right_now() - lst->last_meal, lst->nbr);
					usleep(convert_millisec_to_microsec(200));
					printf("\n%f %d has END thinking\n", right_now() - lst->last_meal, lst->nbr);
				}
			}
		}
		// while (lst->status != AVAILABLE && lst->next->status != AVAILABLE);
		// while (lst->status == NO_AVAILABLE && lst->next->status == NO_AVAILABLE);
	}
	printf("\n%f %d died\n", right_now() - lst->last_meal, lst->nbr);
	// lst->status = NO_AVAILABLE;
	exit(1);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t		thread[5];
	int				i;
	pthread_mutex_t	mutex[5];
	t_list			*lst;

	i = 0;
	lst = NULL;
	(void) argc;
	(void) argv;
	// printf("the address of the i = %p\n",&i);
	//here check the parsing is ok or not
	while (i < 5)
	{
		ft_lstadd_back(&lst, ft_lstnew(i + 1, mutex[i]));
		if (pthread_create(&thread[i], NULL, &sleep_think_eat, ft_lstlast(lst)) != 0)
		{
			printf("there is an error while creating the thread nbr %d\n",i+1);
			return (1);
		}
		if (lst->nbr % 2 && lst->nbr > 1)
			usleep(40);
		i++;
	}
	ft_lstlast(lst)->next = lst;
	i = 0;
	while (i < 5)
	{
		// printf("the %d thread begin \n", i);
		if (pthread_join(thread[i], NULL) != 0)
		{
			printf("there is an error while joining the thread nbr %d\n",i+1);
			return (1);
		}
		// printf("the %d thread end \n", i);
		i++;
	}
	// printf("\n************here is the list***************\n");
	// print_lst(lst);
}
