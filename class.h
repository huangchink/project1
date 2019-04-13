#ifndef _CLASS_H_
#define _CLASS_H_
#include<iostream>
#include<curses.h>
#include<ctime>
#include<fstream>
#include<unistd.h>


using namespace std;
//瘋狂難度
class crazy{
private:

int c,x=0,y=1;
time_t starttime,stoptime;//計時用的
	int go_on=1;
	int minex;
        int miney;
	int height ;int width ;
int mines_in_a_row[20]={0};//每一列總共有幾個地雷

public:
const int size=20; //尺寸
	int mine=100;//地雷數量
	int notmine=400-mine;//非地雷數量
	int mine_info[20][20]={0};//格子裡面存啥
	int map_pressed[20][20]={0};//紀錄格子是否被踩過

	
	WINDOW * win ;
	void setmine();//設置地雷的函數
        void setnumber();//設數字
	void setmap(int height ,int width ,int start_y,int start_x);//設地雷
        void setstart();//設時間
        void getElapsedTime();//計時
	void bang(int y, int x);//加分題(連環爆)
        void sethint();//設置提示
        void lets_play_a_game();//開玩
        void getmap();//output map



};
//新手難度
class easy {
private:

	int c, x = 0, y = 1;
	time_t starttime, stoptime;
	int go_on = 1;
	int minex;
	int miney;
	int height; int width;
	int mines_in_a_row[10] = { 0 };
public:
	const int size = 10;
	int mine = 10;
	int notmine = 90;
	int mine_info[10][10] = { 0 };
	int map_pressed[10][10]={0};


	WINDOW * win;
	void setmine();//設置地雷的函數
	void setnumber();
	void setmap(int height, int width, int start_y, int start_x);
	void setstart();
	void getElapsedTime();
	void bang(int y, int x);
	void sethint();
	void lets_play_a_game();
	void getmap();


};








#endif
