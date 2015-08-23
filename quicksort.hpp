#pragma once
#include "basesort.hpp"

class quicksort : private basesort
{
public:
    quicksort();
    ~quicksort();

    // 通过 basesort 继承
    virtual void sort(int arr[], int num) override;
    
    void sort(int arr[], int nLeft, int nRight);
};

quicksort::quicksort()
{
}

quicksort::~quicksort()
{
}

inline void quicksort::sort(int arr[], int num)
{
    print(arr, num);
    sort(arr, 0, num - 1);
}

inline void quicksort::sort(int arr[], int nLeft, int nRight)
{
    if (nLeft >= nRight) {
        return;
    }

    int i = nLeft;
    int j = nRight;
    int x = arr[nLeft];

    while (i < j) {
        while (i < j && arr[j] >= x) { // 从右向左找第一个小于x的数
            --j;
        }

        if (i < j) {
            arr[i] = arr[j];
            print(arr, 10, true);
            ++i;
        }

        while (i < j && arr[i] < x) { // 从左向右找第一个大于等于x的数
            ++i;
        }

        if (i < j) {
            arr[j] = arr[i];
            print(arr, 10, true);
            --j;
        }
    }
    arr[i] = x;
    print(arr, 10);
    sort(arr, nLeft, i - 1); // 递归调用
    sort(arr, i + 1, nRight);
}