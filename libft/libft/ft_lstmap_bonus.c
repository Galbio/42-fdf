/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:40:24 by gakarbou          #+#    #+#             */
/*   Updated: 2024/11/06 15:29:09 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*cur;

	if (!lst || !del || !f)
		return (NULL);
	dest = ft_lstnew(f(lst->content));
	lst = lst->next;
	cur = dest;
	while (lst)
	{
		cur->next = ft_lstnew(f(lst->content));
		if (!cur->next)
		{
			ft_lstclear(&dest, del);
			return (NULL);
		}
		lst = lst->next;
		cur = cur->next;
	}
	return (dest);
}
