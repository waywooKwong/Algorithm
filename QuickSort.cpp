#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}

int partition(int* a, int l, int r)
{
    int pivot = a[r];
    int index = l - 1;
    for (int j = l; j < r; j++)
    {
        if (a[j] <= pivot)
        {
            index++;
            swap(a[index], a[j]);
        }
    }
    swap(a[index + 1], a[r]);
    return index + 1;
}

void quickSort(int* a, int l, int r)
{
    if (l < r)
    {
        int mid = partition(a, l, r);
        quickSort(a, l, mid - 1);
        quickSort(a, mid + 1, r);
    }
}

int main()
{
    int size = 0;
    cout << "Enter array size: ";
    cin >> size;
    cout << "Enter array elements: ";
    int* a = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }
    quickSort(a, 0, size - 1);
    cout << "Array after sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    delete[] a;
    return 0;
}
