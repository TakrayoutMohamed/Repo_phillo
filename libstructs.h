/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libstructs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:14:26 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/14 23:06:04 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSTRUCTS_H
# define LIBSTRUCTS_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_args
{
	int				nbr_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_time_to_eat;
	int				end_simul;
	pthread_mutex_t	lock_output;
	pthread_mutex_t	lock_increment;
	pthread_mutex_t	lock_time;
	pthread_mutex_t	lock_decrement;
}	t_args;

typedef struct s_list
{
	int				nbr_time_eaten;
	int				nbr;
	unsigned long	last_meal;
	unsigned long	start_simul;
	t_args			*args;
	pthread_t		thread;
	pthread_mutex_t	own_fork;
	struct s_list	*next;
}	t_list;

#endif
