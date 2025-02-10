/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:39:37 by cbrice            #+#    #+#             */
/*   Updated: 2025/01/31 20:25:35 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int n, int *len)
{
	unsigned int	nb;

	nb = n;
	if (n < 0)
	{
		ft_putchar('-', len);
		nb *= -1;
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0', len);
	}
	else
	{
		ft_putnbr(nb / 10, len);
		ft_putnbr(nb % 10, len);
	}
}

void	ft_putnbr_u(unsigned int n, int *len)
{
	if (n < 10)
		ft_putchar(n + '0', len);
	else
	{
		ft_putnbr(n / 10, len);
		ft_putnbr(n % 10, len);
	}
}

void	ft_nbr_x(unsigned int nbr, char Xx, int *len)
{
	unsigned int	base_len;
	char			*base;

	base_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < base_len)
	{
		ft_putchar(base[nbr % base_len], len);
	}
	else
	{
		ft_nbr_x(nbr / base_len, Xx, len);
		ft_nbr_x(nbr % base_len, Xx, len);
	}
}

static void	ft_putptr_hex(unsigned long int nbr, char Xx, int *len)
{
	unsigned long int	base_len;
	char				*base;

	base_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < base_len)
		ft_putchar(base[nbr % base_len], len);
	else
	{
		ft_putptr_hex(nbr / base_len, Xx, len);
		ft_putptr_hex(nbr % base_len, Xx, len);
	}
}

void	ft_put_p(void *p, int *len)
{
	unsigned long int	ptr;

	ptr = (unsigned long int) p;
	if (p == 0)
		ft_putstr("(nil)", len);
	else
	{
		ft_putstr("0x", len);
		ft_putptr_hex(ptr, 'x', len);
	}
}
