/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_third.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:27:27 by slevaslo          #+#    #+#             */
/*   Updated: 2023/03/06 16:27:28 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_f(t_data *data)
{
	t_stack	*nb_a;
	t_stack	*swap;

	if (!data->stack_a || !data->stack_a->next)
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
}

void	ra(t_data *data)
{
	ra_f(data);
	ft_printf("ra\n");
}

void	rb_f(t_data *data)
{
	t_stack	*nb_b;
	t_stack	*swap;

	if (!data->stack_b || !data->stack_b->next)
		return ;
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
}

void	rb(t_data *data)
{
	rb_f(data);
	ft_printf("rb\n");
}

void	rr(t_data *data)
{
	ra_f(data);
	rb_f(data);
	ft_printf("rr\n");
}
