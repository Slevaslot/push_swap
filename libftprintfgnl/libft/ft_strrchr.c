/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slevaslo <slevaslo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:56:22 by slevaslo          #+#    #+#             */
/*   Updated: 2022/11/16 14:09:22 by slevaslo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *stradd, int c)
{
	int		i;
	char	*str;

	str = (char *)stradd;
	i = ft_strlen(str);
	if ((char)c == 0)
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}

// int main()
// {
//     char str[] = "Koiol";
//     char c = 'o';
//     printf("%s\n", ft_strrchr(str, c));
//     printf("%s", strrchr(str, c));
//     return(0);
// }
