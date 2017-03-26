/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaragul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:08:47 by egaragul          #+#    #+#             */
/*   Updated: 2016/12/08 17:39:31 by egaragul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_lst;
	t_list	*buff;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	buff = f(lst);
	new_lst = ft_lstnew(buff->content, buff->content_size);
	if (new_lst)
	{
		tmp = new_lst;
		lst = lst->next;
		while (lst)
		{
			buff = f(lst);
			tmp->next = ft_lstnew(buff->content, buff->content_size);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (new_lst);
}
