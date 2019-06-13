/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 18:30:01 by fmasha-h          #+#    #+#             */
/*   Updated: 2018/12/27 21:06:01 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*begin;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = f(lst);
	begin = new;
	while (lst->next != NULL)
	{
		new->next = f(lst->next);
		if (!new->next)
		{
			free(new);
			return (NULL);
		}
		lst = lst->next;
		new = new->next;
	}
	return (begin);
}
