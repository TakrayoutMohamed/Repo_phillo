/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_accepted_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:47:17 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/13 23:24:46 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libparsing.h"

/*return how many chars in a nbr */
static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/*return how many chars in a string */
size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

/*return true if the given nbr is positive int*/
int	is_positive_int(char *str, int nbr)
{
	int	j;

	j = 0;
	if (nbr <= 0)
		return (0);
	if (str[0] == '+')
		j++;
	while (str[j] == '0' && str[j + 1] != '\0')
		j++;
	if ((int)ft_strlen(str + j) != ft_nbrlen(nbr))
		return (0);
	return (1);
}

/*return true if the given matrix countain only chars that is in range of int*/
int	is_accepted_int(int argc, char **matrix, t_args *args)
{
	if (matrix && *matrix && args)
	{
		if (!is_positive_int(matrix[1], args->nbr_philosophers))
			return (0);
		if (!is_positive_int(matrix[2], args->time_to_die))
			return (0);
		if (!is_positive_int(matrix[3], args->time_to_eat))
			return (0);
		if (!is_positive_int(matrix[4], args->time_to_sleep))
			return (0);
		if (argc == 6)
		{
			if (!is_positive_int(matrix[5], args->number_time_to_eat))
				return (0);
		}
	}
	return (1);
}
