/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:27:32 by almichel          #+#    #+#             */
/*   Updated: 2023/11/22 18:07:02 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_p(unsigned long n, int base)
{
	int	count;

	count = 0;
	if (n == 0)
	{
		count = 1;
		return (count);
	}
	while (n)
	{
		n = n / base;
		count++;
	}
	return (count);
}

int	ft_u(unsigned n, t_list **list, int *error, int base)
{
	char		*result;
	int			count;
	long int	nb;
	int			i;
	t_list		*new_case;

	nb = n;
	count = ft_count_p(n, base);
	i = count;
	result = malloc((count + 1) * sizeof(char));
	if (!result)
		return (*error);
	result[count--] = '\0';
	if (nb == 0)
		result[0] = '0';
	while (nb > 0)
	{
		result[count--] = nb % base + 48;
		nb = nb / base;
	}
	new_case = ft_lstnew_two(result, i);
	ft_lstadd_back(list, new_case);
	return (i);
}

int	ft_p(void *ptr, t_list **list, int *error, int base)
{
	char			*result;
	int				count;
	unsigned long	n;
	t_list			*new_case;
	int				i;

	n = (unsigned long)ptr;
	count = ft_count_p(n, base) + 2;
	result = malloc((count + 1) * sizeof(char));
	i = count;
	result[count--] = '\0';
	if (!result)
		return (*error);
	while (n > 0)
	{
		result[count--] = "0123456789abcdef"[n % base];
		n = n / base;
	}
	result[count] = 'x';
	count--;
	result[count] = '0';
	new_case = ft_lstnew_two(result, i);
	ft_lstadd_back(list, new_case);
	return (i);
}
