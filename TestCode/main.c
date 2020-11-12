#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main() {
    int a, b, c;
    while ((scanf("%d %d %d", &a, &b, &c) != EOF))
    {
        getchar();
        if ((a + b > c) && (a + c > b) && (b + c > a))
        {
            if (a == b && a == c)
            {
                printf("Equilateral triangle!\n");
            }
            else if (a == b || b == c || a == c) 
            {
                printf("Isosceles triangle!\n");

            }
            else
            {
                printf("Ordinary triangle!\n");
            }
        }
        else {
            printf("Not a triangle!\n");
        }
    }
    return 0;
}