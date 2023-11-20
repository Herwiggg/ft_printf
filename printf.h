/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almichel <	almichel@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:34:33 by almichel          #+#    #+#             */
/*   Updated: 2023/11/16 19:08:32 by almichel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	int				size;
	struct s_list	*next;
}					t_list;


int	ft_c(char c, t_list **list, int *error);
int					ft_count(int n, int base);
int					ft_itoa(int n, t_list **list, int *error, int base);
char				*ft_min_to_maj(char *str);
int					ft_itoa_maj(int n, t_list **list, int *error, int base);
int					ft_stock_string(char *str, t_list **list, int *error);

t_list				*ft_lstnew(char *str, int size);
int					ft_stock_char(char c, t_list **list, int *error);
int					ft_search_arg(char c, t_list **list, va_list arg,
						int *error);
int					ft_prog_printf(const char *str, t_list **list, va_list arg,
						int *error);
int					ft_printf(const char *str, ...);
int					ft_strlen(char *str);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_free_list(t_list **list);
char				*ft_strcat(char *dest, char *src);
char				*ft_list_to_tab(t_list **list);
void				ft_write_tab(char *tab);
int					ft_p(unsigned n, t_list **list, int *error, int base);
int					ft_u(unsigned n, t_list **list, int *error, int base);

#endif