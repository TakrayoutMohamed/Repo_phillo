/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphilo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:31:00 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/07 22:55:07 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIB_PHILO_H__
# define __LIB_PHILO_H__
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include "./parsing/libparsing.h"
# define AVAILABLE		1
# define NO_AVAILABLE	0
# define THINK			1
# define EAT			2
# define SLEEP			3

typedef struct s_list
{
	int				nbr;
	double			last_meal;
	double			start_simu;
	int				status;
	pthread_mutex_t	own_fork;
	struct s_list	*next;
} t_list;

typedef struct s_args
{
	int	nbr_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_time_to_eat;
} t_args;

t_list	*ft_lstnew(int nbr, pthread_mutex_t mutex);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
#endif
