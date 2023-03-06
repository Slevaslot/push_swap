/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:33:25 by slevaslo          #+#    #+#             */
/*   Updated: 2023/02/20 20:33:26 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	t_stack	*nb_a;
	t_stack	*swap;

	if (!data->stack_a)
		return ;
	nb_a = data->stack_a;
	swap = new_nb(nb_a->value);
	if (!swap)
		return ;
	while (nb_a && nb_a->next)
		nb_a = nb_a->next;
	nb_a->next = swap;
	nb_a = data->stack_a;
	data->stack_a = nb_a->next;
	free(nb_a);
	ft_printf("ra\n");
}

void	rb(t_data *data)
{
	t_stack	*nb_b;
	t_stack	*swap;

	nb_b = data->stack_b;
	swap = new_nb(nb_b->value);
	if (!swap)
		return ;
	while (nb_b && nb_b->next)
		nb_b = nb_b->next;
	nb_b->next = swap;
	nb_b = data->stack_b;
	data->stack_b = nb_b->next;
	free(nb_b);
	ft_printf("rb\n");
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
}
