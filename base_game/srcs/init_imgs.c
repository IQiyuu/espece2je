/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:42:32 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/30 22:12:16 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "base_game.h"

mlx_image_t	**init_pltimgs(t_infos *infos)
{
	mlx_image_t	**imgs = (mlx_image_t **)malloc(sizeof(mlx_image_t *) * DIFPLT_NBR);
	imgs[0] = mlx_texture_to_image(infos->mlx, mlx_load_png("base_game/imgs/basic_plateforme.png"));
	return (imgs);
}