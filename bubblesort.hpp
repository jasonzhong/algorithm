#pragma once
#include "basesort.hpp"

class bubblesort : private basesort
{
public:
	bubblesort();
	~bubblesort();

    // ͨ�� basesort �̳�
    virtual void sort(int arr[], int num) override;
};

bubblesort::bubblesort()
{
}

bubblesort::~bubblesort()
{
}

void bubblesort::sort(int arr[], int num)
{  
    for (int i = 0; i < num; ++i) {
        for (int j = 1; j < (num - i); ++j) {
            if (arr[j - 1] > arr[j]) {
                swap1(&arr[j - 1], &arr[j]);
                print(arr, num);
            }
        }
    }
}
