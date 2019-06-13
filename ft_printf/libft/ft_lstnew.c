/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 21:36:26 by fmasha-h          #+#    #+#             */
/*   Updated: 2018/12/26 23:03:04 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list *)malloc(sizeof(t_list) * content_size)))
		return (NULL);
	else
	{
		if (!content)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			list->content = (t_list *)malloc(sizeof(t_list) * content_size);
			if (!(list->content))
			{
				free(list);
				return (NULL);
			}
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
	}
	list->next = NULL;
	return (list);
}
