/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:23:33 by almichel          #+#    #+#             */
/*   Updated: 2023/11/22 20:01:17 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstnew_two(char *str, int size)
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next)
		last = last->next;
	last->next = new;
}

void	ft_free_list(t_list **list)
{
	t_list	*head;
	t_list	*temp;

	head = *list;
	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->content);
		free(temp);
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (dest[len])
		len++;
	while (src[i])
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

char	*ft_list_to_tab(t_list **list)
{
	t_list	*head;
	char	*tab;
	int		totalsize;

	totalsize = 0;
	head = *list;
	while (head)
	{
		totalsize = totalsize + head->size;
		head = head->next;
	}
	tab = malloc((totalsize + 1) * sizeof(char));
	if (!tab)
		return (NULL);
	tab[0] = '\0';
	head = *list;
	while (head)
	{
		tab = ft_strcat(tab, head->content);
		head = head->next;
	}
	ft_free_list(list);
	return (tab);
}
