/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:05:15 by slevaslo          #+#    #+#             */
/*   Updated: 2023/03/20 16:00:33 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_data *data)
{
	t_stack	*nb_a;
	int		value;

	value = min_value(data->stack_a);
	if (data->stack_b || !data->stack_a)
		return (1);
	nb_a = data->stack_a;
	while (nb_a)
	{
		if (nb_a->value < value)
			return (1);
		value = nb_a->value;
		nb_a = nb_a->next;
	}
	return (0);
}

int	best_a(t_data *data, int value)
{
	t_stack	*nb_a;
	int		i;
	int		j[2];

	nb_a = data->stack_a;
	i = -1;
	j[0] = min_value(data->stack_a);
	j[1] = min_pos(data->stack_a);
	while (nb_a)
	{
		i++;
		if (nb_a->value < value && nb_a->value >= j[0])
		{
			j[0] = nb_a->value;
			j[1] = i + 1;
		}
		nb_a = nb_a->next;
	}
	if (j[1] > stack_size(data->stack_a) / 2)
		return (j[1] - stack_size(data->stack_a));
	return (j[1]);
}

int	compare_b(t_data *data, int value, int i, int j)
{
	int	b;

	b = best_a(data, value);
	if (b < 0)
		b = -b;
	if (b + i < j
		|| b + -(i - stack_size(data->stack_b)) < j)
	{
		if (i > stack_size(data->stack_b) / 2)
			return (b + -(i - stack_size(data->stack_b)));
		else
			return (b + i);
	}
	return (-1);
}

int	best_b(t_data *data)
{
	t_stack	*nb_b;
	int		i;
	int		j[2];

	nb_b = data->stack_b;
	i = -1;
	j[0] = stack_size(data->stack_b) + stack_size(data->stack_a);
	j[1] = 0;
	while (nb_b)
	{
		i++;
		if (compare_b(data, nb_b->value, i, j[0]) >= 0)
		{
			j[0] = compare_b(data, nb_b->value, i, j[0]);
			j[1] = i;
		}
		nb_b = nb_b->next;
	}
	if (j[1] > stack_size(data->stack_b) / 2)
		return (j[1] - stack_size(data->stack_b));
	return (j[1]);
}

int	sort_stack(t_data *data)
{
	int		i;

	while (stack_size(data->stack_b))
	{
		i = best_b(data);
		if (i < 0)
			while (++i < 1)
				rrb(data);
		else
			while (--i > -1)
				rb(data);
		i = best_a(data, data->stack_b->value);
		if (i < 0)
			while (++i < 1)
				rra(data);
		else
			while (--i > -1)
				ra(data);
		pa(data);
	}
	while (data->stack_a->value != min_value(data->stack_a))
		rra(data);
	return (0);
}
