#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*s;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = ft_lstnew(f(lst->content));
	if (tmp == NULL)
	{
		ft_lstclear(&tmp, del);
		return (NULL);
	}
	s = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&s, del);
			return (NULL);
		}
		ft_lstadd_back(&s, tmp);
		lst = lst->next;
	}
	return (s);
}
