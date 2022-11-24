#include "solong.h"

void load_map(m_list *map)
{
    map -> i=0;
    map->fd = open(map->fname, O_RDONLY);
    while(read(map->fd,&map->c,1) > 0)
    {
        if(map->c!='\n')
        {
            map->map[map->i++]=map->c;
        }
    }
    map->map[map->i++]='\0';
    close(map->fd);
}
void print_map(m_list *map)
{
    int i;
    int j;
    i =0;
    
    while(i<map->height)
    {j=0;
        while(j<map->width)
        {write(1,&(map->map[(i*map->width)+j]),1);
        j++;
        }
        write(1,"\n",1);
        i++;

    }
}

void validate_wall(m_list *map)
{
    int i;
    int l;

    map->len = (map->width*map->height)-1;
    i = 0;
    while(i < map->width)
    {
        if(map->map[i] != '1' || map->map[(map->len)-i] != '1')
            error();
        i++;
    }

    i = 1;
     while(i < map->height)
    {
        l = map->width * i;
        if(map->map[l] != '1' || map->map[l+(map->width-1)] != '1')
            error();
        i++;
    }
}

int	ft_isnext_e(int ppos, m_list *map)
{
	if (map->map[ppos - map->width] == 'E' || map->map[ppos + 1] == 'E'
		|| map->map[ppos + map->width] == 'E' || map->map[ppos - 1] == 'E')
		return (1);
	return (0);
}

int	map_validpath(int ppos, m_list *map)
{
	int	res;

	res = 0;
	if (map->map[ppos] == 'C')
		map->coin_count++;
	map->map[ppos] = 'z';
	if (ft_isnext_e(ppos, map))
		map->isvalid = 1;
	if (map->map[ppos - map->width] != '1' && map->map[ppos - map->width] != 'z'
		&& map->map[ppos - map->width] != 'E')
		res = map_validpath(ppos - map->width, map);
	if (map->map[ppos + 1] != '1' && map->map[ppos + 1] != 'z'
		&& map->map[ppos + 1] != 'E')
		res = map_validpath(ppos + 1, map);
	if (map->map[ppos + map->width] != '1' && map->map[ppos + map->width] != 'z'
		&& map->map[ppos + map->width] != 'E')
		res = map_validpath(ppos + map->width, map);
	if (map->map[ppos - 1] != '1' && map->map[ppos - 1] != 'z'
		&& map->map[ppos - 1] != 'E')
		res = map_validpath(ppos - 1, map);
	return (res);
}