/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dxxi_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:25:21 by almichel          #+#    #+#             */
/*   Updated: 2023/11/21 19:34:50 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(int n, int base)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		n = -n;
		count++;
	}
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

int	ft_itoa_n(int n, t_list **list, int *error, int base)
{
	char		*result;
	int			count;
	long int	nb;
	int			i;
	t_list		*new_case;

	nb = n;
	count = ft_count(n, base);
	i = count;
	result = malloc((count + 1) * sizeof(char));
	if (!result)
		return (*error);
	result = ft_tab_itoa(nb, result, count, base);
	new_case = ft_lstnew_two(result, i);
	ft_lstadd_back(list, new_case);
	return (i);
}

char	*ft_min_to_maj(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int	ft_itoa_maj(int n, t_list **list, int *error, int base)
{
	char		*result;
	int			count;
	long int	nb;
	int			i;
	t_list		*new_case;

	nb = n;
	count = ft_count(n, base);
	i = count;
	result = malloc((count + 1) * sizeof(char));
	if (!result)
		return (*error);
	result = ft_tab_itoa(nb, result, count, base);
	result = ft_min_to_maj(result);
	new_case = ft_lstnew_two(result, i);
	ft_lstadd_back(list, new_case);
	return (i);
}

char	*ft_tab_itoa(long int nb, char *result, int count, int base)
{
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
	return (result);
}
