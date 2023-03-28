/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:42:06 by slevaslo          #+#    #+#             */
/*   Updated: 2023/03/27 14:41:30 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

// int main()
// {
//     char c;

//     c = 128;
//     printf("%d\n", ft_isprint(c));
//     printf("%d", isprint(c));
//     return(0);
// }
