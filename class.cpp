#include<curses.h>
#include<iostream>
#include<ctime>
#include"class.h"
#include<fstream>
#include<unistd.h>
using namespace std;
void crazy::setmine()//設置地雷的函數
{
	for (int i = 0; i < mine; i++)//放地雷，為了跟數字做區隔所以設為-1
	{

		minex = rand() % size;
		miney = rand() % size;
		if (mine_info[miney][minex] == -1)
		{
			i--;
		}
		else
		{
			mine_info[miney][minex] = -1;
		}
	}

}
void easy::setmine()//設置地雷的函數
{
	for (int i = 0; i < mine; i++)//放地雷，為了跟數字做區隔所以設為-1
	{

		minex = rand() % size;
		miney = rand() % size;
		if (mine_info[miney][minex] == -1)
		{
			i--;
		}
		else
		{
			mine_info[miney][minex] = -1;
		}
	}
}

void crazy ::setnumber()
{
	int number;
	for (int i = 1; i<size - 1; i++)//鄰近8個的
	{
		for (int j = 1; j<size - 1; j++)
		{
			if (mine_info[i][j] != -1)
			{
				number = 0;
				if (mine_info[i - 1][j] == -1) { number++; }
				if (mine_info[i + 1][j] == -1) { number++; }
				if (mine_info[i - 1][j - 1] == -1) { number++; }
				if (mine_info[i][j - 1] == -1) { number++; }
				if (mine_info[i + 1][j - 1] == -1) { number++; }
				if (mine_info[i - 1][j + 1] == -1) { number++; }
				if (mine_info[i][j + 1] == -1) { number++; }
				if (mine_info[i + 1][j + 1] == -1) { number++; }
				mine_info[i][j] = number;
			}
		}

	}

	number = 0;
	if (mine_info[0][0] != -1)//鄰近三個的
	{
		if (mine_info[1][0] == -1)
		{
			number++;
		}
		if (mine_info[0][1] == -1)
		{
			number++;
		}
		if (mine_info[1][1] == -1)
		{
			number++;
		}
		mine_info[0][0] = number;

	}

	number = 0;
	if (mine_info[19][0] != -1)//鄰近三個的

	{
		if (mine_info[19][1] == -1)
		{
			number++;
		}
		if (mine_info[18][0] == -1)
		{
			number++;
		}
		if (mine_info[18][1] == -1)
		{
			number++;
		}
		mine_info[19][0] = number;

	}
	number = 0;
	if (mine_info[0][19] != -1)//鄰近三個的

	{
		if (mine_info[1][19] == -1)
		{
			number++;
		}
		if (mine_info[0][18] == -1)
		{
			number++;
		}
		if (mine_info[1][18] == -1)
		{
			number++;
		}

		mine_info[0][19] = number;

	}
	number = 0;
	if (mine_info[19][19] != -1)//鄰近三個的

	{
		if (mine_info[18][19] == -1)
			number++;
		if (mine_info[19][18] == -1)
			number++;
		if (mine_info[18][18] == -1)
			number++;

		mine_info[19][19] = number;

	}
	number = 0;
	for (int j = 1; j<size - 1; j++)//鄰近五個的

	{
		number = 0;
		if (mine_info[0][j] != -1)
		{
			if (mine_info[0][j + 1] == -1)
			{
				number++;
			}
			if (mine_info[0][j - 1] == -1)
			{
				number++;
			}
			if (mine_info[1][j] == -1)
			{
				number++;
			}
			if (mine_info[1][j - 1] == -1)
			{
				number++;
			}
			if (mine_info[1][j + 1] == -1)
			{
				number++;
			}

			mine_info[0][j] = number;
		}
	}
	number = 0;
	for (int j = 1; j<size - 1; j++)//鄰近五個的

	{
		number = 0;
		if (mine_info[19][j] != -1)
		{
			if (mine_info[19][j - 1] == -1)
			{
				number++;
			}
			if (mine_info[19][j + 1] == -1)
			{
				number++;
			}
			if (mine_info[18][j] == -1)
			{
				number++;
			}
			if (mine_info[18][j - 1] == -1)
			{
				number++;
			}
			if (mine_info[18][j + 1] == -1)
			{
				number++;
			}


			mine_info[19][j] = number;
		}
	}
	number = 0;
	for (int i = 1; i<size - 1; i++)//鄰近五個的

	{
		number = 0;
		if (mine_info[i][0] != -1)
		{
			if (mine_info[i + 1][0] == -1)
			{
				number++;
			}

			if (mine_info[i - 1][0] == -1)
			{
				number++;
			}

			if (mine_info[i][1] == -1)
			{
				number++;
			}
			if (mine_info[i - 1][1] == -1)
			{
				number++;
			}
			if (mine_info[i + 1][1] == -1)
			{
				number++;
			}


			mine_info[i][0] = number;
		}
	}


	for (int i = 1; i<size - 1; i++)//鄰近五個的

	{
		number = 0;
		if (mine_info[i][19] != -1)
		{
			if (mine_info[i + 1][19] == -1)
			{
				number++;
			}

			if (mine_info[i - 1][19] == -1)
			{
				number++;
			}

			if (mine_info[i][18] == -1)
			{
				number++;
			}
			if (mine_info[i - 1][18] == -1)
			{
				number++;
			}
			if (mine_info[i + 1][18] == -1)
			{
				number++;
			}

			mine_info[i][19] = number;
		}


	}

}



