#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//void* mymemmove(void* arr1, const void* arr2, size_t count)
//{
//	void* ret = arr1;
//	while (count--)
//	{
//		*(char*)arr1 = *(char*)arr2;
//		((char*)arr1)++;
//		((char*)arr2)++;
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr2[8] = { 1,2,3,4,5,6,7,8 };
//	int* p = NULL;
//	mymemmove(arr2+3, arr2, 20);
//	return 0;
//}


int main()
{
    unsigned char puc[4];
    struct tagPIM
    {
        unsigned char ucPim1;
        unsigned char ucData0 : 1;
        unsigned char ucData1 : 2;
        unsigned char ucData2 : 3;
    }*pstPimData;
    pstPimData = (struct tagPIM*)puc;
    memset(puc, 0, 4);
    pstPimData->ucPim1 = 2;
    pstPimData->ucData0 = 3;
    pstPimData->ucData1 = 4;
    pstPimData->ucData2 = 5;
    printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
    return 0;
}
//   02 29 00 00

//#define MAX_SIZE A+B
//struct _Record_Struct
//{
//	unsigned char Env_Alarm_ID : 4;
//	unsigned char Para1 : 2;
//	unsigned char state;
//	unsigned char avail : 1;
//}*Env_Alarm_Record;
//struct _Record_Struct* pointer = (struct _Record_Struct*)malloc(sizeof(struct _Record_Struct) * MAX_SIZE);
//  3 * 2+3


//int main()
//{
//	struct S2
//	{
//		char c1;
//		char c2;
//		int i;
//	};
//	printf("%d\n", sizeof(struct S2));
//}