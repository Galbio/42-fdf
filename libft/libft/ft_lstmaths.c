/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmaths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:48:07 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/10 16:14:42 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstmin(t_list *lst, int (*get_value)(t_list *))
{
	int	min;

	min = get_value(lst);
	lst = lst->next;
	while (lst)
	{
		if (get_value(lst) < min)
			min = get_value(lst);
		lst = lst->next;
	}
	return (min);
}

int	ft_lstmax(t_list *lst, int (*get_value)(t_list *))
{
	int	max;

	max = get_value(lst);
	lst = lst->next;
	while (lst)
	{
		if (get_value(lst) > max)
			max = get_value(lst);
		lst = lst->next;
	}
	return (max);
}
