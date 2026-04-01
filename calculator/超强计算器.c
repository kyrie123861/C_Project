//#include<stdio.h>
//#include<math.h>
//
//void mnue()
//{
//	printf("*************************************************\n");
//	printf("**************    1.Add   2.Sub  ****************\n");
//	printf("**************    3.Mul   4.Div  ****************\n");
//	printf("**************    0.退出计算器   ****************\n");
//	printf("*************************************************\n");
//}
//int Add(int x, int y)
//{
//	return x + y;
//}
//int Sub(int x, int y)
//{
//	return x - y;
//}
//int Mul(int x, int y)
//{
//	return x * y;
//}
//int Div(int x, int y)
//{
//	return x / y;
//}
//void calc(int (*ps)(int, int))
//{
//	int x, y = 0;
//	printf("请输入想算的数字\n");
//	scanf_s("%d %d", &x, &y);
//	int ret = (*ps)(x, y);
//	printf("计算结果\n");
//	printf("%d\n", ret);
//}
//
//int main()
//{
//	
//	int input = 0;
//	
//	do
//	{
//		mnue();
//		printf("请选择你的计算方向= ");
//		scanf_s("%d", &input);
//		switch(input)
//		{
//		  case 1:
//		  {
//			  calc(Add);
//			  break;
//		  }
//		  case 2:
//		  {
//			  calc(Sub);
//			  break;
//		  }
//		  case 3:
//		  {
//			  calc(Mul);
//			  break;
//		  }
//		  case 4:
//		  {
//			  calc(Div);
//			  break;
//		  }
//		  case 0:
//		  {
//			  printf("退出计算器\n");
//			  break;
//		  }
//		  default:
//		  {
//			  printf("选择错误\n");
//			  break;
//		  }
//		}
//	} while (input);
//	return 0;
//}



















