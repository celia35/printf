/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:58:23 by cbrice            #+#    #+#             */
/*   Updated: 2025/01/30 16:01:50 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *len)
{
	write (1, &c, 1);
	(*len)++;
}

int	ft_putstr(char *s, int *len)
{
	size_t	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)", len);
		return (0);
	}
	while (s[i])
	{
		ft_putchar(s[i], len);
		i++;
	}
	return (0);
}
