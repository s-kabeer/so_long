#include "solong.h"

void	ft_drawhelp(m_list *map, char *img)
{
	map->img = mlx_xpm_file_to_image(map->mlx, img, \
		&map->img_width, &map->img_height);
}

void	ft_drawelement(m_list *map, int len)
{
	if (*(map->map + len) == '1')
		ft_drawhelp(map, map->wall);
	else if (*(map->map + len) == '0')
		ft_drawhelp(map, map->floor);
    else if (*(map->map + len) == 'X')
		ft_drawhelp(map, map->enemy);
	else if (*(map->map + len) == 'E')
		ft_drawhelp(map, map->door);
	else if (*(map->map + len) == 'C')
		ft_drawhelp(map, map->coin);
	else if (*(map->map + len) == 'P')
	{
		if (map->pm % 2)
			ft_drawhelp(map, map->player);
		else
			ft_drawhelp(map, map->player_s);
	}
	else if (*(map->map + len) == 'M')
		ft_drawhelp(map, map->enemy);
}

void	ft_drawmap(m_list *map)
{
	int	len;
	int	w;
	int	h;

	w = 0;
	h = 0;
	len = 0;
    
	while (*(map->map + len))
	{	
		ft_drawelement(map, len);
       
		mlx_put_image_to_window(map->mlx, map->win, map->img, w, h);
        
		w += map->img_width;
		len++;
		if (!(len % map->width))
		{
			w = 0;
			h += map->img_height;
		}
	}
	mlx_string_put(map->mlx, map->win, 20, 20, 0xFFFF5615, ft_itoa(map->moves));
}