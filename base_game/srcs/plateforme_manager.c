/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plt_manager.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:49:38 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/30 21:39:24 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_game.h"

void	add_plt(t_infos *infos, t_plt *n_plt)
{
	if (infos->plts)
	{
		while (infos->plts->next)
			infos->plts = infos->plts->next;
		infos->plts->next = n_plt;
	}
	else
		infos->plts = n_plt;
}

size_t	plt_nbr(t_plt *plt)
{
	size_t	cpt = 0;

	while (plt)
	{
		cpt++;
		plt = plt->next;
	}
	return (cpt);
}

void	create_collplteforme(t_infos *infos, t_coords *coords, size_t *size)
{
	if (coords->x > -size[0] + 64 && coords->x < W_WIDTH - 64 && coords->y > -size[1] + 64 && coords->y < W_HEIGHT - 64)
		add_plt(infos, new_plt(infos, coords, size));
}