void easy::setnumber()
{
	int number;
	for (int i = 1; i<size - 1; i++)//鄰近8個的
	{
		for (int j = 1; j<size - 1; j++)
		{
			if (mine_info[i][j] != -1)
			{
				number = 0;
				if (mine_info[i - 1][j] == -1) { number++; }
				if (mine_info[i + 1][j] == -1) { number++; }
				if (mine_info[i - 1][j - 1] == -1) { number++; }
				if (mine_info[i][j - 1] == -1) { number++; }
				if (mine_info[i + 1][j - 1] == -1) { number++; }
				if (mine_info[i - 1][j + 1] == -1) { number++; }
				if (mine_info[i][j + 1] == -1) { number++; }
				if (mine_info[i + 1][j + 1] == -1) { number++; }
				mine_info[i][j] = number;
			}
		}

	}

	number = 0;
	if (mine_info[0][0] != -1)//鄰近三個的
	{
		if (mine_info[1][0] == -1)
		{
			number++;
		}
		if (mine_info[0][1] == -1)
		{
			number++;
		}
		if (mine_info[1][1] == -1)
		{
			number++;
		}
		mine_info[0][0] = number;

	}

	number = 0;
	if (mine_info[9][0] != -1)//鄰近三個的

	{
		if (mine_info[9][1] == -1)
		{
			number++;
		}
		if (mine_info[8][0] == -1)
		{
			number++;
		}
		if (mine_info[8][1] == -1)
		{
			number++;
		}
		mine_info[9][0] = number;

	}
	number = 0;
	if (mine_info[0][9] != -1)//鄰近三個的

	{
		if (mine_info[1][9] == -1)
		{
			number++;
		}
		if (mine_info[0][8] == -1)
		{
			number++;
		}
		if (mine_info[1][8] == -1)
		{
			number++;
		}

		mine_info[0][9] = number;

	}
	number = 0;
	if (mine_info[9][9] != -1)//鄰近三個的

	{
		if (mine_info[8][9] == -1)
			number++;
		if (mine_info[9][8] == -1)
			number++;
		if (mine_info[8][8] == -1)
			number++;

		mine_info[9][9] = number;

	}
	number = 0;
	for (int j = 1; j<size - 1; j++)//鄰近五個的

	{
		number = 0;
		if (mine_info[0][j] != -1)
		{
			if (mine_info[0][j + 1] == -1)
			{
				number++;
			}
			if (mine_info[0][j - 1] == -1)
			{
				number++;
			}
			if (mine_info[1][j] == -1)
			{
				number++;
			}
			if (mine_info[1][j - 1] == -1)
			{
				number++;
			}
			if (mine_info[1][j + 1] == -1)
			{
				number++;
			}

			mine_info[0][j] = number;
		}
	}
	number = 0;
	for (int j = 1; j<size - 1; j++)//鄰近五個的

	{
		number = 0;
		if (mine_info[9][j] != -1)
		{
			if (mine_info[9][j - 1] == -1)
			{
				number++;
			}
			if (mine_info[9][j + 1] == -1)
			{
				number++;
			}
			if (mine_info[8][j] == -1)
			{
				number++;
			}
			if (mine_info[8][j - 1] == -1)
			{
				number++;
			}
			if (mine_info[8][j + 1] == -1)
			{
				number++;
			}


			mine_info[9][j] = number;
		}
	}
	number = 0;
	for (int i = 1; i<size - 1; i++)//鄰近五個的

	{
		number = 0;
		if (mine_info[i][0] != -1)
		{
			if (mine_info[i + 1][0] == -1)
			{
				number++;
			}

			if (mine_info[i - 1][0] == -1)
			{
				number++;
			}

			if (mine_info[i][1] == -1)
			{
				number++;
			}
			if (mine_info[i - 1][1] == -1)
			{
				number++;
			}
			if (mine_info[i + 1][1] == -1)
			{
				number++;
			}


			mine_info[i][0] = number;
		}
	}


	for (int i = 1; i<size - 1; i++)//鄰近五個的

	{
		number = 0;
		if (mine_info[i][9] != -1)
		{
			if (mine_info[i + 1][9] == -1)
			{
				number++;
			}

			if (mine_info[i - 1][9] == -1)
			{
				number++;
			}

			if (mine_info[i][8] == -1)
			{
				number++;
			}
			if (mine_info[i - 1][8] == -1)
			{
				number++;
			}
			if (mine_info[i + 1][8] == -1)
			{
				number++;
			}

			mine_info[i][9] = number;
		}


	}

}














void crazy:: setmap(int height, int width, int start_y, int start_x)
{
	win = newwin(height, width, start_y, start_x);
	refresh();
	box(win, 0, 0);
	wprintw(win, "map");
	wrefresh(win);
}

void easy::setmap(int height, int width, int start_y, int start_x)
{
	win = newwin(height, width, start_y, start_x);
	refresh();
	box(win, 0, 0);
	wprintw(win, "map");
	wrefresh(win);
}
void crazy::setstart()
{
	starttime = time(NULL);
}
void easy::setstart()
{
	starttime = time(NULL);
}
void crazy::getElapsedTime() {
	time(&stoptime);
	mvprintw(0, 24, "Time(elapsed    seconds):");
	mvprintw(0, 37, "%d", stoptime - starttime);


}

