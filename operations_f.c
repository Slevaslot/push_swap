/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:33:09 by slevaslo          #+#    #+#             */
/*   Updated: 2023/02/20 20:33:11 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	t_stack	*nb_a;
	int		swap;

	nb_a = data->stack_a;
	if (!nb_a || !nb_a->next)
		return ;
	swap = nb_a->value;
	nb_a->value = nb_a->next->value;
	nb_a->next->value = swap;
	ft_printf("sa\n");
}

void	sb(t_data *data)
{
	t_stack	*nb_b;
	int		swap;

	nb_b = data->stack_b;
	if (!nb_b || !nb_b->next)
		return ;
	swap = nb_b->value;
	nb_b->value = nb_b->next->value;
	nb_b->next->value = swap;
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
}

void	pa(t_data *data)
{
	t_stack	*nb_b;
	t_stack	*swap;

	nb_b = data->stack_b;
	if (!nb_b)
		return ;
	swap = new_nb(nb_b->value);
	if (!swap)
		return ;
	swap->next = data->stack_a;
	data->stack_b = nb_b->next;
	data->stack_a = swap;
	free(nb_b);
	ft_printf("pa\n");
}

void	pb(t_data *data)
{
	t_stack	*nb_a;
	t_stack	*swap;

	nb_a = data->stack_a;
	if (!nb_a)
		return ;
	swap = new_nb(nb_a->value);
	if (!swap)
		return ;
	swap->next = data->stack_b;
	data->stack_a = nb_a->next;
	data->stack_b = swap;
	free(nb_a);
	ft_printf("pb\n");
}
