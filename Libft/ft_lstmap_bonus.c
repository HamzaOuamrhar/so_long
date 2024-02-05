/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:40:33 by houamrha          #+#    #+#             */
/*   Updated: 2023/11/13 18:16:54 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*node ;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	node = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		node = ft_lstnew(content);
		if (node == NULL)
		{
			ft_lstclear(&res, del);
			del(content);
			return (NULL);
		}
		if (res == NULL)
			res = node;
		else
			ft_lstadd_back(&res, node);
		lst = lst->next;
	}
	return (res);
}