void easy::getElapsedTime() {
	time(&stoptime);
	mvprintw(0, 24, "Time(elapsed    seconds):");
	mvprintw(0, 37, "%d", stoptime - starttime);


}

void crazy::bang(int y, int x)//uncover the adjacent squares
{

	if ((mine_info[y][x] == 0) && (y > 0) && (y < 19) && (x > 0) && (x < 19))
	{
		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)
		{
			mvprintw(y, x + 1, "%d", crazy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)
		{
			mvprintw(y + 2, x + 1, "%d", crazy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);

		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)
		{
			mvprintw(y + 1, x + 2, "%d", crazy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] = 1;
			bang(y, x + 1);

		}
		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)
		{
			mvprintw(y + 1, x, "%d", crazy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);

		}
		if (mine_info[y - 1][x - 1] != -1 && map_pressed[y - 1][x - 1] == 0)
		{
			mvprintw(y, x, "%d", crazy::mine_info[y - 1][x - 1]);
			notmine--;
			map_pressed[y - 1][x - 1] = 1;
			bang(y - 1, x - 1);

		}
		if (mine_info[y + 1][x - 1] != -1 && map_pressed[y + 1][x - 1] == 0)
		{
			mvprintw(y + 2, x, "%d", crazy::mine_info[y + 1][x - 1]);
			notmine--;
			map_pressed[y + 1][x - 1] = 1;
			bang(y + 1, x - 1);

		}
		if (mine_info[y - 1][x + 1] != -1 && map_pressed[y - 1][x + 1] == 0)
		{
			mvprintw(y, x + 2, "%d", crazy::mine_info[y - 1][x + 1]);
			notmine--;
			map_pressed[y - 1][x + 1] = 1;
			bang(y - 1, x + 1);

		}
		if (mine_info[y + 1][x + 1] != -1 && map_pressed[y + 1][x + 1] == 0)
		{
			mvprintw(y + 2, x + 2, "%d", crazy::mine_info[y + 1][x + 1]);
			notmine--;
			map_pressed[y + 1][x + 1] = 1;
			bang(y + 1, x + 1);

		}

	}


	else if ((mine_info[y][x] == 0) && (x == 0) && (y == 0))
	{
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)
		{
			mvprintw(y + 2, x + 1, "%d", crazy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);
		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)
		{
			mvprintw(y + 1, x + 2, "%d", crazy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] == 1;
			bang(y, x + 1);
		}
		if (mine_info[y + 1][x + 1] != -1 && map_pressed[y + 1][x + 1] == 0)
		{
			mvprintw(y + 2, x + 2, "%d", crazy::mine_info[y + 1][x + 1]);
			notmine--;
			map_pressed[y + 1][x + 1] = 1;
			bang(y + 1, x + 1);
		}
	}
	else if ((mine_info[y][x] == 0) && (x == 0) && (y == 19))
	{
		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)
		{
			mvprintw(y, x + 1, "%d", crazy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)
		{
			mvprintw(y + 1, x + 2, "%d", crazy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] = 1;
			bang(y, x + 1);
		}
		if (mine_info[y - 1][x + 1] != -1 && map_pressed[y - 1][x + 1] == 0)
		{
			mvprintw(y, x + 2, "%d", crazy::mine_info[y - 1][x + 1]);
			notmine--;
			map_pressed[y - 1][x + 1] = 1;
			bang(y - 1, x + 1);
		}
	}

	else if ((mine_info[y][x] == 0) && (x == 19) && (y == 0))
	{

		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)
		{
			mvprintw(y + 1, x, "%d", crazy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);
		}
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)
		{
			mvprintw(y + 2, x + 1, "%d", crazy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);
		}
		if (mine_info[y + 1][x - 1] != -1 && map_pressed[y + 1][x - 1] == 0)
		{
			mvprintw(y + 2, x, "%d", crazy::mine_info[y + 1][x - 1]);
			notmine--;
			map_pressed[y + 1][x - 1] = 1;
			bang(y + 1, x - 1);
		}
	}
	else if ((mine_info[y][x] == 0) && (x == 19) && (y == 19))

	{

		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)
		{
			mvprintw(y, x + 1, "%d", crazy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}

		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)
		{

			mvprintw(y + 1, x, "%d", crazy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);
		}

		if (mine_info[y - 1][x - 1] != -1 && map_pressed[y - 1][x - 1] == 0)

		{
			mvprintw(y, x, "%d", crazy::mine_info[y - 1][x - 1]);
			notmine--;
			map_pressed[y - 1][x - 1] = 1;
			bang(y - 1, x - 1);
		}

	}
	else if ((mine_info[y][x] == 0) && (y == 0))

	{
		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)

		{
			mvprintw(y + 1, x, "%d", crazy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);

		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)

		{
			mvprintw(y + 1, x + 2, "%d", crazy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] = 1;
			bang(y, x + 1);
		}
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)

		{
			mvprintw(y + 2, x + 1, "%d", crazy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);
		}
		if (mine_info[y + 1][x + 1] != -1 && map_pressed[y + 1][x + 1] == 0)

		{
			mvprintw(y + 2, x + 2, "%d", crazy::mine_info[y + 1][x + 1]);
			notmine--;
			map_pressed[y + 1][x + 1] = 1;
			bang(y + 1, x + 1);

		}
		if (mine_info[y + 1][x - 1] != -1 && map_pressed[y + 1][x - 1] == 0)

		{
			mvprintw(y + 2, x, "%d", crazy::mine_info[y + 1][x - 1]);
			notmine--;
			map_pressed[y + 1][x - 1] = 1;
			bang(y + 1, x - 1);
		}


	}



	else if ((mine_info[y][x] == 0) && (y == 19))

	{
		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)

		{
			mvprintw(y + 1, x, "%d", crazy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);
		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)

		{
			mvprintw(y + 1, x + 2, "%d", crazy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] = 1;
			bang(y, x + 1);

		}
		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)

		{
			mvprintw(y, x + 1, "%d", crazy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}
		if (mine_info[y - 1][x - 1] != -1 && map_pressed[y - 1][x - 1] == 0)

		{
			mvprintw(y, x, "%d", crazy::mine_info[y - 1][x - 1]);
			notmine--;
			map_pressed[y - 1][x - 1] = 1;
			bang(y - 1, x - 1);
		}
		if (mine_info[y - 1][x + 1] != -1 && map_pressed[y - 1][x + 1] == 0)

		{
			mvprintw(y, x + 2, "%d", crazy::mine_info[y - 1][x + 1]);
			notmine--;
			map_pressed[y - 1][x + 1] = 1;
			bang(y - 1, x + 1);
		}


	}


	else if ((mine_info[y][x] == 0) && (x == 0))

	{
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)

		{
			mvprintw(y + 2, x + 1, "%d", crazy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);
		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)

		{
			mvprintw(y + 1, x + 2, "%d", crazy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] = 1;
			bang(y, x + 1);
		}
		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)

		{
			mvprintw(y, x + 1, "%d", crazy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}
		if (mine_info[y + 1][x + 1] != -1 && map_pressed[y + 1][x + 1] == 0)

		{
			mvprintw(y + 2, x + 2, "%d", crazy::mine_info[y + 1][x + 1]);
			notmine--;
			map_pressed[y + 1][x + 1] = 1;
			bang(y + 1, x + 1);

		}
		if (mine_info[y - 1][x + 1] != -1 && map_pressed[y - 1][x + 1] == 0)

		{
			mvprintw(y, x + 2, "%d", crazy::mine_info[y - 1][x + 1]);
			notmine--;
			map_pressed[y - 1][x + 1] = 1;
			bang(y - 1, x + 1);

		}


	}



	else if ((mine_info[y][x] == 0) && (x == 19))

	{
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)

		{
			mvprintw(y + 2, x + 1, "%d", crazy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);

		}
		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)

		{
			mvprintw(y + 1, x, "%d", crazy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);

		}
		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)

		{
			mvprintw(y, x + 1, "%d", crazy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}

		if (mine_info[y - 1][x - 1] != -1 && map_pressed[y - 1][x - 1] == 0)

		{
			mvprintw(y, x, "%d", crazy::mine_info[y - 1][x - 1]);
			notmine--;
			map_pressed[y - 1][x - 1] = 1;
			bang(y - 1, x - 1);
		}
		if (mine_info[y + 1][x - 1] != -1 && map_pressed[y + 1][x - 1] == 0)

		{
			mvprintw(y + 2, x, "%d", crazy::mine_info[y + 1][x - 1]);
			notmine--;
			map_pressed[y + 1][x - 1] = 1;
			bang(y + 1, x - 1);

		}

	}
}


