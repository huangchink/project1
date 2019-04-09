#ifndef _CLASS_H_
#define _CLASS_H_
#include<iostream>
#include<curses.h>
#include<ctime>
#include<fstream>
#include<unistd.h>


using namespace std;
class crazy{
private:

int c,x=0,y=1;
time_t starttime,stoptime;
	int go_on=1;
	int minex;
        int miney;
	int height ;int width ;
int mines_in_a_row[20]={0};
public:
const int size=20;
	int mine=100;
	int notmine=300;
	int mine_info[20][20]={0};
	int map_pressed[20][20];

	
	WINDOW * win ;
	void setmine();//設置地雷的函數
        void setnumber();
	void setmap(int height ,int width ,int start_y,int start_x);
        void setstart();
        void getElapsedTime();
	void bang(int y, int x);
        void sethint();
        void lets_play_a_game();
        void getmap();



};
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
	int map_pressed[10][10];


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
