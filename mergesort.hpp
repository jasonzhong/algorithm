#pragma once
#include "basesort.hpp"

class mergersort : private basesort
{
public:
    mergersort();
    ~mergersort();

    // 通过 basesort 继承
    virtual void sort(int arr[], int num) override;

    void mergesort(int arr[], int first, int last, int temp[]);
    void mergearray(int arr[], int first, int mid, int last, int temp[]);
};

mergersort::mergersort()
{
}

mergersort::~mergersort()
{
}

void mergersort::sort(int arr[], int num)
{
    print(arr, num);
    int *parr = new int[num];
    if (!parr) {
        return;
    }

    mergesort(arr, 0, num - 1, parr);

    delete[] parr;
}

inline void mergersort::mergesort(int arr[], int first, int last, int temp[])
{
    if (first >= last) {
        return;
    }

    int mid = (first + last) / 2;
    mergesort(arr, first, mid, temp);    //左边有序
    mergesort(arr, mid + 1, last, temp); //右边有序
    mergearray(arr, first, mid, last, temp); //再将二个有序数列合并
}

inline void mergersort::mergearray(int arr[], int first, int mid, int last, int temp[])
{
    int i = first;
    int j = mid + 1;
    int m = mid;
    int n = last;
    int k = 0;

    while (i <= m && j <= n) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            ++k;
            ++i;
        } else {
            temp[k] = arr[j];
            ++k;
            ++j;
        }
    }

    while (i <= m) {
        temp[k] = arr[i];
        ++k;
        ++i;
    }

    while (j <= m) {
        temp[k] = arr[j];
        ++k;
        ++j;
    }

    for (i = 0; i < k; ++i) {
        arr[first + i] = temp[i];
        print(arr, 10, true);
    }
    print(arr, 10);
}
