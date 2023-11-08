#include <iostream>

using namespace std;

void insertion_sort(int *a, int size)
{

    // insertion sort
    for(int i = 0; i < size-1; i++){
        for(int j = i+1; j > 0; j--){
            if(a[j] < a[j-1]){
                a[j] = a[j] + a[j-1];
                a[j-1] = a[j] - a[j-1];
                a[j] = a[j] - a[j-1];
            }
        }
    }

    // print result
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int array[] = {6, 5, 8, 1, 4, 7, 9, 0, 1, 2, 2};
    insertion_sort(array, sizeof(array) / sizeof(int));

    return 0;
};
