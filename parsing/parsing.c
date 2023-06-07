/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:52 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/07 23:45:25 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libparsing.h"

int	parsing(int argc, char **argv, t_args args)
{
	if (!is_valid_nbr_args(argc))
		return (0);
	if (!is_only_nbrs(argv))
		return (0);
	if (1)
		return (0);
	return (1);
}
