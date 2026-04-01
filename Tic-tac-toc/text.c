#include"game.h"
//测试游戏的逻辑
void mnue()
{
	printf("*****************************************\n");
	printf("***************  1 开始游戏 *************\n");
	printf("***************  0  exit    *************\n");
	printf("*****************************************\n");
}


void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化键盘的函数
	Iniboard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	//下棋
	while (1)
	{
		playerMove(board, ROW, COL);
		//判断输赢
		ret = iswin(board, ROW, COL);

		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		computerMove(board, ROW, COL);
		//判断输赢
		ret = iswin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
	DisplayBoard(board, ROW, COL);


}


int main()
{

	srand((unsigned int)time(NULL));//设置随机数的生成起点
	int input = 0;
	do
	{
		mnue();
		printf("请输入\n");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("退出游戏\n");
			break;
		}
		default:
			printf("请重新选择！\n");
			break;
		}
	} while (input);


	return 0;
}