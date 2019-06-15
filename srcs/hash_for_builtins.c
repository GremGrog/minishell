#include "../minishell.h"

long long	hash_for_builtin(char *str)
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
	hash %= 20;
	return (hash);
}

void		set_htabsize(int newsize)
{
	g_htabsize = newsize * 7;
}

t_hasht		*create_elem(void *key, void *value)
{
	t_hasht		*elem;

	elem = (t_hasht*)malloc(sizeof(t_hasht));
	elem->key = (void*)key;
	elem->value = (void*)value;
	elem->next = NULL;
	return (elem);
}

t_hasht		*copy_elem(t_hasht *dst, t_hasht *elem)
{
	dst->key = elem->key;
	dst->value = elem->value;
	return (dst);
}

void	create_hash_table()
{
	t_hasht		*arr[20];
	t_hasht 	*ls;
	long long	hash;
	int			i;

	i = 0;
	while (i < 20)
		arr[i++] = create_elem(NULL, NULL);
	ls = create_elem("kek", &ft_printf);
	hash = hash_for_builtin((char*)ls->key);
	if (arr[hash])
	{
		if (arr[hash]->key != NULL)
			return ;
		free(arr[hash]);
	}
	arr[hash] = ls;
	// for (int i = 0; i < 20; i++)
	// 	ft_printf("%d %s\n", i, arr[i]->key);
	i = 0;
	while (i < 20)
		free(arr[i++]);
	// free(&ls);
	// free(ls);
	// int (*check) (char*, ...);

	// ls = (t_hasht*)malloc(sizeof(t_hasht));
	// ls->key = (char*)"echo";
	// ls_2 = (t_hasht*)malloc(sizeof(t_hasht));
	// ls_2->key = (char*)"git";
	// cd = (t_hasht*)malloc(sizeof(t_hasht));
	// cd->key = (char*)"valgrind";
	// pwd = (t_hasht*)malloc(sizeof(t_hasht));
	// pwd->key = (char*)"rm";
	// arr[hash_for_builtin(ls->key)] = *ls;
	// arr[hash_for_builtin(cd->key)] = *cd;
	// arr[hash_for_builtin(pwd->key)] = *pwd;
	// arr[hash_for_builtin(ls_2->key)] = *ls_2;


	// pwd->value = (void*)&ft_printf;
	// check = pwd->value;
	// check("hello\n");
}
