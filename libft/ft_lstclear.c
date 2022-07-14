/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:11:58 by mijung            #+#    #+#             */
/*   Updated: 2022/07/11 21:12:02 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*begin;

	if (lst == 0 || *lst == 0)
		return ;
	begin = *lst;
	while (begin != 0)
	{
		temp = begin;
		del(begin->content);
		begin = begin->next;
		free(temp);
	}
	*lst = 0;
}
