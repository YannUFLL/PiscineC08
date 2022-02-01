/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 00:59:53 by ydumaine          #+#    #+#             */
/*   Updated: 2022/02/01 02:16:31 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_affi(int i, int nbr)
{
	char	a[20];
	int		u;

	u = 0;
	while (nbr > 0 || nbr < 0)
	{
		if (nbr > 0)
			a[u] = nbr % i;
		if (nbr < 0)
			a[u] = - (nbr % i);
		nbr = nbr / i;
		u++;
	}
	while (--u >= 0)
		ft_putchar(a[u] + 48);
}

void	ft_putnbr(int nbr)
{
	int	i;

	i = 10;
	if (nbr < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	if (nbr == 0)
		ft_putchar('0');
	else
		ft_affi(i, nbr);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void ft_show_tab(struct s_stock_str *par)
{
	int	i;

	printf("\n%s", par[0].str);
	i = 0;
	while (par[i].str != 0)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

