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

int	*ft_u(unsigned n, t_list **list, int *error, int base)
{
	char				*result;
	int					count;
	long int			nb;
	int					i;
	t_list 				*new_case;
	
	nb = n;
	count = ft_count(n, base);
	i = count;
	result = malloc ((count + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[count--] = '\0';
	if (nb == 0)
		result[0] = '0';
	if (nb < 0)
	{
		nb = -nb;
		result[0] = '-';
	}
	while (nb > 0)
	{
		result[count--] = nb % base + 48;
		nb = nb / base;
	}
	new_case = ft_lstnew(result, i);
	ft_lstadd_back(list, new_case);
	return (i);
}

int	*ft_p(unsigned n, t_list **list, int *error, int base)
{

}