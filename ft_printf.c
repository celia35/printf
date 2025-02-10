/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:37:06 by cbrice            #+#    #+#             */
/*   Updated: 2025/01/30 15:57:43 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_flags(va_list args, const char format, int *len)
{
	if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(args, int), len);
	else if (format == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), len);
	else if (format == 'c')
		ft_putchar((char)va_arg(args, int), len);
	else if (format == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (format == '%')
		ft_putchar(format, len);
	else if (format == 'x')
		ft_nbr_x(va_arg(args, int), format, len);
	else if (format == 'X')
		ft_nbr_x(va_arg(args, int), format, len);
	else if (format == 'p')
		ft_put_p(va_arg(args, void *), len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start (args, format);
	count = 0;
	if (!format || *format == '\0')
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_flags (args, *format, &count);
		}
		else
			ft_putchar (*format, &count);
		format++;
	}
	va_end(args);
	return (count);
}
