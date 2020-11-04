#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 1000

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 100
#define MAX_SEX 5

typedef struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char sex[MAX_SEX];
	short age;
}PeoInfo;

typedef struct Contact
{
	PeoInfo data[MAX];
	int sz;
}Contact;

void add_contact(Contact* pc);
void show_contact(Contact* pc);
void del_contact(Contact* pc);
void search_contact(Contact* pc);
void modify_contact(Contact* pc);
void sort_contact(Contact* pc);
void clear_contact(Contact* pc);