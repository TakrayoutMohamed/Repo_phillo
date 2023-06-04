/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphilo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:31:00 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/03 16:36:18 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIB_PHILO_H__
# define __LIB_PHILO_H__
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# define AVAILABLE		1
# define NO_AVAILABLE	0
# define THINK			1
# define EAT			2
# define SLEEP			3

typedef struct s_list
{
	int				nbr;
	pthread_mutex_t	own_fork;
	int				status;
	struct s_list	*next;
} t_list;

t_list	*ft_lstnew(int nbr, pthread_mutex_t mutex);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
#endif
