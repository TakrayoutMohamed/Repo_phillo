/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_nbr_args.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:41:20 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/07 21:42:02 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libparsing.h"

/*return true if the number of args is 5 or 6*/
int	is_valid_nbr_args(int argc)
{
	if (argc != 6 && argc != 5)
	{
		printf("\nERROR :\n");
		if (argc > 6)
			printf("too much args, allowd number are 5 or 6\n");
		else
			printf("too few args, allowd number are 5 or 6\n");
		return (0);
	}
	return (1);
}
