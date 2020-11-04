#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contact.h"

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW,
	CLEAR
};

void menu()
{
	printf("----------------------------------\n");
	printf("------    1.add   2.delate   -----\n");
	printf("------    3.search  4.modify -----\n");
	printf("------    5.sort  6.show     -----\n");
	printf("------    0.exit 7.clear     -----\n");
	printf("----------------------------------\n");
}

void test()
{
	Contact con = { 0 };
	int input = 0;
	do
	{
		menu();
		printf("\n");
		printf("请输入你想进行的操作：---->");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		//case SORT:
		//	sort_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		case CLEAR:
			clear_contact(&con);
			break;
		case EXIT:
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}



