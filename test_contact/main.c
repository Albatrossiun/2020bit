#include "contact.h"

void menu()
	{
		printf("\n");
		printf("*********************************\n");
		printf("******  1. add     2. del     ***\n");
		printf("******  3. search  4. modify  ***\n");
		printf("******  5. sort    6. show    ***\n");
		printf("******        0. exit         ***\n");
		printf("*********************************\n");
		printf("\n");
	}

enum option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SORT,
	SHOW,
};

void test()
{
	Contact con = { 0 };
	init_contact(&con);
	int input = 0;
	do
	{
		menu();
		printf("请选择---------------->");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			add_contact(&con);
			break;
		case DEL:
			del_contact(&con);
			break;
		case SEARCH:
			search_contact(&con);
			break;
		case MODIFY:
			modify_contact(&con);
			break;
		case SORT:
			sort_contact(&con);
			break;
		case SHOW:
			show_contact(&con);
			break;
		case EXIT:
			save_contact(&con);
			destroy_contact(&con);
			printf("退出通讯录\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}