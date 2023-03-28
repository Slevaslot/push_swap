/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:25:58 by slevaslo          #+#    #+#             */
/*   Updated: 2023/03/27 14:41:30 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pos(t_stack *stack)
{
	t_stack	*nb;
	int		i;
	int		j[2];

	nb = stack;
	i = -1;
	j[0] = 2147483647;
	j[1] = 0;
	while (++i < stack_size(stack))
	{
		if (nb->value < j[0])
		{
			j[1] = i;
			j[0] = nb->value;
		}
		nb = nb->next;
	}
	return (j[1]);
}

int	min_value(t_stack *stack)
{
	t_stack	*nb;
	int		j;

	nb = stack;
	j = 2147483647;
	while (nb)
	{
		if (nb->value < j)
			j = nb->value;
		nb = nb->next;
	}
	return (j);
}

int	stack_size(t_stack *stack)
{
	t_stack	*nb;
	int		i;

	nb = stack;
	i = 0;
	while (nb != NULL)
	{
		i++;
		nb = nb->next;
	}
	return (i);
}

int	*make_tab(t_stack *stack)
{
	t_stack	*nb;
	int		*tab;
	int		i;

	nb = stack;
	tab = malloc(sizeof(int) * stack_size(stack));
	i = -1;
	while (nb)
	{
		tab[++i] = nb->value;
		nb = nb->next;
	}
	return (tab);
}

void	free_stacks(t_data *data)
{
	t_stack	*nb_a;
	t_stack	*nb_b;

	nb_a = data->stack_a;
	nb_b = data->stack_b;
	while (nb_a)
	{
		data->stack_a = nb_a->next;
		free(nb_a);
		nb_a = data->stack_a;
	}
	while (nb_b)
	{
		data->stack_b = nb_b->next;
		free(nb_b);
		nb_b = data->stack_b;
	}
}
