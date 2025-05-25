/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksupinsk <ksupinsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:42:10 by ksupinsk          #+#    #+#             */
/*   Updated: 2025/05/06 18:06:35 by ksupinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*dlst;
	t_list	*tmp;

	dlst = *lst;
	while (dlst != NULL)
	{
		tmp = dlst->next;
		ft_lstdelone(dlst, del);
		dlst = tmp;
	}
	*lst = NULL;
}
