#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main() 
{
    int n, i, j, flag = 1;
    scanf("%d", &n);
    int a[30] = { 0 };
    for (i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
        for (j = 0; j < i; j++) 
        {
            if (a[i] == a[j]) 
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            printf("%d ", a[i]);
        flag = 1;
    }
    return 0;
}

//int main() 
//{
//    int a, b, c;
//    while ((scanf("%d %d %d", &a, &b, &c) != EOF))
//    {
//        if ((a + b > c) && (a + c > b) && (b + c > a))
//        {
//            if (a == b && a == c)
//            {
//                printf("Equilateral triangle!\n");
//            }
//            else if (a == b || b == c || a == c) 
//            {
//                printf("Isosceles triangle!\n");
//            }
//            else
//            {
//                printf("Ordinary triangle!\n");
//            }
//        }
//        else 
//        {
//            printf("Not a triangle!\n");
//        }
//    }
//    return 0;
//}