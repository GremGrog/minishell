#include "../minishell.h"

long long	hash_for_builtin(char *str, int hasht_size)
{
	int			i;
	long long	hash;
	int			p;
	long long	p_pow;

	p_pow = 1;
	i = 0;
	hash = 0;
	p = 16;
	while (str[i] != '\0')
	{
		hash += (str[i] - 'a' + 1) * p_pow;
		p_pow *= p;
		i++;
	}
	hash %= hasht_size;
	return (hash);
}

t_hasht		*create_hasht_elem(void *key, void *value)
{
	t_hasht		*elem;

	elem = (t_hasht*)malloc(sizeof(t_hasht));
	elem->key = (void*)key;
	elem->value = (void*)value;
	elem->next = NULL;
	return (elem);
}

t_map	*create_hash_table(int hasht_size)
{
	t_map		*map;
	int			i;

	i = 0;
	map = (t_map*)malloc(sizeof(t_map));
	map->size = hasht_size;
	map->hash_t = (t_hasht**)malloc(sizeof(t_hasht *) * map->size);
	map->hash_func = (void*)&hash_for_builtin;
	while (i < map->size)
		map->hash_t[i++] = NULL;
	return (map);
}

void	add_elem_to_hasht(t_map *head, char *key, void *value)
{
	// t_hasht		*elem;
	t_hasht		**tmp;
	long long	hash;

	// elem = create_hasht_elem(key, value);
	hash = hash_for_builtin(key, head->size);
	tmp = &(head->hash_t[hash]);
	if (*tmp == NULL)
		*tmp = create_hasht_elem(key, value);
	else
	{
		while ((*tmp)->next != NULL)
			tmp = &((*tmp)->next);
		if (ft_strcmp(key, (*tmp)->key) == 0)
			(*tmp)->value = value;
		else
			(*tmp)->next = create_hasht_elem(key, value);
	}
}

void	delete_hash_t(t_map *head)
{
	t_hasht		**tmp;
	t_hasht		*buf;
	int			i;
	// t_hasht		*temp;

	i = 0;
	tmp = (head->hash_t);
	while (i < head->size)
	{
		// if ((*tmp)->next != NULL)
		// {
		// 	buf = (*tmp)->next;
		// 	while (buf != NULL)
		// 	{
		// 		temp = buf;
		// 		buf = buf->next;
		// 		free(temp);
		// 	}
		// }
		// else
		// {
			buf = (*tmp);
			if (buf != NULL)
				free(buf);
			(*tmp)++;
			i++;

		// }
	}
	// free(head);
}
