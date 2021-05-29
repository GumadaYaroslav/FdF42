#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	t_list	*s;

	if (!*lst)
	{
		*lst = nw;
		return ;
	}
	s = ft_lstlast(*lst);
	s->next = nw;
}