void easy::bang(int y, int x)//uncover the adjacent squares
{

	if ((mine_info[y][x] == 0) && (y > 0) && (y < 9) && (x > 0) && (x < 9))
	{
		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)
		{
			mvprintw(y, x + 1, "%d", easy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)
		{
			mvprintw(y + 2, x + 1, "%d", easy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);

		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)
		{
			mvprintw(y + 1, x + 2, "%d", easy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] = 1;
			bang(y, x + 1);

		}
		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)
		{
			mvprintw(y + 1, x, "%d", easy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);

		}
		if (mine_info[y - 1][x - 1] != -1 && map_pressed[y - 1][x - 1] == 0)
		{
			mvprintw(y, x, "%d", easy::mine_info[y - 1][x - 1]);
			notmine--;
			map_pressed[y - 1][x - 1] = 1;
			bang(y - 1, x - 1);

		}
		if (mine_info[y + 1][x - 1] != -1 && map_pressed[y + 1][x - 1] == 0)
		{
			mvprintw(y + 2, x, "%d", easy::mine_info[y + 1][x - 1]);
			notmine--;
			map_pressed[y + 1][x - 1] = 1;
			bang(y + 1, x - 1);

		}
		if (mine_info[y - 1][x + 1] != -1 && map_pressed[y - 1][x + 1] == 0)
		{
			mvprintw(y, x + 2, "%d", easy::mine_info[y - 1][x + 1]);
			notmine--;
			map_pressed[y - 1][x + 1] = 1;
			bang(y - 1, x + 1);

		}
		if (mine_info[y + 1][x + 1] != -1 && map_pressed[y + 1][x + 1] == 0)
		{
			mvprintw(y + 2, x + 2, "%d", easy::mine_info[y + 1][x + 1]);
			notmine--;
			map_pressed[y + 1][x + 1] = 1;
			bang(y + 1, x + 1);

		}

	}


	else if ((mine_info[y][x] == 0) && (x == 0) && (y == 0))
	{
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)
		{
			mvprintw(y + 2, x + 1, "%d", easy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);
		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)
		{
			mvprintw(y + 1, x + 2, "%d", easy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] == 1;
			bang(y, x + 1);
		}
		if (mine_info[y + 1][x + 1] != -1 && map_pressed[y + 1][x + 1] == 0)
		{
			mvprintw(y + 2, x + 2, "%d", easy::mine_info[y + 1][x + 1]);
			notmine--;
			map_pressed[y + 1][x + 1] = 1;
			bang(y + 1, x + 1);
		}
	}
	else if ((mine_info[y][x] == 0) && (x == 0) && (y == 9))
	{
		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)
		{
			mvprintw(y, x + 1, "%d", easy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)
		{
			mvprintw(y + 1, x + 2, "%d", easy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] = 1;
			bang(y, x + 1);
		}
		if (mine_info[y - 1][x + 1] != -1 && map_pressed[y - 1][x + 1] == 0)
		{
			mvprintw(y, x + 2, "%d", easy::mine_info[y - 1][x + 1]);
			notmine--;
			map_pressed[y - 1][x + 1] = 1;
			bang(y - 1, x + 1);
		}
	}

	else if ((mine_info[y][x] == 0) && (x == 9) && (y == 0))
	{

		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)
		{
			mvprintw(y + 1, x, "%d", easy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);
		}
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)
		{
			mvprintw(y + 2, x + 1, "%d", easy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);
		}
		if (mine_info[y + 1][x - 1] != -1 && map_pressed[y + 1][x - 1] == 0)
		{
			mvprintw(y + 2, x, "%d", easy::mine_info[y + 1][x - 1]);
			notmine--;
			map_pressed[y + 1][x - 1] = 1;
			bang(y + 1, x - 1);
		}
	}
	else if ((mine_info[y][x] == 0) && (x == 9) && (y == 9))

	{

		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)
		{
			mvprintw(y, x + 1, "%d", easy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}

		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)
		{

			mvprintw(y + 1, x, "%d", easy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);
		}

		if (mine_info[y - 1][x - 1] != -1 && map_pressed[y - 1][x - 1] == 0)

		{
			mvprintw(y, x, "%d", easy::mine_info[y - 1][x - 1]);
			notmine--;
			map_pressed[y - 1][x - 1] = 1;
			bang(y - 1, x - 1);
		}

	}
	else if ((mine_info[y][x] == 0) && (y == 0))

	{
		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)

		{
			mvprintw(y + 1, x, "%d", easy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);

		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)

		{
			mvprintw(y + 1, x + 2, "%d", easy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] = 1;
			bang(y, x + 1);
		}
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)

		{
			mvprintw(y + 2, x + 1, "%d", easy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);
		}
		if (mine_info[y + 1][x + 1] != -1 && map_pressed[y + 1][x + 1] == 0)

		{
			mvprintw(y + 2, x + 2, "%d", easy::mine_info[y + 1][x + 1]);
			notmine--;
			map_pressed[y + 1][x + 1] = 1;
			bang(y + 1, x + 1);

		}
		if (mine_info[y + 1][x - 1] != -1 && map_pressed[y + 1][x - 1] == 0)

		{
			mvprintw(y + 2, x, "%d", easy::mine_info[y + 1][x - 1]);
			notmine--;
			map_pressed[y + 1][x - 1] = 1;
			bang(y + 1, x - 1);
		}


	}



	else if ((mine_info[y][x] == 0) && (y == 9))

	{
		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)

		{
			mvprintw(y + 1, x, "%d", easy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);
		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)

		{
			mvprintw(y + 1, x + 2, "%d", easy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] = 1;
			bang(y, x + 1);

		}
		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)

		{
			mvprintw(y, x + 1, "%d", easy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}
		if (mine_info[y - 1][x - 1] != -1 && map_pressed[y - 1][x - 1] == 0)

		{
			mvprintw(y, x, "%d", easy::mine_info[y - 1][x - 1]);
			notmine--;
			map_pressed[y - 1][x - 1] = 1;
			bang(y - 1, x - 1);
		}
		if (mine_info[y - 1][x + 1] != -1 && map_pressed[y - 1][x + 1] == 0)

		{
			mvprintw(y, x + 2, "%d", easy::mine_info[y - 1][x + 1]);
			notmine--;
			map_pressed[y - 1][x + 1] = 1;
			bang(y - 1, x + 1);
		}


	}


	else if ((mine_info[y][x] == 0) && (x == 0))

	{
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)

		{
			mvprintw(y + 2, x + 1, "%d", easy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);
		}
		if (mine_info[y][x + 1] != -1 && map_pressed[y][x + 1] == 0)

		{
			mvprintw(y + 1, x + 2, "%d", easy::mine_info[y][x + 1]);
			notmine--;
			map_pressed[y][x + 1] = 1;
			bang(y, x + 1);
		}
		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)

		{
			mvprintw(y, x + 1, "%d", easy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}
		if (mine_info[y + 1][x + 1] != -1 && map_pressed[y + 1][x + 1] == 0)

		{
			mvprintw(y + 2, x + 2, "%d", easy::mine_info[y + 1][x + 1]);
			notmine--;
			map_pressed[y + 1][x + 1] = 1;
			bang(y + 1, x + 1);

		}
		if (mine_info[y - 1][x + 1] != -1 && map_pressed[y - 1][x + 1] == 0)

		{
			mvprintw(y, x + 2, "%d", easy::mine_info[y - 1][x + 1]);
			notmine--;
			map_pressed[y - 1][x + 1] = 1;
			bang(y - 1, x + 1);

		}


	}



	else if ((mine_info[y][x] == 0) && (x == 9))

	{
		if (mine_info[y + 1][x] != -1 && map_pressed[y + 1][x] == 0)

		{
			mvprintw(y + 2, x + 1, "%d", easy::mine_info[y + 1][x]);
			notmine--;
			map_pressed[y + 1][x] = 1;
			bang(y + 1, x);

		}
		if (mine_info[y][x - 1] != -1 && map_pressed[y][x - 1] == 0)

		{
			mvprintw(y + 1, x, "%d", easy::mine_info[y][x - 1]);
			notmine--;
			map_pressed[y][x - 1] = 1;
			bang(y, x - 1);

		}
		if (mine_info[y - 1][x] != -1 && map_pressed[y - 1][x] == 0)

		{
			mvprintw(y, x + 1, "%d", easy::mine_info[y - 1][x]);
			notmine--;
			map_pressed[y - 1][x] = 1;
			bang(y - 1, x);
		}

		if (mine_info[y - 1][x - 1] != -1 && map_pressed[y - 1][x - 1] == 0)

		{
			mvprintw(y, x, "%d", easy::mine_info[y - 1][x - 1]);
			notmine--;
			map_pressed[y - 1][x - 1] = 1;
			bang(y - 1, x - 1);
		}
		if (mine_info[y + 1][x - 1] != -1 && map_pressed[y + 1][x - 1] == 0)

		{
			mvprintw(y + 2, x, "%d", easy::mine_info[y + 1][x - 1]);
			notmine--;
			map_pressed[y + 1][x - 1] = 1;
			bang(y + 1, x - 1);

		}

	}
}


	void crazy ::sethint()
	{
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{

				if (mine_info[i][j] == -1)
				{
					mines_in_a_row[i]++;
				}
			}

		}


	}
	void easy::sethint()
	{
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{

				if (mine_info[i][j] == -1)
				{
					mines_in_a_row[i]++;
				}
			}

		}


	}


	void crazy ::lets_play_a_game()
	{

		setstart();
		while (go_on)
		{
			mvaddstr(2, 42, "remains:");
			mvprintw(2, 50,"%d", notmine);
			attrset(A_UNDERLINE);
			mvaddstr(2, 30, "Crazy LEVEL");
			mvaddstr(3, 40, "wanna quit game?press q");
			mvaddstr(4, 40, "wanna uncover?press s");
			mvaddstr(5, 40, "(Do not uncover outside the map and don't uncover those which have been uncovered)");
			mvaddstr(6, 40, "Need a hint?,press h");
			mvaddstr(7, 40, "wanna erect a flag?press f");
			cbreak(); // disable key buffering
			noecho(); // disable echoing
			keypad(stdscr, TRUE); // enable keypad reading
			getmaxyx(stdscr, height, width); // get screen size
			mvaddstr(1, 40, "Pressed Key: ");
			go_on = TRUE;
			move(y, x);
			nodelay(stdscr, TRUE);
			while ((c = getch()) == ERR)


			{

				getElapsedTime();

			}

			nodelay(stdscr, FALSE);
			move(y, x);
			int p;
			start://防呆
			c = getch();
			switch (c) {
				//按h即可獲得提示

			case 'h':
			{
				mvaddstr(8, 40, "hint :");
				mvaddstr(9, 40, "Please press 1 to 9 and 0 and  w e r t y u i o p to get the mine numbers in that row");
				p = getch();

				switch (p)
				{


				case '1':
					mvprintw(10, 32, "row 1:");
					mvprintw(10, 40, "%d", mines_in_a_row[0]);
					break;
				case '2':
					mvprintw(11, 32, "row 2:");
					mvprintw(11, 40, "%d", mines_in_a_row[1]);
					break;
				case '3':
					mvprintw(12, 32, "row 3:");
					mvprintw(12, 40, "%d", mines_in_a_row[2]);
					break;
				case '4':
					mvprintw(13, 32, "row 4:");
					mvprintw(13, 40, "%d", mines_in_a_row[3]);
					break;
				case '5':
					mvprintw(14, 32, "row 5:");
					mvprintw(14, 40, "%d", mines_in_a_row[4]);
					break;
				case '6':
					mvprintw(15, 32, "row 6:");
					mvprintw(15, 40, "%d", mines_in_a_row[5]);
					break;
				case '7':
					mvprintw(16, 32, "row 7:");
					mvprintw(16, 40, "%d", mines_in_a_row[6]);
					break;
				case '8':
					mvprintw(17, 32, "row 8:");
					mvprintw(17, 40, "%d", mines_in_a_row[7]);
					break;
				case '9':
					mvprintw(18, 32, "row 9:");
					mvprintw(18, 40, "%d", mines_in_a_row[8]);
					break;
				case '0':
					mvprintw(19, 32, "row 10:");
					mvprintw(19, 40, "%d", mines_in_a_row[9]);
					break;
				case 'w':
					mvprintw(20, 32, "row 11:");
					mvprintw(20, 40, "%d", mines_in_a_row[10]);
					break;
				case 'e':
					mvprintw(21, 32, "row 12:");
					mvprintw(21, 40, "%d", mines_in_a_row[11]);
					break;
				case 'r':
					mvprintw(22, 32, "row 13:");
					mvprintw(22, 40, "%d", mines_in_a_row[12]);
					break;
				case 't':
					mvprintw(23, 32, "row 14:");
					mvprintw(23, 40, "%d", mines_in_a_row[13]);
					break;
				case 'y':
					mvprintw(24, 32, "row 15:");
					mvprintw(24, 40, "%d", mines_in_a_row[14]);
					break;
				case 'u':
					mvprintw(25, 32, "row 16:");
					mvprintw(25, 40, "%d", mines_in_a_row[15]);
					break;
				case 'i':
					mvprintw(26, 32, "row 17:");
					mvprintw(26, 40, "%d", mines_in_a_row[16]);
					break;
				case 'o':
					mvprintw(27, 32, "row 18:");
					mvprintw(27, 40, "%d", mines_in_a_row[17]);
					break;
				case 'p':
					mvprintw(28, 32, "row 19:");
					mvprintw(28, 40, "%d", mines_in_a_row[18]);
					break;
				default:
					mvprintw(10, 43, "only 1~9,press h and select one of 1~9 !!!");
					break;
				}
				break;

			}
			//按q則離開遊戲
			case 'q':mvaddstr(27, 1, "you already quit the game,press any key to leave"); int input; input = getch(); go_on = false; break;
			case 's'://開踩
				attrset(A_REVERSE);//反白
				if (crazy::mine_info[y - 1][x - 1] == 0&&map_pressed[y-1][x-1]!=1)
				{
					map_pressed[y - 1][x - 1] = 1;
					printw("%d", crazy::mine_info[y - 1][x - 1]);

					bang(y - 1, x - 1);
					notmine--;
					break;
				}

				if (crazy::mine_info[y - 1][x - 1] != -1 && crazy::mine_info[y - 1][x - 1] != 0 && map_pressed[y - 1][x - 1] !=1 )             //沒踩到地雷，遊戲繼續
				{
					map_pressed[y - 1][x - 1] = 1;
					printw("%d", crazy::mine_info[y - 1][x - 1]);
					notmine--;
					break;
				}
				else if (crazy::mine_info[y - 1][x - 1] == -1)
				{

					start_color();
					init_pair(1, COLOR_CYAN, COLOR_RED);
					attrset(COLOR_PAIR(1));
					//踩到地雷，爆了，玩家輸入任意鍵以獲得整個地圖位置
					printw("b");
					mvaddstr(17, 1, "You uncover a mine,Game Over!!!!");
					mvaddstr(18, 1, "please press any key so as to get the whole maps ");
					int a = getch();
					clear();
					refresh();
					go_on = false;

					break;



				}
				break;
			case 'f':
				printw("f"); break;
			case KEY_LEFT: --x; mvaddstr(1, 54, "Left "); break;
			case KEY_RIGHT: ++x; mvaddstr(1, 54, "Right"); break;
			case KEY_UP: --y; mvaddstr(1, 54, "Up "); break;
			case KEY_DOWN: ++y; mvaddstr(1, 54, "Down "); break;
			default: goto start;
			} // switch (c)
			while (x < 0) x += width;
			while (x >= width) x -= width;
			while (y < 0) y += height;
			while (y >= height) y -= height;
			refresh();
			// while (go_on)
			if (notmine == 0)//非雷區全部踩完,代表獲勝
			{
				go_on = false;
				mvaddstr(7, 1, "You Win!!!!please press any key to get the whole map");
				int win;
				win = getch();

			}






		}

	}



	void easy::lets_play_a_game()
	{

		setstart();
		while (go_on)
		{
			mvaddstr(2, 42, "remains");
			mvprintw(2, 50, "%d", notmine);
			attrset(A_UNDERLINE);
			mvaddstr(2, 30, "Easy LEVEL");
			mvaddstr(3, 40, "wanna quit game?press q");
			mvaddstr(4, 40, "wanna uncover?press s");
			mvaddstr(5, 40, "(Do not uncover outside the map and don't uncover those which have been uncovered)");
			mvaddstr(6, 40, "Need a hint?,press h");
			mvaddstr(7, 40, "wanna erect a flag?press f");
			cbreak(); // disable key buffering
			noecho(); // disable echoing
			keypad(stdscr, TRUE); // enable keypad reading
			getmaxyx(stdscr, height, width); // get screen size
			mvaddstr(1, 40, "Pressed Key: ");
			go_on = TRUE;
			move(y, x);
			nodelay(stdscr, TRUE);
			while ((c = getch()) == ERR)


			{

				getElapsedTime();

			}

			nodelay(stdscr, FALSE);
			move(y, x);
			int p;
		start://防呆
			c = getch();
			switch (c) {
				//按h即可獲得提示

			case 'h':
			{
				mvaddstr(8, 40, "hint :");
				mvaddstr(9, 40, "Please press 1~9 to get the mine numbers in that row(sorry just provide 9 rows )");
				p = getch();

				switch (p)
				{


				case '1':
					mvprintw(10, 32, "row 1:");
					mvprintw(10, 40, "%d", mines_in_a_row[0]);
					break;
				case '2':
					mvprintw(11, 32, "row 2:");
					mvprintw(11, 40, "%d", mines_in_a_row[1]);
					break;
				case '3':
					mvprintw(12, 32, "row 3:");
					mvprintw(12, 40, "%d", mines_in_a_row[2]);
					break;
				case '4':
					mvprintw(13, 32, "row 4:");
					mvprintw(13, 40, "%d", mines_in_a_row[3]);
					break;
				case '5':
					mvprintw(14, 32, "row 5:");
					mvprintw(14, 40, "%d", mines_in_a_row[4]);
					break;
				case '6':
					mvprintw(15, 32, "row 6:");
					mvprintw(15, 40, "%d", mines_in_a_row[5]);
					break;
				case '7':
					mvprintw(16, 32, "row 7:");
					mvprintw(16, 40, "%d", mines_in_a_row[6]);
					break;
				case '8':
					mvprintw(17, 32, "row 8:");
					mvprintw(17, 40, "%d", mines_in_a_row[7]);
					break;
				case '9':
					mvprintw(18, 32, "row 9:");
					mvprintw(18, 40, "%d", mines_in_a_row[8]);															break;
				default:
					mvprintw(10, 41, "only 1~9,press h and select one of 1~9 !!!");
					break;
				}
				break;

			}
			//按q則離開遊戲
			case 'q':mvaddstr(27, 1, "you already quit the game,press any key to leave"); int input; input = getch(); go_on = false; break;
			case 's'://開踩
				attrset(A_REVERSE);//反白
				if (easy::mine_info[y - 1][x - 1] == 0 &&easy::map_pressed[y-1][x-1]!=1)
				{
					easy::map_pressed[y - 1][x - 1] = 1;

					printw("%d", easy::mine_info[y - 1][x - 1]);

					bang(y - 1, x - 1);
					notmine--;
					break;
				}

				if (easy::mine_info[y - 1][x - 1] != -1 && easy::mine_info[y - 1][x - 1] != 0&&easy::map_pressed[y-1][x-1]!=1)             //沒踩到地雷，遊戲繼續
				{
					easy::map_pressed[y - 1][x - 1] = 1;
					printw("%d", easy::mine_info[y - 1][x - 1]);
					notmine--;
					break;
				}
				else if (easy::mine_info[y - 1][x - 1] == -1)
				{

					start_color();
					init_pair(1, COLOR_CYAN, COLOR_RED);
					attrset(COLOR_PAIR(1));
					//踩到地雷，爆了，玩家輸入任意鍵以獲得整個地圖位置
					printw("b");
					mvaddstr(17, 1, "You uncover a mine,Game Over!!!!");
					mvaddstr(18, 1, "please press any key so as to get the whole maps ");
					int a = getch();
					clear();
					refresh();
					go_on = false;

					break;



				}
				break;
			case 'f':
				printw("f"); break;
			case KEY_LEFT: --x; mvaddstr(1, 54, "Left "); break;
			case KEY_RIGHT: ++x; mvaddstr(1, 54, "Right"); break;
			case KEY_UP: --y; mvaddstr(1, 54, "Up "); break;
			case KEY_DOWN: ++y; mvaddstr(1, 54, "Down "); break;
			default: goto start;
			} // switch (c)
			while (x < 0) x += width;
			while (x >= width) x -= width;
			while (y < 0) y += height;
			while (y >= height) y -= height;
			refresh();
			// while (go_on)
			if (notmine == 0)//非雷區全部踩完,代表獲勝
			{
				go_on = false;
				mvaddstr(7, 1, "You Win!!!!hellllll yeahhhhh");
				int win;
				win = getch();

			}






		}

	}






	void crazy ::getmap()
	{
		ofstream outfile("Mine.txt", ios::out);//輸出 map到Mine.txt(請用cat指令打開)
		if (!outfile) {
			cerr << "Failed opening" << endl;
			exit(1);
		}
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{
				if (mine_info[i][j] != -1)
					outfile << mine_info[i][j];
				else
					outfile << 'b';




			}
			outfile << '\n';
		}
	}
	void easy::getmap()
	{
		ofstream outfile("Mine.txt", ios::out);//輸出 map到Mine.txt(請用cat指令打開)
		if (!outfile) {
			cerr << "Failed opening" << endl;
			exit(1);
		}
		for (int i = 0; i<size; i++)
		{
			for (int j = 0; j<size; j++)
			{
				if (mine_info[i][j] != -1)
					outfile << mine_info[i][j];
				else
					outfile << 'b';




			}
			outfile << '\n';
		}
	}

