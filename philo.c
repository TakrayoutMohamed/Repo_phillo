/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:35:52 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/10 16:57:14 by mohtakra         ###   ########.fr       */
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
		printf("|side struct |\n");
		printf("\t||nbr_philosophers   = %lu\n",lst->args->nbr_philosophers);
		printf("\t||number_time_to_eat = %lu\n",lst->args->number_time_to_eat);
		printf("\t||time_to_die  	   = %lu\n",lst->args->time_to_die);
		printf("\t||time_to_eat  	   = %lu\n",lst->args->time_to_eat);
		printf("\t||time_to_sleep      = %lu\n",lst->args->time_to_sleep);
		printf("|end side struct |\n");
			lst = lst->next;
		if (lst->nbr == breaker)
			break ;
	}
	printf("\n----}\n");
	lst = tmp;
	printf("\n");
}


/*return the number of millisecond in a given number of seconds*/
unsigned long	convert_sec_to_millisec(unsigned long sec)
{
	return ((unsigned long) sec * 1000);
}

/*return the number of millisecond in a given number of microsecond*/
unsigned long	convert_microsec_to_millisec(unsigned long microsec)
{
	return ((unsigned long) microsec / 1000);
}

/*return the number of microsecond in a given number of millisecond*/
unsigned long	convert_millisec_to_microsec(unsigned long millisec)
{
	return ((unsigned long) millisec * 1000);
}

/*return the time of now in seconds since the Epoch(Jan. 1, 1970 at 00:00:00)
* in milliseconds
*/
unsigned long right_now(void)
{
	struct timeval	tv;
	// unsigned long	t_now;

	gettimeofday(&tv, NULL);
	// t_now = convert_sec_to_millisec(tv.tv_sec);
	// t_now += convert_microsec_to_millisec(tv.tv_usec);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

// void	eat(t_list *lst, double ts)
// {

// }

/*sleep a proccess or a thread for some time in milliseconds*/
void ft_usleep(unsigned long unbr)
{
    unsigned long   time;
    unsigned long   start;

    time = (unbr * 95) / 100;
    start = right_now();
    usleep(time * 1000);
    while(1)
    {
        if (right_now() - start >= unbr)
            break ;
        usleep(90);
    }
}

int	ft_atoi(char *str)
{
	int	negative;
	int	nbr;

	negative = 1;
	nbr = 0;
	if (str)
	{
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				negative = -1;
			str++;
		}
		while (*str)
		{
			nbr = nbr * 10 + *str - 48;
			str++;
		}
	}
	return (nbr * negative);
}

t_args	*set_struct(int argc, char **argv)
{
	t_args	*args;

	args = (t_args *)malloc(sizeof(t_args));
	args->nbr_philosophers = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->printable = 1;
	if (argc == 6)
		args->number_time_to_eat = ft_atoi(argv[5]);
	else
		args->number_time_to_eat = 0;
	return (args);
}

void	print_state(char c, t_list *lst)
{
	if (!lst->args->printable)
		return ;
	else if (c == 'f')
		printf("\n%ld %d has taken a fork\n", right_now() - lst->start_simul, lst->nbr);
	else if (c == 'e')
		printf("\n%ld %d is eating\n", right_now() - lst->start_simul, lst->nbr);
	else if (c == 's')
		printf("\n%ld %d is sleeping\n", right_now() - lst->start_simul, lst->nbr);
	else if (c == 't')
		printf("\n%ld %d  is thinking\n", right_now() - lst->start_simul, lst->nbr);
}

void	*sleep_think_eat(void *args)
{
	t_list	*lst;

	lst = (t_list*)args;
	lst->last_meal = right_now();
	lst->start_simul = right_now();
	if (lst->nbr & 1)
		usleep(100);
	while (1)
	{
		pthread_mutex_lock(&lst->own_fork);
		print_state('f', lst);
		pthread_mutex_lock(&lst->next->own_fork);
		print_state('f', lst);
		print_state('e', lst);
		ft_usleep(lst->args->time_to_eat);
		lst->last_meal = right_now();
		lst->nbr_time_eaten += 1;
		pthread_mutex_unlock(&lst->next->own_fork);
		pthread_mutex_unlock(&lst->own_fork);
		print_state('s', lst);
		ft_usleep(lst->args->time_to_sleep);
		print_state('t', lst);
		if (lst->args->number_time_to_eat)
		{
			if (lst->args->number_time_to_eat < lst->nbr_time_eaten)
			{
				printf("\noooooooooooooooooooooooooo nbr = %d\n",lst->nbr);
				break ;
			}
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t		*thread;
	t_args			*args;
	t_list			*lst;
	int				i;

	i = 0;
	lst = NULL;
	args = set_struct(argc, argv);
	if (!is_valid_parsing(argc, argv, args))
	{
		return (free(args), 0);
	}
	while ((unsigned long)i < args->nbr_philosophers)
	{
		thread = (pthread_t *)malloc(sizeof(pthread_t));
		ft_lstadd_back(&lst, ft_lstnew(i + 1));
		ft_lstlast(lst)->args = args;
		if (pthread_create(thread, NULL, &sleep_think_eat, ft_lstlast(lst)))
		{
			printf("there is an error while creating the thread nbr %d\n",i+1);
			return (1);
		}
		if (pthread_detach(*thread))
		{
			printf("there is an error while detaching the thread nbr %d\n",i+1);
			return (1);
		}
		free(thread);
		i++;
	}
	ft_lstlast(lst)->next = lst;
	i = 0;
	while (lst)
	{
		if (right_now() - lst->last_meal >= lst->args->time_to_die)
		{
			args->printable = 0;
			printf("\n%ld %d died\n", right_now() - lst->start_simul, lst->nbr);
			break ;
		}
		usleep(200);
		lst = lst->next;
	}
	// printf("\n************here is the list***************\n");
	// print_lst(lst);
	// exit(0);
	// here i will free all the alocated data
	return (0);
}
