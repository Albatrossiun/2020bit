#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_NAME 20
#define MAX_TELE 12
#define MAX_ADDR 100
#define MAX_QQ 12
#define MAX_SEX 5

typedef struct PeoInfo
{
	char name[MAX_NAME];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	char qq[MAX_QQ];
	char sex[MAX_SEX];
	short age;
}PeoInfo;

typedef struct Contact
{
	PeoInfo* data;
	int sz;
	int capacity;
}Contact;

void check_capacity(Contact* pc);
void load_contact(Contact* pc);
void init_contact(Contact* pc);
void add_contact(Contact* pc);
void show_contact(Contact* pc);
void del_contact(Contact* pc);
void search_contact(Contact* pc);
void modify_contact(Contact* pc);
void sort_contact(Contact* pc);
void destroy_contact(Contact* pc);
void save_contact(Contact* pc);