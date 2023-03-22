/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_first.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:08:53 by slevaslo          #+#    #+#             */
/*   Updated: 2023/03/06 14:00:23 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_f(t_data *data)
{
	t_stack	*nb_a;
	int		swap;

	nb_a = data->stack_a;
	if (!nb_a || !nb_a->next)
		return ;
	swap = nb_a->value;
	nb_a->value = nb_a->next->value;
	nb_a->next->value = swap;
}

void	sa(t_data *data)
{
	sa_f(data);
	ft_printf("sa\n");
}

void	sb_f(t_data *data)
{
	t_stack	*nb_b;
	int		swap;

	nb_b = data->stack_b;
	if (!nb_b || !nb_b->next)
		return ;
	swap = nb_b->value;
	nb_b->value = nb_b->next->value;
	nb_b->next->value = swap;
}

void	sb(t_data *data)
{
	sb_f(data);
	ft_printf("sb\n");
}

void	ss(t_data *data)
{
	sa_f(data);
	sb_f(data);
	ft_printf("ss\n");
}
