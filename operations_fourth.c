/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_fourth.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:08:53 by slevaslo          #+#    #+#             */
/*   Updated: 2023/03/06 14:05:47 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_f(t_data *data)
{
	t_stack	*nb_a;
	t_stack	*swap;

	nb_a = data->stack_a;
	if (!nb_a || !nb_a->next)
		return ;
	while (nb_a->next->next)
		nb_a = nb_a->next;
	swap = new_nb(nb_a->next->value);
	if (!swap)
		return ;
	free(nb_a->next);
	nb_a->next = NULL;
	nb_a = data->stack_a;
	swap->next = nb_a;
	data->stack_a = swap;
}

void	rra(t_data *data)
{
	rra_f(data);
	ft_printf("rra\n");
}

void	rrb_f(t_data *data)
{
	t_stack	*nb_b;
	t_stack	*swap;

	nb_b = data->stack_b;
	if (!nb_b || !nb_b->next)
		return ;
	while (nb_b->next->next)
		nb_b = nb_b->next;
	swap = new_nb(nb_b->next->value);
	if (!swap)
		return ;
	free(nb_b->next);
	nb_b->next = NULL;
	nb_b = data->stack_b;
	swap->next = nb_b;
	data->stack_b = swap;
}

void	rrb(t_data *data)
{
	rrb_f(data);
	ft_printf("rrb\n");
}

void	rrr(t_data *data)
{
	rra_f(data);
	rrb_f(data);
	ft_printf("rrr\n");
}
