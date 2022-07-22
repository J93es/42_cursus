/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mijung <mijung@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 21:11:48 by mijung            #+#    #+#             */
/*   Updated: 2022/07/11 21:11:51 by mijung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = 0;
	if (*lst == 0)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = new;
}
