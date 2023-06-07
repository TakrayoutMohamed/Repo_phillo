/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_only_nbrs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 21:16:21 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/07 23:47:01 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libparsing.h"

/*return true if the given char a space char*/
static int	ft_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

/*return true if the given char is a sign + or - */
static int	ft_is_sign(char c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

/*return true if the **str is only integers + and -*/
int	is_only_nbrs(char **str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && !ft_is_space(str[i][j]))
			{
				if (ft_is_sign(str[i][j]) && ft_isdigit(str[i][j - 1]))
					return (0);
				if (ft_is_sign(str[i][j]) && !ft_isdigit(str[i][j + 1]))
					return (0);
				if (ft_is_sign(str[i][j]) && ft_is_sign(str[i][j - 1]))
					return (0);
				else if (str[i][j] != '+')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
