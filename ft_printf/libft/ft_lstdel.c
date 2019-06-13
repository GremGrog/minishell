/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 23:31:02 by fmasha-h          #+#    #+#             */
/*   Updated: 2018/12/27 23:04:29 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	while ((*alst) != NULL)
	{
		del((*alst), (*alst)->content_size);
		(*alst) = (*alst)->next;
	}
	free(*alst);
	*alst = NULL;
}
