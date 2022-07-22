/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:12:16 by mijung            #+#    #+#             */
/*   Updated: 2022/07/12 13:16:02 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dst;
	t_list	*temp;

	if (lst == 0)
		return (0);
	dst = ft_lstnew(f(lst->content));
	if (dst == 0)
		return (0);
	lst = lst->next;
	while (lst != 0)
	{
		temp = ft_lstnew(f(lst->content));
		if (!temp)
		{
			ft_lstclear(&dst, del);
			return (0);
		}
		ft_lstadd_back(&dst, temp);
		lst = lst->next;
	}
	return (dst);
}
