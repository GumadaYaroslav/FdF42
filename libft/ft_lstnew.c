#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(t_list));
	if (elem)
	{
		elem->next = NULL;
		elem->content = content;
	}
	else
		return (NULL);
	return (elem);
}
