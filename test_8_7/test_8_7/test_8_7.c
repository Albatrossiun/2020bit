//# @FileName:test.c
//# @author:ZhaoXinYi
//# @version:0.0.1
//# @Date:2020.08.07
//# @BSD

#define _CRT_SECURE_NO_WARNINGS 1	//��÷���Դ�ļ��ĵ�һ��
//��newc++file.cpp���������һ�䣬������ÿһ��Դ�ļ������Լ��Զ�Я��һ��
//vs��������Ϊ����ȫ�ĺ��� scanf strcpy

//ctrl+F5 ���п�ݼ�

//��סctrl���������Ըı������С ����-ѡ��-�������ɫ

//д���Ѿ���ʱ
//void main()
//{
//
//}

// main�����ǳ������ڣ������Ǵ�main�����ĵ�һ�п�ʼִ�е�
// main����ֻ��һ����һ�����̣����̣�����ֻ������ֻ��һ��main����

// scanf-���� printf-��� һ��

#include <stdio.h>	// std-��׼ i-input o-output


int main()	// int ����ֵ����Ϊ����   main�Ǻ�����
{
	int num = 0;
	scanf("%d\n",&num);
	printf("%d\n",num);
	printf("hello bit\n");	// printf �ǿ⺯����c���������ṩ�ĺ�������Ҫ����ͷ�ļ�
	printf("\n");
	printf("\n");
	printf("%d\n",sizeof(char));		// 1byte
	printf("%d\n",sizeof(short));		// 2byte					ֻ�ܱ�ʾ0-65535
	printf("%d\n",sizeof(int));			// 4byte
	printf("%d\n",sizeof(long));		// 4byte(32λ)/8byte(64λ)	��׼�涨��sizeof(long) >= sizeof(int)
	printf("%d\n",sizeof(long long));	// 8byte					��׼�涨��sizeof(long long) >= sizeof(long)
	printf("%d\n",sizeof(float));		// 4byte
	printf("%d\n",sizeof(double));		// 8byte

	return 0;
}

//��������
//char �ַ���������
//short ������
//int ����
//long ������
//long long ����������
//float �����ȸ�����	123.45 12.345*10 1234.5*10^-1
//double ˫���ȸ�����


//���������С�ĵ�λ
//����λ bit
//�ֽ� byte
//KB
//MB
//GB
//TB

//������ 1 0 һ���洢��С����һ������λ
//�涨��8��bit = 1��byte
//�涨��1��MB=1024��KB

//c�����и��ؼ��� sizeof(����)--�������ʹ������������ٿռ�Ĵ�С