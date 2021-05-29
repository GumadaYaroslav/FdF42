#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst == NULL)
		return ;
	tmp = *lst;
	while (*lst)
	{
		tmp = *lst;
		del((*lst)->content);
		*lst = (*lst)->next;
		free(tmp);
	}
}
