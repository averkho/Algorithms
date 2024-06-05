#include <iostream>

void print(int arr[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << "   ";
    }
    std::cout << std::endl;
}

void merge(int arr[], int left_index, int middle_index, int right_index)
{

    int n1 = middle_index - left_index + 1;
    int n2 = right_index - middle_index;


    int *L = new int[n1];
    int *R = new int[n2];

    for (int i = 0; i < n1; ++i) L[i] = arr[left_index + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[middle_index + 1 + j];

    int i {0};
    int j {0};
    int k {left_index};

    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            ++i;
        }
        else
        {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    } 

    while (i < n1)
    {
        arr[k] = L[i];
        ++i;
        ++k;

    }

    while (j < n2)
    {
        arr[k] = R[j];
        ++j;
        ++k;
    }

    delete[] L;
    delete[] R;

}

void mergeSort(int arr[], int left_index, int right_index)
{
    if (left_index < right_index)
    {
        int middle_index = left_index + (right_index - left_index) / 2;

        mergeSort(arr,left_index, middle_index);
        mergeSort(arr, middle_index + 1, right_index);
        merge(arr, left_index, middle_index, right_index);
    }
    

}



int main()
{
    int arr[] = {2,3,1,3,42,42,3,7,6,4,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    print(arr, size);
    mergeSort(arr, 0, size-1);
    print(arr, size);
    return 0;
}