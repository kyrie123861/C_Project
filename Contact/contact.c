#define _CRT_SECURE_NO_WARNINGS 1
////通讯录的实现

#include"contact.h"

//静态版本
//void Initcontact(Contact* pc)
//{
//	assert(pc);
//	pc->count = 0;
//	memset(pc->data, 0, sizeof(pc->data));
//}


void Check(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		Peoinfo* ptr = (Peoinfo*)realloc(pc->data, (pc->capacity + 2) * sizeof(Peoinfo));
		if (ptr == NULL)
		{
			printf("ADD::%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += 2;
			printf("增容成功\n");
		}
	}
}


void Loadcontact(Contact* pc)
{
	FILE* Pfread = fopen("contact.txt", "rb");
	if (Pfread == NULL)
	{
		perror("Loadcontact");
		return;
	}
	//读文件
	Peoinfo tmp = { 0 };

	while (fread(&tmp, sizeof(Peoinfo), 1, Pfread) == 1)
	{
		//考虑增容
		Check(pc);

		pc->data[pc->count] = tmp;
		pc->count++;

	}

	//释放文件
	fclose(Pfread);
	Pfread = NULL;
}


//动态版本
int Initcontact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (Peoinfo*)calloc(3, sizeof(Peoinfo));
	if (pc->data == NULL)
	{
		printf("Init::%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = 3;

	//加载文件的信息到通讯录
	Loadcontact(pc);

	return 0;
}

void Destorycontact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
	printf("已释放\n");
}

//静态版本
//void Addcontact(Contact* pc)
//{
//	assert(pc);
//	if (pc->count == 100)
//	{
//		printf("通讯录已满，无法添加\n");
//		return;//这里表示结束当前函数
//	}
//	//如果没满
//
//	printf("请输入名字：");
//	scanf_s("%s", pc->data[pc->count].name, (unsigned)sizeof(pc->data[pc->count].name));
//	printf("请输入年龄：");
//	scanf_s("%d", &(pc->data[pc->count].age));
//	printf("请输入性别：");
//	scanf_s("%s", pc->data[pc->count].sex, (unsigned)sizeof(pc->data[pc->count].sex));
//	printf("请输入电话：");
//	scanf_s("%s", pc->data[pc->count].tele, (unsigned)sizeof(pc->data[pc->count].tele));
//	printf("请输入住址：");
//	scanf_s("%s", pc->data[pc->count].addr, (unsigned)sizeof(pc->data[pc->count].addr));
//
//	pc->count++;
//	printf("增加成功\n");
//}


//动态版本
void Addcontact(Contact* pc)
{
	assert(pc);
	//增容
	Check(pc);
	//
	printf("请输入名字：");
	scanf_s("%s", pc->data[pc->count].name, (unsigned)sizeof(pc->data[pc->count].name));
	printf("请输入年龄：");
	scanf_s("%d", &(pc->data[pc->count].age));
	printf("请输入性别：");
	scanf_s("%s", pc->data[pc->count].sex, (unsigned)sizeof(pc->data[pc->count].sex));
	printf("请输入电话：");
	scanf_s("%s", pc->data[pc->count].tele, (unsigned)sizeof(pc->data[pc->count].tele));
	printf("请输入住址：");
	scanf_s("%s", pc->data[pc->count].addr, (unsigned)sizeof(pc->data[pc->count].addr));

	pc->count++;
	printf("增加成功\n");
}


void Showcontact(const Contact* pc)
{
	int i = 0;
	printf("%10s\t%5s\t%5s\t%10s\t%10s\n", "名字", "年龄", "性别", "电话号码", "住址");
	for (i = 0; i < pc->count; i++)
	{
		printf("%10s\t%5d\t%5s\t%10s\t%10s\n", pc->data[i].name, 
								       pc->data[i].age, 
									   pc->data[i].sex, 
								       pc->data[i].tele, 
									   pc->data[i].addr);
	}
}


int Findbyname(Contact* pc, char* name)
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}


void Delcontact(Contact* pc)
{
	char name[20] = { 0 };
	assert(pc);
	if (pc->count == 0)
	{
		printf("找不到该联系人，无法删除\n");
		return;
	}
	printf("输入要删除人的姓名:> ");
	scanf_s("%s", name, (unsigned)sizeof(name));
	//1.查找
	int ret = Findbyname(pc, name);
	if (ret == -1)
	{
		printf("查找不到该联系人\n");
		return;
	}
	//2.删除
	int i = 0;
	for (i = ret; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("删除成功\n");
}


void Searchcontact(Contact* pc)
{
	assert(pc);
	char name[20] = { 0 };
	printf("输入想查找的联系人: > ");
	scanf_s("%s", name, (unsigned)sizeof(name));
	int ret = Findbyname(pc, name);
	if (ret == -1)
	{
		printf("查找不到该联系人\n");
		return;
	}
	printf("-%10s\t-%5s\t-%5s\t-%10s\t-%10s\n", "名字", "年龄", "性别", "电话号码", "住址");
	printf("%10s\t%5d\t%5s\t%10s\t%10s\n", pc->data[ret].name,
											pc->data[ret].age,
											pc->data[ret].sex,
											pc->data[ret].tele,
											pc->data[ret].addr);
	
}


void Modifycontact(Contact* pc)
{
	char name[20] = { 0 };
	printf("输入要修改人的姓名:> ");
	scanf_s("%s", name, (unsigned)sizeof(name));
	//1.查找
	int ret = Findbyname(pc, name);
	if (ret == -1)
	{
		printf("要修改的人不存在\n");
		return;
	}

	printf("找到要修改的联系人，请开始修改\n");

	printf("请重新输入名字：");
	scanf_s("%s", pc->data[ret].name, (unsigned)sizeof(pc->data[ret].name));
	printf("请重新输入年龄：");
	scanf_s("%d", &(pc->data[ret].age));
	printf("请重新输入性别：");
	scanf_s("%s", pc->data[ret].sex, (unsigned)sizeof(pc->data[ret].sex));
	printf("请重新输入电话：");
	scanf_s("%s", pc->data[ret].tele, (unsigned)sizeof(pc->data[ret].tele));
	printf("请重新输入住址：");
	scanf_s("%s", pc->data[ret].addr, (unsigned)sizeof(pc->data[ret].addr));

	printf("修改成功\n");
}

int qosrt_by_name(const char* e1, const char* e2)
{
	return strcmp(((Peoinfo*)e1), ((Peoinfo*)e2));
}

void Qosrtcontact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(Peoinfo), qosrt_by_name);
	printf("排序成功\n");
}


void Savecontact(Contact* pc)
{
	assert(pc);
	FILE* Pfwrite = fopen("contact.txt", "wb");//以二进制的方式去写
	if (Pfwrite == NULL)
	{
		perror("Savecontact");
		return;
	}
	//写文件
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(Peoinfo), 1, Pfwrite);
	}

	//释放文件
	fclose(Pfwrite);
	Pfwrite = NULL;
}
