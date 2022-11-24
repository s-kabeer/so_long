#include "solong.h"

void init_map(m_list *map)
{
map->width = 0;
map->height = 0;
map->map = NULL;
map->i = 0;

map -> counte =0;
map -> countc =0;
map -> countp = 0;
map -> ppos = 0;
map -> countx = 0;
map -> xpos =0;
map ->coin_count=0;
map ->isvalid=0;
map->pm = 0;

map->coin_coll=0;
map->moves=0;


    map->wall = "./img/wall.xpm";
	map->floor = "./img/free_tile.xpm";
	map->door = "./img/door.xpm";
	map->coin = "./img/coin.xpm";
	map->player = "./img/knor.xpm";
	map->player_s = "./img/knor_s.xpm";
	map->enemy = "./img/enemy.xpm";

}

void map_char_check(int pos,char c,m_list *map)
{
    if(c == 'E')
        map->counte++;

    else if(c == 'C')
        map->countc++;

    else if(c == 'P')
        {
            map->countp++;
            map->ppos=pos;
        }
    else if(c == 'X')
    {
        map->countx++;
        map->xpos=pos;
    }
    else if(c != '1' && c!='0')
        error();

}
void map_validate_char(m_list *map)
{
    if(map->width)
    {
        if(map->width !=map->i)
        error();
    }
    map->height++;
    if(map->countc <= 0 || map->counte != 1 || map->countp != 1)
    error();
}

void set_map(m_list *map)
{
   
    map->n = read(map->fd,&map->c,1);
    while (map->n > 0)
    {
        if(map->c != '\n')
        {
        map_char_check((map->width*map->height)+map->i++, map->c,map);
        }
        else
        {
            if(!map->i)
            error();
            if(map->width)
            {
                if(map->width != map->i)
                error();

            }
            else
                map->width = map->i;
            map->height++;
            map->i=0;
        }
        map->n = read(map->fd,&map->c,1);
    }

   map_validate_char(map);   

}
void read_map(m_list *map)
{
 map->fd = open(map->fname, O_RDONLY);
set_map(map);
close(map->fd);
map->map=(char*) malloc(map->width*map->height+1);
load_map(map);

validate_wall(map);
map_validpath(map->ppos,map);
if (!map->isvalid || (map->countc != map->coin_count))
		error();
        load_map(map);
//print_map(map);
}
