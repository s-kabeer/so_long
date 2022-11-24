#include "solong.h"


void error()
{
    printf("Error\n");
    exit(1);

}
int	ft_closewin(m_list *map, int fdflag)
{
    (void) map;
    (void) fdflag;
    
     printf("Game over\n");
    exit(1);
}
int validate_filename(char *fname)
{
    int i;
    i = 0;
    while(fname[i] != '\0')
    {
        if(fname[i] == '.')
        {
            if(fname[i+1] == 'b' && fname[i+2] == 'e' && fname[i+3] == 'r' && fname[i+4] == '\0')
                return (1);
        }
        i++;
    }
    return (0);
}

int main(int n,char *ar[])
{
    if(n == 2)
    {
        m_list map;
        map.fname=ar[1];
        if(!validate_filename(map.fname))
        error();
        
        init_map(&map);
        
        read_map(&map);
      
        map.mlx = mlx_init();
        map.img_height=map.height*48;
        map.img_width=map.width*48;
	map.win = mlx_new_window(map.mlx, (map.width*48), \
		(map.height*48), "Welcome");
	ft_drawmap(&map);
//mlx_loop(map.mlx);
mlx_key_hook(map.win, key_pressed, &map);
	mlx_hook(map.win, 17, 0, ft_closewin, &map);
    mlx_loop_hook(map.mlx, move_enemy, &map);
    mlx_loop(map.mlx);
      //  printf("\nWidth: %d\n Height:%d \n",map.width,map.height);
    }

}

