#pragma once
#include "basesort.hpp"

class insertionsort : private basesort
{
public:
    // ͨ�� basesort �̳�
    virtual void sort(int arr[], int num) override;
};

void insertionsort::sort(int arr[], int num)
{
    print(arr, num);
    int j = 0;
    for (int i = 1; i < num; ++i) {
        int ntemp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > ntemp; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = ntemp;
        print(arr, num);
    }
}