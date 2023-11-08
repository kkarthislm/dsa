#include <iostream>

using namespace std;

void counting_sort(int *a, int size)
{
    // find max
    int max_num = -1;
    for (int i = 0; i < size; i++)
    {
        max_num = max(max_num, a[i]);
    }

    // arry to store the freq of original array values
    int temp[max_num + 1] = {0};
    for (int i = 0; i < size; i++)
    {
        temp[a[i]]++;
    }

    for (int i = 1; i < max_num + 1; i++)
    {
        temp[i] += temp[i - 1];
    }

    int result[size] = {0};
    for (int i = size - 1; i >= 0; i--)
    {
        result[temp[a[i]] - 1] = a[i];
        temp[a[i]]--;
    }

    for (int i = 0; i < size; i++)
    {
        cout << result[i] << endl;
    }
}

int main()
{
    int array[] = {6, 5, 8, 1, 4, 7, 9, 0, 1, 2, 2};
    counting_sort(array, sizeof(array) / sizeof(int));

    return 0;
};
