#pragma once
////通讯录的声明

#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>


//人的信息
typedef struct Peoinfo
{
	char name[20];
	int age;
	char sex[10];
	char tele[12];
	char addr[30];
}Peoinfo;


//通讯录

//静态版本
//typedef struct Contact
//{
//	Peoinfo data[100];//可以存放一百个人的信息
//	int count;//记录通讯录的实际人数个数
//}Contact;


//动态版本
typedef struct Contact
{
	Peoinfo* data;//可以存放一百个人的信息
	int count;//记录通讯录的实际人数个数
	int capacity;//记录此时的容量
}Contact;


//通讯录的初始化
int Initcontact(Contact* pc);

//销毁通讯录//这个意思是释放内存
void Destorycontact(Contact* pc);

//增加联系人
void Addcontact(Contact* pc);

//打印通讯录
void Showcontact(const Contact* pc);

//删除联系人
void Delcontact(Contact* pc);

//查找联系人
void Searchcontact(Contact* pc);

//修改联系人
void Modifycontact(Contact* pc);

//排序联系人
void Qosrtcontact(Contact* pc);

//保存文件
void Savecontact(Contact* pc);

//加载文件
void Loadcontact(Contact* pc);