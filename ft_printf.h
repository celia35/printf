/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbrice <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:02:28 by cbrice            #+#    #+#             */
/*   Updated: 2025/01/30 16:06:41 by cbrice           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putstr(char *s, int *len);
void	ft_putnbr(int n, int *len);
void	ft_putnbr_u(unsigned int n, int *len);
void	ft_put_p(void *addr, int *len);
void	ft_nbr_x(unsigned int nbr, char Xx, int *len);
void	ft_putchar(char c, int *len);

#endif
