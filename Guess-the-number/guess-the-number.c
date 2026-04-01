#include<stdio.h>
#include<time.h>

void mune()
{
	printf("***********************************\n");
	printf("************   1.play   ***********\n");
	printf("************   0.exit   ***********\n");
	printf("***********************************\n");
}

void play()
{
	srand((unsigned int)time(NULL));
	//设置随机数的范围
	int ret = rand() % 100;
	int n = 0;
	do
	{
		printf("请输入你想要猜的数字");
		printf("\n");
		scanf_s("%d", &n);
		if (n == ret)
		{
			printf("猜对了\n");
			break;
		}
		else if (n > ret)
		{
			printf("猜大了，目\n");
			printf("\n");
		}
		else
		{
			printf("猜小了,徐\n");
			printf("\n");
		}
		
	} while (n);
}

int main()
{
	int num = 0;
	do
	{
		mune();
		printf("请输入你的选择");
		scanf_s("%d", &num);
		switch (num)
		{
		case 1:
		{
			play();//进入游戏
			break;
		}
		case 0:
		{
			printf("退出游戏\n");
			break;
		}
		default:
		{
			printf("输入错误,请重新选择\n");
			break;
		}
		}
	} while (num);
	return 0;
}
