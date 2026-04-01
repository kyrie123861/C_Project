//这个超级计算器的厉害之处在于它可以继续加入你想要计算的方向
//应为创造了一个函数指针数组
//可以一直为里面输入计算函数
//只需改变其中的数值就可以了

#include<stdio.h>
#include<math.h>

void mnue()
{
	printf("*************************************************\n");
	printf("**************    1.Add   2.Sub  ****************\n");
	printf("**************    3.Mul   4.Div  ****************\n");
	printf("**************    0.退出计算器   ****************\n");
	printf("*************************************************\n");
}
int Add(int x, int y)
{
	return x + y;
}
int Sub(int x, int y)
{
	return x - y;
}
int Mul(int x, int y)
{
	return x * y;
}
int Div(int x, int y)
{
	return x / y;
}


int main()
{
	int i = 0;
	do 
	{
		mnue();
		printf("请选择计算方向= ");
		scanf_s("%d", &i);
		int (*arr[5])(int, int) = { 0,Add,Sub,Mul,Div };
		if (i >= 1 && i <= 4)
		{
			int x, y = 0;
			printf("请输入要计算的数\n");
			scanf_s("%d %d", &x, &y);
			int ret = arr[i](x, y);
			printf("计算结果为= ");
			printf("%d\n", ret);
		}
		else if (i == 0)
		{
			printf("退出计算器\n");
		}
		else
		{
			printf("请重新输入\n");
		}
	} while (i);

	return 0;
}



















