#define SEPARATOR "#<ab@17943918#@>#"
#ifndef SORTING_H
#define SORTING_H
#include <iostream>
using namespace std;
template <class T>
class Sorting {
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        long size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }
    
    //Helping functions go here

    static void builtHeap(T* start, T* end, int i) {
        int largeChild = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int size = end - start;
        if (leftChild < size && start[leftChild] > start[largeChild]) {
            largeChild = leftChild;
        }
        if (rightChild < size && start[rightChild] > start[largeChild]) {
            largeChild = rightChild;
        }
        if (largeChild != i) {
            swap(start[largeChild], start[i]);
            builtHeap(start, end, largeChild);
        }
    }

    static void heapSort(T* start, T* end){
        //TODO
        int size = end - start;
        for (int i = size / 2 - 1; i >= 0; i--) {
            builtHeap(start, end, i);
            Sorting<T>::printArray(start,end);
        }
        for (int i = size - 1; i > 0; i--) {
            swap(start[0], start[i]);
            Sorting<T>::printArray(start,end);
            builtHeap(start, start + i, 0);
            Sorting<T>::printArray(start,end);
        }
        Sorting<T>::printArray(start,end);
    }
    
};
#endif /* SORTING_H */

int main()
{
    int arr[4]={-1,0,2,3};
    Sorting<int>::heapSort(&arr[0],&arr[4]);


    return 0;
}