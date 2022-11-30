/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:00:08 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/30 22:03:07 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_game.h"

void	render_player(t_infos *infos)
{
	p_img->instances[0].y = p_coords->y;
	p_img->instances[0].x = p_coords->x;
}

void	render_basic_plt(t_plt *plt, mlx_image_t *img)
{
	while (plt)
	{
		img->instances[plt->index].x = plt->coords->x;
		img->instances[plt->index].y = plt->coords->y;
	}
}
