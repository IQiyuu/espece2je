/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:44:34 by dgoubin           #+#    #+#             */
/*   Updated: 2022/11/30 22:00:37 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_plt	t_plt;
struct s_plt
{
	t_coords		*coords;
	size_t			x_size;
	size_t			y_size;
	size_t			index;
	int				collision;
	t_plt	*next;
};

typedef struct s_player
{
	t_coords	*coords;
	float		horizontal_acc;
	float		vertical_acc;
	int			is_grounded;
	int			double_jump;
	mlx_image_t	*img;
}	t_player;

typedef struct s_infos
{
	mlx_t 			*mlx;
	t_player 		*player;
	t_plt			*plts;
	mlx_image_t		**plt_imgs;
}	t_infos;

#endif