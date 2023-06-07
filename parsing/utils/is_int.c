/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:47:17 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/07 23:58:21 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libparsing.h"

/*return how many chars in a nbr */
static int	ft_nbrlen(int nbr)
{
	int	len;

	len = 0;
	if (nbr <= 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

/*return true if the given char is a sign + or - */
static int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

/*return how many chars in a string */
size_t  ft_strlen(char *str)
{
    size_t  len;

    len = 0;
    while (*str)
    {
        len++;
        str++;
    }
    return (len);
}

/*return true if the given matrix countain only chars that is in range of int*/
int	is_accepted_int(char **matrix, t_args *args)
{
	int	j;
	int	minus;

	while (*matrix && args)
	{
		j = 0;
		if ((*matrix)[0] == '+')
			j++;
		while ((*matrix)[j] == '0' && (*matrix)[j + 1] != '\0')
				j++;
		if ((int)ft_strlen((*matrix) + j) != ft_nbrlen(args->))
			return (0);
		lst = lst->next;
		matrix++;
	}
	return (1);
}