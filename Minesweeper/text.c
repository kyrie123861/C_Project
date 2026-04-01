#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()
{
	printf("******************************************************\n");
	printf("**************          1.play          **************\n");
	printf("**************          0.exit          **************\n");
	printf("******************************************************\n");
}

void play()
{
	char mine[ROWS][COLS] = { 0 };//存放布置好的雷
	char show[ROWS][COLS] = { 0 };//存放出排查出的雷的信息
	//初始化数组的内容都为指定内容
	// 
	//mine在没有布置雷的时候都为'0'
	Initbord(mine, ROWS, COLS, '0');
	
	//show在没有排查雷的时候都为'*'
	Initbord(show, ROWS, COLS, '*');

	//Displaybord(mine, ROW, COL);//这个是埋的雷的信息，不打印，挂哥专用

	//埋雷
	Setmine(mine, ROW, COL);

	Displaybord(show, ROW, COL);

	//排查雷
	Findmine(mine, show, ROW, COL);
}

int main()		
{
	int input = 0;

	//设置生成数的起点
	srand((unsigned int)time(NULL));
	do
	{                   
		menu();
		printf("请选择：> ");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
		{
			play();
			break;
		}
		case 0:
		{
			printf("退出游戏\n");
			break;
		}
	    default:
		{
			printf("选择错误，重新选择\n");
		}
		}

	} while (input);

	return 0;
}

