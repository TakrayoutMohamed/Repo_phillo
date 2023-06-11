/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 18:59:49 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/11 19:04:51 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

int	ft_atoi(char *str)
{
	int	negative;
	int	nbr;

	negative = 1;
	nbr = 0;
	if (str)
	{
		if (*str == '-' || *str == '+')
		{
			if (*str == '-')
				negative = -1;
			str++;
		}
		while (*str)
		{
			nbr = nbr * 10 + *str - 48;
			str++;
		}
	}
	return (nbr * negative);
}
