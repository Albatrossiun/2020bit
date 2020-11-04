#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

void add_contact(Contact* pc)
{
	if (pc->sz >= MAX)
	{
		printf("通讯录已满，无法ADD");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入电话:>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入地址:>");
		scanf("%s", pc->data[pc->sz].addr);
		printf("请输入性别:>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入年龄:>");
		scanf("%d", &(pc->data[pc->sz].age));
		pc->sz++;
		printf("添加成功\n");
	}
}


static int find_peo_by_name(Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(name, pc->data[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}

//void show_contact(Contact* pc)
//{
//	int i = 0;
//	printf("%10s %12s %20s %5s %5s\n", "名字", "电话", "地址", "年龄", "性别");
//	for (i = 0; i < pc->sz; i++)
//	{
//		printf("%10s %12s %20s %5d %5s\n", pc->data[i].name,
//			pc->data[i].tele,
//			pc->data[i].addr,
//			pc->data[i].age,
//			pc->data[i].sex);
//	}
//}

void del_contact(Contact* pc)
{
	if (pc->sz == 0)
	{
		printf("抱歉，通讯录为空\n");
	}
	else
	{
		char name[MAX_NAME] = { 0 };
		printf("请输入要删除人的名字:>");
		scanf("%s", name);
		int pos = find_peo_by_name(pc, name);
		if (pos == -1)
		{
			printf("很遗憾，删除的人不存在\n");
		}
		else
		{
			int j = 0;
			for (j = pos; j < pc->sz - 1; j++)
			{
				pc->data[j] = pc->data[j + 1];
			}
			pc->sz--;
			printf("删除成功\n");
		}
	}
}


void search_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要查找人的名字:>");
	scanf("%s", name);
	int pos = find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("%10s %12s %20s %5s %5s\n",
			"名字", "电话", "地址", "年龄","性别");
		printf("%10s %12s %20s %5d %5s\n", pc->data[pos].name,
			pc->data[pos].tele,
			pc->data[pos].addr,
			pc->data[pos].age,
			pc->data[pos].sex);
	}
}



void modify_contact(Contact* pc)
{
	char name[MAX_NAME] = { 0 };
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = find_peo_by_name(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("请输入新的名字:>");
		scanf("%s", pc->data[pos].name);
		printf("请输入新的电话:>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入新的地址:>");
		scanf("%s", pc->data[pos].addr);
		printf("请输入新的性别:>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入新的年龄:>");
		scanf("%d", &(pc->data[pos].age));
	}
}


void sort_contact(Contact* pc)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pc->sz - 1; i++)
	{
		int flag = 1;
		for (j = 0; j < pc->sz - 1 - i; j++)
		{
			if (strcmp(pc->data[j].name, pc->data[j + 1].name) > 0)
			{
				PeoInfo tmp = pc->data[j];
				pc->data[j] = pc->data[j + 1];
				pc->data[j + 1] = tmp;
				flag = 0;
			}
		}
		if (1 == flag)
		{
			break;
		}
	}
}

void clear_contact(Contact* pc)
{
	pc->sz = 0;
	printf("已清空通讯录\n");
}


void show_contact(Contact* pc)
{
	int i = 0;
	printf("%10s %10s %10s %10s %10s\n", "名字", "电话", "地址", "年龄",  "性别");
	for (i = 0; i < pc->sz; i++)
	{
		printf("%10s %10s %10s %10d %10s\n", pc->data[i].name,
			pc->data[i].tele,
			pc->data[i].addr,
			pc->data[i].age,
			pc->data[i].sex);
	}
}

//void show_contact(Contact* pc)
//{
//	int i = 0;
//	printf("%10s %12s %20s %5s %5s\n", "名字", "电话", "地址", "年龄", "性别");
//	for (i = 0; i < pc->sz; i++)
//	{
//		printf("%10s %12s %20s %5d %5s\n", pc->data[i].name,
//			pc->data[i].tele,
//			pc->data[i].addr,
//			pc->data[i].age,
//			pc->data[i].sex);
//	}
//}