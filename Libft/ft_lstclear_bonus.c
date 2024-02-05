/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: houamrha <houamrha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:42:13 by houamrha          #+#    #+#             */
/*   Updated: 2023/11/13 22:24:37 by houamrha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*suivant;

	if (!lst)
		return ;
	if (*lst != NULL && del != NULL)
	{
		tmp = *lst;
		while (tmp != NULL)
		{
			suivant = tmp->next;
			if (tmp->content != NULL)
			{
				del(tmp->content);
				tmp->content = NULL;
			}
			free(tmp);
			tmp = suivant;
		}
	}
	*lst = NULL;
}
