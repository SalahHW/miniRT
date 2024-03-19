
#ifndef RENDER_H
# define RENDER_H

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_mlx_session
{
	void	*mlx;
	void	*win;
	t_img	*image;
}			t_mlx_session;

void	init_camera_basis(t_base *base_cam, t_context *minirt);
int			run_rendering(t_context *context);
int			deal_key(int keycode, t_context *context);
int			init_mlx_session(t_context *context);
int			run_window(t_context *context);
int			close_window(t_context *context);

#endif