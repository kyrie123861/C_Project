#define _CRT_SECURE_NO_WARNINGS 1
////测试功能
#include"contact.h"

enum Option
{
	EXIT,
	ADD,
	DEL,
	SAERCH,
	MODIFY,
	SHOW,
	QSORT
};

void menu()
{
	printf("****************************************************\n");
	printf("********       1.add            2.del       ********\n");
	printf("********       3.saerch         4.modify    ********\n");
	printf("********       5.show           6.qsort     ********\n");
	printf("********       0.exit                       ********\n");
	printf("****************************************************\n");
}

int main()
{
	int input = 0;
	Contact con;
	Initcontact(&con);
	do
	{
		menu();
		printf("请输入: > ");
		scanf_s("%d", &input);
		switch(input)
		{
		case ADD:
			Addcontact(&con);
			break;
		case DEL:
			Delcontact(&con);
			break;
		case SAERCH:
			Searchcontact(&con);
			break;
		case MODIFY:
			Modifycontact(&con);
			break;
		case SHOW:
			Showcontact(&con);
			break;
		case QSORT:
			Qosrtcontact(&con);
			break;
		case EXIT:
		{
			Savecontact(&con);
			Destorycontact(&con);
			printf("退出通讯录\n");
			break;
		}
		default:
		{
			printf("请重新选择\n");
			break;
		}
		}
	} while (input);


	return 0;
}
