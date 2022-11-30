/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_game.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:45:24 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/30 22:00:31 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHYSICS_H
# define PHYSICS_H

# include "libft.h"
# include "MLX42.h"
# include <stdio.h>
# include "struct.h"

# define W_WIDTH 1920
# define W_HEIGHT 1080

# define p_coords infos->player->coords
# define p_grounded infos->player->is_grounded
# define p_img infos->player->img

# define pt_img infos->plateformes->img
# define pt_coords infos->plateformes->coords
# define pt_index infos->plateformes->index

# define BASIC_P infos->plt_imgs[0]

# define DIFPLT_NBR 1
# define X_SPEED 6
# define X_MAXSPEED 20
# define Y_SPEED 120
# define PLAYER_SIZE 64
# define A_KEY mlx_is_key_down(infos->mlx, MLX_KEY_A)
# define D_KEY mlx_is_key_down(infos->mlx, MLX_KEY_D)
# define LEFT_KEY mlx_is_key_down(infos->mlx, MLX_KEY_LEFT)
# define RIGHT_KEY mlx_is_key_down(infos->mlx, MLX_KEY_RIGHT)
# define IS_SPACE keydata.key == MLX_KEY_SPACE
# define IS_UP keydata.key == MLX_KEY_UP
# define IS_W keydata.key == MLX_KEY_W
# define IS_PRESSED keydata.action == MLX_PRESS

// pseudo_physic
void			move_player(t_infos *infos);
void			hook_manager(int width, int height, void *param);
void			loop_manager(void *param);
void			key_manager(mlx_key_data_t keydata, void *param);
void			init_window();
void			print_player_stats(t_infos *infos);

// struct init
t_infos			*new_infos();
t_player		*new_player(mlx_t *mlx, t_coords *coords);
t_coords		*new_coords(size_t x, size_t y);

// init img
mlx_image_t		**init_pltimgs(t_infos *infos);

// plateforme gestionnaire
size_t			plt_nbr(t_plt *plat);
void			add_plt(t_infos *infos, t_plt *n_plat);
void			create_collplt(t_infos *infos, t_coords *coords, size_t *size);
t_plt			*new_plt(t_infos *infos, t_coords *coords, size_t *size);

// view
void		render_player(t_infos *infos);
void    	render_basic_plt(t_plt *plt, mlx_image_t *img);

#endif