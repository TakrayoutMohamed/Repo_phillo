/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphilo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:31:00 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/11 19:35:30 by mohtakra         ###   ########.fr       */
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
	int				printable;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	time_to_sleep;
	unsigned long	number_time_to_eat;
	unsigned long	end_simul;
} t_args;

typedef struct s_list
{
	int				nbr;
	unsigned long	last_meal;
	unsigned long	start_simul;
	unsigned long	nbr_time_eaten;
	int				status;
	pthread_mutex_t	own_fork;
	t_args			*args;
	struct s_list	*next;
} t_list;

# include "./parsing/libparsing.h"

t_list	*ft_lstnew(int nbr);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
/*philo utils functions*/
void			*eat_sleep_think(void *args);
void			del(void *data);
int				ft_atoi(char *str);
void			ft_usleep(unsigned long unbr);
void			print_state(char c, t_list *lst);
unsigned long	right_now(void);
t_args			*set_mutual_data(int argc, char **argv);



#endif