/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:06:33 by slevaslo          #+#    #+#             */
/*   Updated: 2023/03/30 18:03:49 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(t_data *data)
{
	t_stack	*nb_a;

	nb_a = data->stack_a;
	if (nb_a->value > nb_a->next->value)
	{
		if (nb_a->value > nb_a->next->next->value)
		{
			if (nb_a->next->value > nb_a->next->next->value)
			{
				sa(data);
				rra(data);
			}
			else
				ra(data);
		}
		else if (nb_a->value < nb_a->next->next->value)
			sa(data);
	}
	else if (nb_a->value > nb_a->next->next->value)
		rra(data);
	else if (nb_a->next->value > nb_a->next->next->value)
	{
		sa(data);
		ra(data);
	}
}

int	dividend_check(t_data *data, int j)
{
	t_stack	*nb;

	nb = data->stack_a;
	while (nb)
	{
		if (nb->value < j)
			return (1);
		nb = nb->next;
	}
	return (0);
}

int	median_check(t_stack *stack, int i)
{
	t_stack	*nb;

	nb = stack;
	while (nb)
	{
		if (nb->value < i)
			return (1);
		nb = nb->next;
	}
	return (0);
}

int	median_of(t_stack *stack)
{
	int	*tab;
	int	i;

	tab = make_tab(stack);
	ft_sort_int_tab(tab, stack_size(stack));
	i = tab[stack_size(stack) / 2];
	free(tab);
	return (i);
}

void	sort_median(t_data *data)
{
	t_stack	*nb_a;
	int		i;
	int		j;
	int		l;

	nb_a = data->stack_a;
	j = stack_size(data->stack_a);
	while (j > 5)
	{
		l = median_of(data->stack_a);
		while (median_check(data->stack_a, l) == 1)
		{
			if (nb_a->value < l)
				pb(data);
			else
				ra(data);
			nb_a = data->stack_a;
		}
		j = j / 2;
	}
	i = stack_size(data->stack_a);
	while (--i > 2)
		pb(data);
	sort_three_numbers(data);
}
