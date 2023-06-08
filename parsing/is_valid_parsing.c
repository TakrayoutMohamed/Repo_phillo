/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 19:51:52 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/08 16:31:38 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libparsing.h"

/*return true if the given agrs are 5 or 6 ,
* and contains only digits it could also contains a + sign,
*  and contains only positive integers \t
*/
int	is_valid_parsing(int argc, char **argv, t_args *args)
{
	if (!is_valid_nbr_args(argc))
	{
		printf("\nERROR : allowd number of args are 5 or 6\n");
		return (0);
	}
	if (!is_only_digits(argv))
	{
		printf("\nERROR : only digits and may be a + sign in its begain\n");
		return (0);
	}
	if (!is_accepted_int(argc, argv, args))
	{
		printf("\nERROR : use only positive number in int range\n");
		return (0);
	}
	return (1);
}
