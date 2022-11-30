/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stats.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:43:53 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/30 21:21:26 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_game.h"

void	print_player_stats(t_infos *infos)
{
	printf("===== player stats =====\n");
	printf("coords : (%f,%f)\n", p_coords->x, p_coords->y);
	printf("horizontal accel : %f\n", infos->player->horizontal_acc);
	printf("vertical accel : %f\n", infos->player->vertical_acc);
	printf("is grounded : %d\n", p_grounded);
	printf("double jump up : %d\n", infos->player->double_jump);
	printf("=====      end     =====\n");
}