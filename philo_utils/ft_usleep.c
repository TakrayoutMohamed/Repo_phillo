/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohtakra <mohtakra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:00:22 by mohtakra          #+#    #+#             */
/*   Updated: 2023/06/11 19:33:46 by mohtakra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../libphilo.h"

/*sleep a proccess or a thread for some time in milliseconds*/
void	ft_usleep(unsigned long unbr)
{
	unsigned long	time;
	unsigned long	start;

	time = (unbr * 95) / 100;
	start = right_now();
	usleep(time * 1000);
	while(1)
	{
		if (right_now() - start >= unbr)
			break ;
		usleep(50);
	}
}
