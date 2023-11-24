/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sc%_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:27:32 by almichel          #+#    #+#             */
/*   Updated: 2023/11/23 17:40:11 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*s2;
	int		size;

	i = 0;
	size = ft_strlen(s);
	s2 = malloc((size + 1) * sizeof(char));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_stock_string(char *str, t_list **list, int *error)
{
	int		i;
	char	*tab;
	t_list	*new_case;

	if (!str)
	{
		tab = ft_strdup("(null)");
		new_case = ft_lstnew_two(tab, 6);
		ft_lstadd_back(list, new_case);
		return (6);
	}
	i = 0;
	tab = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!tab)
		return (*error = 0);
	while (str[i])
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	new_case = ft_lstnew_two(tab, ft_strlen(str));
	ft_lstadd_back(list, new_case);
	return (ft_strlen(str));
}

int	ft_c(char c, t_list **list, int *error)
{
	char	*tab;
	t_list	*new_case;

	tab = malloc(2 * sizeof(char));
	if (!tab)
		return (*error);
	tab[0] = c;
	tab[1] = '\0';
	new_case = ft_lstnew_two(tab, 1);
	ft_lstadd_back(list, new_case);
	return (1);
}
