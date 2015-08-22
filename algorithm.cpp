// algorithm.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "shellsort.hpp"
#include "selectsort.hpp"
#include "mergesort.hpp"
#include "heapsort.hpp"

int main()
{
    //int arri[] = { 10, 9, 2, 5, 8, 3, 4, 7, 1, 6, 11, 55, 64, 88, 53, 22, 11, 45, 32, 12, 64, 66, 67, 88, 89, 98, 73, 71, 21, 15 };
    int arri[] = {10, 9, 2, 5, 8, 4, 3, 7, 1, 6};
    printf("数组长度 : %d\n", sizeof(arri) / sizeof(int));

    heapsort sort;
/*    mergersort sort;
    selectsort sort;
    shellsort sort;
    bubblesort bsort;        
    insertionsort isort;*/

    sort.sort(arri, sizeof(arri) / sizeof(int));

    getchar();
    return 0;
}

