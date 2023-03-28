/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:28:41 by slevaslo          #+#    #+#             */
/*   Updated: 2023/03/27 14:41:30 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elemCount, size_t elementSize)
{
	void	*tab;
	char	*array;
	size_t	i;

	i = 0;
	tab = NULL;
	if (elemCount * elementSize == 0 || elemCount <= SIZE_MAX / elementSize)
		tab = (void *)malloc(elemCount * elementSize);
	if (!tab)
		return (NULL);
	array = (char *) tab;
	while (i < elemCount * elementSize)
	{
		array[i] = 0;
		i++;
	}
	return (tab);
}
