#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct Pt
{
	int row;
	int col;
}PT;



void PrintMaze(int** maze, int N, int M)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			printf("%d ", maze[i][j]);
		}
		printf("\n");

	}
}


bool isPass(int** maze, int N, int M, PT pos)
{
	if (pos.row >= 0 && pos.row < N
		&& pos.col >= 0 && pos.col < M
		&& maze[pos.row][pos.col] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool GetMazePath(int** maze, int N, int M, PT cur)
{
	if (cur.col == M - 1, cur.row == N - 1)
	{
		return true;
	}


	PT next;
	maze[cur.row][cur.col] = 2;

	//上
	next = cur;
	next.row -= 1;
	if (isPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}

	//下
	next = cur;
	next.row += 1;
	if (isPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}
	
	//左
	next = cur;
	next.col -= 1;
	if (isPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}
	
	//右
	next = cur;
	next.col += 1;
	if (isPass(maze, N, M, next))
	{
		if (GetMazePath(maze, N, M, next))
			return true;
	}

	return false;
}



int main()
{
	int N = 0, M = 0;
	scanf("%d %d", &N, &M);

	int** maze = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
	{
		maze[i] = (int*)malloc(sizeof(int) * M);
	}

	//输入二维数组
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%d", &maze[i][j]);
		}

	}

	PT entry = { 0,0 };
	if (GetMazePath(maze, N, M, entry))
	{
		printf("找到通路\n");
	}
	else
	{
		printf("no找到通路\n");
	}



	for (int i = 0; i < N; i++)
	{
		free(maze[i]);
	}
	free(maze);
	maze = NULL;

	return 0;
}


