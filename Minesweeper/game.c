#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void Initbord(char mine[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			mine[i][j] = set;
		}
	}
}


void Displaybord(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("--------------------------扫雷----------------------------\n");
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i); 
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("--------------------------扫雷----------------------------\n");
}


void Setmine(char board[ROWS][COLS], int row, int col)
{
	int count = EASY_COUNT;
	while (count)
	{
		int x = rand() % row + 1;
		int y = rand() % col + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}

	}
}


int Get_my_mine(char board[ROWS][COLS], int x, int y)
{
	return (board[x - 1][y]
		+ board[x - 1][y - 1]
		+ board[x][y - 1]
		+ board[x + 1][y - 1]
		+ board[x + 1][y]
		+ board[x + 1][y + 1]
		+ board[x][y + 1]
		+ board[x - 1][y + 1] - 8 * '0');

}


void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;

	while (win< (row * col - EASY_COUNT))
	{
		printf("请输入要排查雷的坐标:> ");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= 9 && y >= 1 && y <= 9)
		{
			if (show[x][y] != '*')
			{
				printf("该位置已经被排查，不可重复排查\n");
			}
			else
			{
				//是雷
				if (mine[x][y] == '1')
				{
					printf("遗憾，你被炸死\n");
					Displaybord(mine, ROW, COL);//显示雷的位置
					break;
				}
				//不是雷
				else
				{
					//统计mine中，x，y周围雷的个数
					int count = Get_my_mine(mine, x, y);
					show[x][y] = count + '0';//转化成数字字符
					Displaybord(show, ROW, COL);
				}
			}
		}
		else
		{
			printf("超出范围，请重新输入\n");
		}
		if (win == row * col - EASY_COUNT)
		{
			printf("恭喜你，排查成功\n");
		}
	}
}
