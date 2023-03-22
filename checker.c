/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:33:29 by slevaslo          #+#    #+#             */
/*   Updated: 2023/03/06 14:10:44 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*make_str(int fd)
{
	char	*buffer;
	char	*str;

	str = ft_calloc(1, 1);
	if (!str)
		return (NULL);
	buffer = get_next_line(fd);
	while (buffer)
	{
		str = ft_strjoin(str, buffer);
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	return (str);
}

char	**read_map(int fd)
{
	char	*str;
	char	**fon;

	str = make_str(fd);
	fon = ft_split(str, '\n');
	if (!fon)
		return (NULL);
	close(fd);
	free(str);
	if (!fon[0])
	{
		free(fon);
		return (NULL);
	}
	return (fon);
}

int	can_move(t_data *data, char *fon)
{
	if (ft_strncmp(fon, "sa", 2) == 0)
		return (sa_f(data), 0);
	else if (ft_strncmp(fon, "sb", 2) == 0)
		return (sb_f(data), 0);
	else if (ft_strncmp(fon, "ss", 2) == 0)
		return (sa_f(data), sb_f(data), 0);
	else if (ft_strncmp(fon, "pa", 2) == 0)
		return (pa_f(data), 0);
	else if (ft_strncmp(fon, "pb", 2) == 0)
		return (pb_f(data), 0);
	else if (ft_strncmp(fon, "rra", 3) == 0)
		return (rra_f(data), 0);
	else if (ft_strncmp(fon, "rrb", 3) == 0)
		return (rrb_f(data), 0);
	else if (ft_strncmp(fon, "rrr", 3) == 0)
		return (rra_f(data), rrb_f(data), 0);
	else if (ft_strncmp(fon, "ra", 2) == 0)
		return (ra_f(data), 0);
	else if (ft_strncmp(fon, "rb", 2) == 0)
		return (rb_f(data), 0);
	else if (ft_strncmp(fon, "rr", 2) == 0)
		return (ra_f(data), rb_f(data), 0);
	return (1);
}

int	do_move(t_data *data, char **fon)
{
	int	i;

	i = -1;
	while (fon[++i])
	{
		if (can_move(data, fon[i]) == 1)
		{
			free_stacks(data);
			return (ft_printf("Error\n"));
		}
	}
	if (is_sort(data) == 1)
	{
		ft_freetab(fon);
		free_stacks(data);
		return (ft_printf("KO\n"));
	}
	else
	{
		ft_freetab(fon);
		free_stacks(data);
		return (ft_printf("OK\n"));
	}
}

int	main(int argc, char **argv)
{
	char	**fon;
	t_data	data;

	if (argc == 1)
		return (1);
	data.stack_a = NULL;
	data.stack_b = NULL;
	data.err = 0;
	data.len = argc - 1;
	if (make_stack(&data, argv) > 0)
		return (1);
	fon = read_map(0);
	if (fon)
		do_move(&data, fon);
	else
	{
		if (is_sort(&data) == 1)
		{
			free_stacks(&data);
			return (ft_printf("KO\n"));
		}
		free_stacks(&data);
		return (ft_printf("OK\n"));
	}
	return (0);
}
