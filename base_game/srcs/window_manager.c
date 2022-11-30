/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:47:35 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/30 21:55:41 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_game.h"

void	init_window()
{
	t_infos		*infos;

	infos = new_infos();
	mlx_key_hook(infos->mlx, &key_manager, infos);
	mlx_loop_hook(infos->mlx, &loop_manager, infos);
	mlx_resize_hook(infos->mlx, &hook_manager, infos);
	mlx_loop(infos->mlx);
}
