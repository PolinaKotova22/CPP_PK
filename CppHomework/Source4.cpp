#pragma once
#include<iostream>
#include<Windows.h>

using namespace std;

// #1

void sortArray(int arr[], int size, bool reverse = false)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1 - i; j++)
        {
            if (reverse == false)
            {
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
            else
            {
                if (arr[j] < arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
    }
}