#pragma once
#include "basesort.hpp"

class selectsort : private basesort
{
public:
    selectsort();
    ~selectsort();

    // Í¨¹ý basesort ¼Ì³Ð
    virtual void sort(int arr[], int num) override;
};

selectsort::selectsort()
{
}

selectsort::~selectsort()
{
}

void selectsort::sort(int arr[], int num)
{
    print(arr, num);
    for (int i = 0; i < num; i++) {
        int Mindex = i;
        for (int j = i + 1; j < num; j++) {
            if (arr[j] < arr[Mindex]) {
                Mindex = j;
            }
        }
        swap1(&arr[i], &arr[Mindex]);
        print(arr, num);
    }
}
