/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wding-ha <wding-ha@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 21:27:28 by wding-ha          #+#    #+#             */
/*   Updated: 2021/05/23 22:06:28 by wding-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*hold;

	hold = (t_list *)malloc(sizeof(hold));
	if (!hold)
		return (NULL);
	hold->content = content;
	hold->next = NULL;
	return (hold);
}
