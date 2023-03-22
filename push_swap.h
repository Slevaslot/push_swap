/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:04:07 by slevaslo          #+#    #+#             */
/*   Updated: 2023/03/06 14:10:58 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define SIZE_MAX (18446744073709551615UL)

# include "../libftprintfgnl/libftprintfgnl.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;
	int		err;
}	t_data;

int		make_stack(t_data *data, char **argv);
void	sort_median(t_data *data);
int		stack_size(t_stack *stack);
int		sort_stack(t_data *data);
int		*make_tab(t_stack *stack);
int		min_value(t_stack *stack);
int		min_pos(t_stack *stack);
void	free_stacks(t_data *data);
t_stack	*new_nb(int value);
void	add_back_nb(t_stack *stack, t_stack *new);
int		is_sort(t_data *data);
void	sort_three_numbers(t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	ss(t_data *data);
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	sa_f(t_data *data);
void	sb_f(t_data *data);
void	pa_f(t_data *data);
void	pb_f(t_data *data);
void	ra_f(t_data *data);
void	rb_f(t_data *data);
void	rra_f(t_data *data);
void	rrb_f(t_data *data);

#endif
