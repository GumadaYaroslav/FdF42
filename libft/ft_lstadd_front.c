#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *nw)
{
	if (lst && nw)
	{
		nw->next = *lst;
		*lst = nw;
	}
}
