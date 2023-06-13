/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libparsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:52:39 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/13 23:20:57 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPARSING_H
# define LIBPARSING_H
# include "./../libphilo.h"

int	is_only_digits(char **str);
int	is_valid_nbr_args(int argc);
int	is_accepted_int(int argc, char **matrix, t_args *args);
int	is_valid_parsing(int argc, char **argv, t_args *args);

#endif
