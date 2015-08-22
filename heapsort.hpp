#pragma once
#include "basesort.hpp"

#define leftChild(i) (2*(i) + 1)

class heapsort : private basesort
{
public:
    heapsort();
    ~heapsort();

    // Í¨¹ý basesort ¼Ì³Ð
    virtual void sort(int arr[], int num) override;

    void percdown(int *arr, int i, int num);
};

heapsort::heapsort()
{
}

heapsort::~heapsort()
{
}

void heapsort::sort(int arr[], int num)
{
    print(arr, num);

    int i = 0;
    for (i = (num / 2); i >= 0; --i) {
        percdown(arr, i, num);
        print(arr, num);
    }

    for (i = (num - 1); i > 0; --i) {
        swap1(&arr[0], &arr[i]);
        print(arr, num);
        percdown(arr, 0, i);
    }
}

inline void heapsort::percdown(int *arr, int i, int num)
{
    int temp = 0;
    int child = 0;
    for (temp = arr[i]; leftChild(i) < num; i = child)
    {
        child = leftChild(i);
        if (child != num - 1 && arr[child + 1] > arr[child]) {
            ++child;
        }

        if (arr[child] > temp) {
            arr[i] = arr[child];
            print(arr, 10, true);
        } else {
            break;
        }
    }
    arr[i] = temp;
    print(arr, 10, true);
}
