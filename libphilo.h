/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libphilo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:31:00 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/13 23:20:13 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPHILO_H
# define LIBPHILO_H
# include "./libstructs.h"
# include "./parsing/libparsing.h"

t_list			*ft_lstnew(int nbr);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
/*philo utils functions*/
void			*eat_sleep_think(void *args);
void			del(void *data);
int				ft_atoi(char *str);
void			ft_usleep(unsigned long unbr);
void			print_state(char c, t_list *lst, unsigned long time);
unsigned long	right_now(void);
t_args			*set_mutual_data(int argc, char **argv);

#endif