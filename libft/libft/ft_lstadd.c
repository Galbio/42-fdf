/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gakarbou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 15:45:36 by gakarbou          #+#    #+#             */
/*   Updated: 2024/12/10 15:53:51 by gakarbou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*dest;

	dest = malloc(sizeof(t_list));
	if (!dest)
		return (NULL);
	dest->content = content;
	dest->next = NULL;
	return (dest);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && *lst)
		new->next = *lst;
	*lst = new;
}
