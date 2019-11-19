/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgrankul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:55:13 by vgrankul          #+#    #+#             */
/*   Updated: 2019/10/31 14:03:50 by vgrankul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		n = n / 10;
		ft_putnbr(n);
		ft_putchar('8');
	}
	else
	{
		if (n < -2147483648 || n > 2147483647)
			return ;
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n < 10)
		{
			ft_putchar(n + '0');
			return ;
		}
		ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
		return ;
	}
}