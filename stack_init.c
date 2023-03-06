/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:34:05 by slevaslo          #+#    #+#             */
/*   Updated: 2023/02/20 20:34:06 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_back_nb(t_stack *stack, t_stack *new)
{
	t_stack	*nb;

	nb = stack;
	if (!stack)
	{
		nb = new;
		return ;
	}
	while (nb->next)
		nb = nb->next;
	nb->next = new;
	new->next = NULL;
}

t_stack	*new_nb(int value)
{
	t_stack	*nb;

	nb = malloc(sizeof(t_stack));
	if (!nb)
		return (NULL);
	nb->value = value;
	nb->next = NULL;
	return (nb);
}
