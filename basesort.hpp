#pragma once

#ifndef __BASESORT_H_
#define __BASESORT_H_

#include <iostream>

class basesort
{
public:
	basesort();
	virtual ~basesort();

	void swap1(int *left, int *right);
	void swap2(int &left, int &right);
	void swap3(int &left, int &right);

    void print(int arr[], int num, bool bprocess = false);
    void print(int arr[], int first, int num, bool bprocess = false);

    virtual void sort(int arr[], int num) = 0;

public:
    int m_nLine;
};

basesort::basesort()
{
    m_nLine = 0;
}

basesort::~basesort()
{
}

inline void basesort::swap1(int * left, int * right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

inline void basesort::swap2(int & left, int & right)
{
	int temp = left;
	left = right;
	right = left;
}

inline void basesort::swap3(int & left, int & right)
{
	if (&left != &right) {
		left ^= right;
		right ^= left;
		left ^= right;
	}
}

inline void basesort::print(int arr[], int num, bool bprocess)
{
    if (!bprocess) {
        printf("%02d : ", m_nLine);
        ++m_nLine;
    } else {
        printf("     ");
    }
    for (int i = 0; i < num; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

inline void basesort::print(int arr[], int first, int num, bool bprocess)
{
    if (!bprocess) {
        printf("%02d : ", m_nLine);
        ++m_nLine;
    }
    else {
        printf("     ");
    }
    for (int i = first; i < (first + num); ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

#endif // __BASESORT_H_