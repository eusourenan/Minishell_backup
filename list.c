#include "header.h"

void	free_list(t_env **list)
{
	t_env	*aux;

	if (list == NULL)
		return ;
	aux = *list;
	while (aux)
	{
		free(aux->var);
		*list = aux->next;
		free(aux);
		aux = *list;
	}
}

void	add_back(t_env **list, t_env *node)
{
	t_env	*aux;

	if (list == NULL)
		return ;
	if (*list == NULL)
	{
		*list = node;
		return ;
	}
	aux = *list;
	while (aux->next)
		aux = aux->next;
	aux->next = node;
}

t_env	*new_node(char *value)
{
	t_env	*node;
	char	*copy;

	node = (t_env *)malloc(sizeof(t_env));
	if (node == NULL)
		return (NULL);
	copy = ft_strdup(value);
	if (copy == NULL)
	{
		free(node);
		return (NULL);
	}
	node->var = copy;
	node->next = NULL;
	return (node);
}

size_t	list_size(t_env *list)
{
	size_t	size;

	size = 0;
	if (list == NULL)
		return (size);
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}
