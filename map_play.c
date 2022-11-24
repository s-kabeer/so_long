#include "solong.h"

void move_player(int pos,m_list *map)
{ 
    
   

if(map->map[pos] == '0')
{
    map->map[map->ppos]='0';
    map->map[pos] = 'P';
    map->ppos = pos;
    map->moves++;
    ft_drawmap(map);
}
else if(map->map[pos] == 'X')
{
    map->map[map->ppos]='0';
    map->map[pos] = 'P';
    map->ppos = pos;
    map->moves++;
    ft_drawmap(map);
    error();
}
else if(map->map[pos] == 'C')
{
   map->map[map->ppos]='0';
    map->map[pos] = 'P';
    map->ppos = pos;
     map->moves++;
     map->coin_coll++;
     ft_drawmap(map);
}
else if(map->map[pos] == 'E')
{
    if(map->countc==map->coin_coll)
    {
    map->map[map->ppos]='0';
    map->ppos = pos;
    map->map[pos] = 'P';
    map->moves++;
    ft_drawmap(map);
    error();
    }
}

    
    //print_map(map);
  //  printf("\nNo of Moves:%d\nCoin Collected:%d\n",map->moves,map->coin_count);

}


int key_pressed(int c,m_list *map)
{
   // char a=c+48;
   // write(1,"hi",2);
    if(c==13)
    {
        move_player(map->ppos - map->width,map);
    }
    else if(c == 0)
    {
        move_player(map->ppos - 1,map);
    }
     else if(c == 2)
    {
        move_player(map->ppos + 1,map);
    }
    else if(c == 1)
    {
        move_player(map->ppos + map->width,map);
    }
return(0);
}

void move_enemy_up(m_list *map)
{
     static int flag=0;
    if(map->map[map->xpos-map->width] == '0'  && flag==0)
    {
       

        map->map[map->xpos]='0';
        map->xpos = map->xpos - map->width;
        map->map[map->xpos] = 'X';
      
    }
    else if(map->map[map->xpos+map->width] == '0')
    {
        
        map->map[map->xpos]='0';
        map->xpos = map->xpos +map->width;
        map->map[map->xpos] = 'X';
          if(map->map[map->xpos + map->width] != '0')
            flag =0;
       
    }
    usleep(100000);
     ft_drawmap(map);
    
}

void move_enemy_left(m_list *map)
{
  //  (void) *map;
  static int flag=0;
//    printf("\n%d",map->xpos);

    if(map->map[map->xpos+1] == '0' && flag==0)
    {
       
        map->map[map->xpos]='0';
        map->map[map->xpos+1] = 'X';
        map->xpos=map->xpos+        1;
       
    }
   else if(map->map[map->xpos-1] == '0')
    {
        flag =1;
       
        map->map[map->xpos]='0';
        map->map[map->xpos-1] = 'X';
        map->xpos=map->xpos-1;
       
        if(map->map[map->xpos-1] != '0')
            flag =0;
    }
    /*else if(map->map[map->xpos+map->width] == '0')
    {
        flag =1;
        map->map[map->xpos]='0';
        map->map[map->xpos+map->width] = 'X';
        map->xpos=map->xpos+map->width;
       
       // if(map->map[map->xpos+1] != '0')
        //    flag =0;
    }
    else if(map->map[map->xpos-map->width] == '0')
    {
        flag =1;
        map->map[map->xpos]='0';
        map->map[map->xpos-map->width] = 'X';
        map->xpos=map->xpos-map->width;
       
       // if(map->map[map->xpos+1] != '0')
        //    flag =0;
    }*/
        usleep(100000);
       ft_drawmap(map);
    



}

int move_enemy(m_list *map)
{
 if(map->map[map->xpos+1] == '0' || map->map[map->xpos-1] == '0'
 || map->map[map->xpos+1] == 'P' || map->map[map->xpos-1] == 'P')
 {
   if( map->map[map->xpos+1] == 'P' || map->map[map->xpos-1] == 'P')
   {
     ft_drawmap(map);
   error();
   }
 move_enemy_left(map);
 }
 else if(map->map[map->xpos+map->width] == '0' || map->map[map->xpos-map->width] == '0'
        || map->map[map->xpos+map->width] == 'P' || map->map[map->xpos-map->width] == 'P')
        if(map->map[map->xpos+map->width] == 'P' || map->map[map->xpos-map->width] == 'P')
        {
          ft_drawmap(map);
          error();
        }
   move_enemy_up(map);
   return(0);
}

