#include "fdfStuff/minilibx_macos/mlx.h"

int deal(int key, void *param)//void* win_ptr, void* mlx_point)
{
    // printf("%d ", key)
    if (key == 53)
        exit(0);
        
    return(0);
}

int main()
{
    void *win_ptr;
    void *img_ptr;
     void *mlx_point = mlx_init();
    win_ptr = mlx_new_window(mlx_point, 400, 400, "Marinella");
    
    for (int i = 200; i <= 250; i++)
    {
        mlx_pixel_put(mlx_point, win_ptr, i, 200, 0xFFFFFF);
        mlx_pixel_put(mlx_point, win_ptr, 200, i, 0xFFFFF);
        mlx_pixel_put(mlx_point, win_ptr, i, 250, 0xFFFF);
        mlx_pixel_put(mlx_point, win_ptr, 250, i, 0xFFF);
    }
    mlx_string_put(mlx_point, win_ptr, 170, 1, 0xFFFF, "fuck_fdf");
    img_ptr = mlx_new_image(mlx_point, 50, 70);
    mlx_put_image_to_window(mlx_point, win_ptr, img_ptr, 0, 300);
    mlx_key_hook(win_ptr, deal, (void*)0);
    mlx_loop(mlx_point);
}