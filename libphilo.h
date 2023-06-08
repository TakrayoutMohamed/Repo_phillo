/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphilo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:31:00 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/08 17:01:31 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPHILO_H
# define LIBPHILO_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# define AVAILABLE		1
# define NO_AVAILABLE	0

typedef struct s_args
{
	unsigned long	nbr_philosophers;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	number_time_to_eat;
} t_args;

typedef struct s_list
{
	int				nbr;
	unsigned long	last_meal;
	int				nbr_time_to_eat;
	int				status;
	pthread_mutex_t	own_fork;
	t_args			*args;
	struct s_list	*next;
} t_list;


# include "./parsing/libparsing.h"

t_list	*ft_lstnew(int nbr, pthread_mutex_t mutex);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));


#endif
