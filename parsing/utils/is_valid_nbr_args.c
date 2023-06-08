/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_nbr_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:41:20 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/08 14:38:22 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libparsing.h"

/*return true if the number of args is 5 or 6*/
int	is_valid_nbr_args(int argc)
{
	if (argc != 6 && argc != 5)
		return (0);
	return (1);
}
