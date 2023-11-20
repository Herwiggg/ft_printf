/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:33:15 by almichel          #+#    #+#             */
/*   Updated: 2023/11/16 18:36:01 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_list	*ft_lstnew(char *str, int size)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list->content = str;
	list->size = size;
	list->next = NULL;
	return (list);
}
int	ft_stock_char(char c, t_list **list, int *error)
{
	char	*tab;
	int		size;
	t_list *new_case;

	tab = malloc(2 * sizeof(char));
	if(!tab)
		return (NULL);
	size = 1;
	tab[0] = c;
	tab[1] = '\0';
	new_case = ft_lstnew(tab, size);
	ft_lstadd_back(list, new_case);
	return (1);
}
int	ft_search_arg(char c,t_list **list, va_list arg, int *error)
{
	int	size;

	size = 0; 
	if (c == 'c')
		size = ft_c(va_arg(arg, int), list, error);
	else if (c == 's')
		size = ft_stock_string(va_arg(arg, char *), list, error);
	else if (c == 'p')
		size = ft_p(va_arg(arg, void *), list, error);
	else if (c == 'd' || c == 'i')
		size = ft_itoa(va_arg(arg, void *), list, error, 10);
	else if (c == 'u')
		size = ft_u(va_arg(arg, unsigned int), list, error, 10);
	else if (c == 'x')
		size = ft_itoa(va_arg(arg, unsigned int), list, error, 16);
	else if (c == 'X')
		size = ft_itoa_maj(va_arg(arg, unsigned int), list, error, 16);
	else if (c == '%')
		size = ft_c(c, list, error);
	return (size);


}
int	ft_prog_printf(const char *str, t_list **list, va_list arg, int *error)
{
	int		i;
	int		size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			size = size + ft_search_arg(str[i + 1], list, arg, error);
			i++;
		}
		else
			size = size + ft_stock_char(str[i], list, error);
		i++;
	}
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	va;

	va_start(va, str);
	
}
