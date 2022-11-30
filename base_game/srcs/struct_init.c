/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:42:11 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/30 22:03:00 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_game.h"

t_coords	*new_coords(size_t x, size_t y)
{
	t_coords	*coords;

	coords = (t_coords *)malloc(sizeof(t_coords));
	coords->x = x;
	coords->y = y;
	return (coords);
}

t_player	*new_player(mlx_t *mlx, t_coords *coords)
{
	t_player	*player;

	player = (t_player *)malloc(sizeof(t_player));
	player->coords = coords;
	player->horizontal_acc = 0;
	player->vertical_acc = 0;
	player->is_grounded = 1;
	player->double_jump = 1;
	player->img = mlx_texture_to_image(mlx, mlx_load_png("base_game/imgs/player.png"));
	return (player);
}

t_infos	*new_infos()
{
	t_infos	*infos;
	
	infos = (t_infos *)malloc(sizeof(t_infos));
	infos->mlx = mlx_init(W_WIDTH, W_HEIGHT, "MLX42", true);
	infos->player = new_player(infos->mlx, new_coords(0, W_HEIGHT - PLAYER_SIZE));
	infos->plt_imgs = init_pltimgs(infos);
	mlx_image_to_window(infos->mlx, infos->player->img, p_coords->x, p_coords->y);
	return (infos);
}

t_plt	*new_plt(t_infos *infos, t_coords *coords, size_t *size)
{
	t_plt	*plt;
	
	plt = (t_plt *)malloc(sizeof(t_plt));
	plt->coords = coords;
	plt->x_size = size[0];
	plt->y_size = size[1];
	plt->collision = 1;
	plt->index = plt_nbr(infos->plts) + 1;
	return (plt);
}