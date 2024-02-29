#include "../../include/miniRT.h"

int init_mlx_session(t_context *context)
{
    t_mlx_session *mlx_session;

    mlx_session = (t_mlx_session *)malloc(sizeof(t_mlx_session));
    if (!mlx_session)
        return (print_error("Failed to allocate memory for mlx"));
    context->mlx_session = mlx_session;
    context->mlx_session->mlx = mlx_init();
    return (SUCCESS);
}