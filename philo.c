/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:35:52 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/05 22:11:48 by mohtakra         ###   ########.fr       */
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


/*return the number of milisecond in a given number of seconds*/
double	convert_sec_to_millisec(int sec)
{
	return ((double) sec * 1000);
}

/*return the number of milisecond in a given number of microsecond*/
double	convert_microsec_to_millisec(int microsec)
{
	return ((double) microsec / 1000);
}

void	*sleep_think_eat(void *args)
{
	t_list	*lst;
	struct timeval t;

	lst = (t_list*)args;
	gettimeofday(&t, NULL);
	// printf("here is the test for the use of sec to milli : %ld s = %f millisec\n",t.tv_sec, convert_sec_to_millisec(t.tv_sec));
	// printf("here is the test for the use of micro to milli : %d us = %f millisec\n",t.tv_usec, convert_microsec_to_millisec(t.tv_usec));
	lst->last_meal = convert_sec_to_millisec(t.tv_sec) + convert_microsec_to_millisec(t.tv_usec);
	// printf("the new last meal is %f \n",lst->last_meal);
	// sleep(2);
	while (convert_sec_to_millisec(t.tv_sec) + convert_microsec_to_millisec(t.tv_usec) - lst->last_meal <= 1 )
	{
		pthread_mutex_lock(&lst->own_fork);
		pthread_mutex_lock(&lst->next->own_fork);
		printf("\nthe philo %d is START eating usec = %f currtime = %d\n",lst->nbr,lst->last_meal, t.tv_usec);
		usleep(200 / 1000);
		gettimeofday(&t, NULL);
		lst->last_meal = convert_sec_to_millisec(t.tv_sec) + convert_microsec_to_millisec(t.tv_usec);
		printf("\nthe philo %d is END eating usec = %f currtime = %d\n",lst->nbr,lst->last_meal, t.tv_usec);
		pthread_mutex_unlock(&lst->next->own_fork);
		pthread_mutex_unlock(&lst->own_fork);
		printf("\nthe philo %d is START sleeping usec = %f currtime = %d\n",lst->nbr,lst->last_meal, t.tv_usec);
		usleep(1 / 1000);
		printf("\nthe philo %d is END sleeping usec = %f currtime = %d\n",lst->nbr,lst->last_meal, t.tv_usec);
		printf("\nthe philo %d is START thinking usec = %f currtime = %d\n",lst->nbr,lst->last_meal, t.tv_usec);
		usleep(1 / 1000);
		printf("\nthe philo %d is END thinking usec = %f currtime = %d\n",lst->nbr,lst->last_meal, t.tv_usec);
		gettimeofday(&t, NULL);
	}
	printf("\nthe philo %d is daying usec = %f currtime = %d\n",lst->nbr,lst->last_meal, t.tv_usec);
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
	while (i < 5)
	{
		ft_lstadd_back(&lst, ft_lstnew(i + 1, mutex[i]));
		if (pthread_create(&thread[i], NULL, &sleep_think_eat, ft_lstlast(lst)) != 0)
		{
			printf("there is an error while creating the thread nbr %d\n",i+1);
			return (1);
		}
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
