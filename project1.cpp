#include<curses.h>
#include<iostream>
#include<ctime>
#include<fstream>
#include"class.h"
#include<unistd.h>
using namespace std;
int height,width,start_y,start_x;
int main()
{
bool crazy_endgame=false;  //THanos will paid for it
bool easy_endgame=false;
srand(time(0));
initscr();
clear();
refresh();
attrset(A_BOLD);
mvaddstr(0,0,"welcome to minesweeper");
mvaddstr(1,0,"please choose 1. easy or 2.crazy");//讓玩家選擇難度
int c;
c=getch();
clear();
refresh();
switch(c)// 選擇難度
{
case '2' :
	{
start_y=0,start_x=0;
height=22;
width=22;
crazy Crazy;
Crazy.setmap(height,width,start_y,start_x);//架設地圖

Crazy.setmine();//設置地雷
Crazy.setnumber();//設置數字
Crazy.sethint();//設置提示
Crazy.lets_play_a_game();//開玩
//crazy_endgame = true;//win或者是lose
Crazy.getmap();//輸出 map到Mine.txt(請用cat指令打開)


	break;
	}
	case '1':

start_y=0,start_x=0;
height=12;
width=12;
easy Easy;
Easy.setmap(height, width, start_y, start_x);//架設地圖

Easy.setmine();//設置地雷
Easy.setnumber();//設置數字
Easy.sethint();//設置提示
Easy.lets_play_a_game();//開玩
						 //crazy_endgame = true;//win或者是lose
Easy.getmap();//輸出 map到Mine.txt(請用cat指令打開)

break;

}
endwin();

return 0;
} // main( )

