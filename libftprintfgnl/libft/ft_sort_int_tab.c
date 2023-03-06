/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdosso-d <pdosso-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:19:55 by pdosso-d          #+#    #+#             */
/*   Updated: 2023/02/16 15:20:15 by pdosso-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	x;

	x = 0;
	i = 0;
	while ((i < size))
	{
		while (x < size)
		{
			if (tab[x] < tab[i])
				ft_swap(&tab[i], &tab[x]);
			else
				x++;
		}
		i++;
		x = i + 1;
	}
}
