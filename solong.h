#ifndef SOLONG_H
#define SOLONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "minilibx/mlx.h"


typedef struct map_details
{
char *fname;
int fd;
int width;
int height;
int len;
char *map;
char c;
int n;
int  i;

int counte;
int countc;
int countp;
int ppos;
int countx;
int xpos;
int coin_count;
int coin_coll;
int moves;
int isvalid;

    void	*mlx;
	void	*win;
    char	*wall;
	char	*floor;
	char	*door;
	char	*coin;
	char	*player;
	char	*player_s;
	char	*enemy;
    int		img_width;
	int		img_height;
    int  pm;
    void	*img;


} m_list;

void init_map(m_list *map);
void map_char_check(int pos,char c,m_list *map);
void map_validate_char(m_list *map);
void set_map(m_list *map);
void read_map(m_list *map);
void error();
void load_map(m_list *map);
void print_map(m_list *map);
void validate_wall(m_list *map);
int	ft_isnext_e(int ppos, m_list *map);
int	map_validpath(int ppos, m_list *map);

void	ft_drawhelp(m_list *map, char *img);
void	ft_drawelement(m_list *map, int len);
void	ft_drawmap(m_list *map);
char	*ft_itoa(int n);
int	ft_closewin(m_list *map, int fdflag);
int key_pressed(int c,m_list *map);
int move_enemy(m_list *map);


#endif
