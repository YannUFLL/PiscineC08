/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydumaine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:49:23 by ydumaine          #+#    #+#             */
/*   Updated: 2022/02/01 01:59:50 by ydumaine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_stock_str.h"
void	ft_putstr(char *str);
void ft_show_tab(struct s_stock_str *par);

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strcpy(char *src, _Bool *error)
{
	int	i;

	char *dest;
	i = 0;
	while (src[i] != '\0')
		i++;
	i++;
	if (!(dest = malloc(i)))
	{
		error = NULL;
		return (dest);
	}
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
struct	s_stock_str *ft_strs_to_tab(int	ac, char **av)
{
	int	i;
	t_stock_str *tab;
	_Bool error;
	_Bool *ptr_error; 
	error = 0;
	ptr_error = &error;
	i = 0;
	if (!(tab = malloc((sizeof(int) + (sizeof(char *) * 2) * (ac + 1) ))))
		ptr_error = NULL;
	while (i < ac && error == 0)
	{
		tab[i].str = ft_strcpy(av[i],ptr_error);
		tab[i].copy = ft_strcpy(av[i],ptr_error);
		tab[i].size = ft_strlen(av[i]); 
		i++;
	
	}
	printf("\nvaleur printf : %s\n", tab[0].str);
	tab[i].str = 0;
	tab[i].copy = 0;
	tab[i].size = 0;
	if (ptr_error == NULL)
		return(tab);
	return(tab);
}

int	main()
{
	char *tab[3];
	char a[] = "bonjour";
	char b[] = "au revoir";
	char c[] = "zgeg";
	tab[0] = a;
	tab[1] = b;
	tab[2] = c;
    
	
	t_stock_str *bonjour;
   	bonjour	= ft_strs_to_tab(3, tab);
	ft_show_tab(bonjour);
}
