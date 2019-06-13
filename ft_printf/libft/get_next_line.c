/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmasha-h <fmasha-h@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 18:54:16 by fmasha-h          #+#    #+#             */
/*   Updated: 2019/01/23 18:46:39 by fmasha-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*get_fd(t_list **node, int fd)
{
	t_list	*new;

	new = *node;
	while (new)
	{
		if (new->content_size == (size_t)fd)
			return (new);
		new = new->next;
	}
	new = ft_lstnew("\0", fd);
	ft_lstadd(node, new);
	(*node) = new;
	return (*node);
}

static int		str_create(t_list *cache, char **string)
{
	char		*str;
	int			i;

	i = 0;
	while (((char*)(cache->content))[i] != '\n'
	&& ((char*)(cache->content))[i] != '\0')
		i++;
	if (!((*string) = ft_strsub(cache->content, 0, i)))
		return (0);
	if (((char*)(cache->content))[i] == '\n')
		i++;
	if (!(str = ft_strdup(cache->content)))
		return (0);
	free(cache->content);
	if (!(cache->content = ft_strsub(str, i, ft_strlen(str) - i)))
		return (0);
	free(str);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	static t_list	*node;
	t_list			*cache;
	char			*str_cache;

	if (fd < 0 || line == NULL || read(fd, buf, 0) < 0)
		return (-1);
	cache = get_fd(&node, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(str_cache = ft_strjoin(cache->content, buf)))
			return (0);
		free(cache->content);
		cache->content = ft_strdup(str_cache);
		free(str_cache);
		if (ft_strchr(cache->content, '\n'))
			break ;
	}
	if (cache->content && ft_strlen(cache->content) != 0)
		return (str_create(cache, line));
	return (0);
}
