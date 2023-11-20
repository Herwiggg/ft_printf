/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc%_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:27:32 by almichel          #+#    #+#             */
/*   Updated: 2023/11/17 17:10:03 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_stock_string(char *str, t_list **list, int *error)
{
	int		i;
	char	*tab;
	int		size;
	t_list	*new_case;

	size = ft_strlen(str);
	i = 0;
	tab = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!tab)
		return (*error);
	while (str[i])
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	new_case = ft_lstnew(tab, size);
	ft_lstadd_back(list, new_case);
	return (ft_strlen(str));
}

int	ft_c(char c, t_list **list, int *error)
{
	char	*tab;
	int		size;
	t_list *new_case;

	tab = malloc(2 * sizeof(char));
	if (!tab)
		return (*error);
	tab[0] = c;
	tab[1] = '\0';
	new_case = ft_lstnew(tab, size);
	ft_lstadd_back(list, new_case);
	return (1);
}
