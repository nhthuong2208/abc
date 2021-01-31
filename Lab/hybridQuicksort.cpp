#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static T* Partition(T* start, T* end) ;
public:
    /* Function to print an array */
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void insertionSort(T *start, T *end);

    static void hybridQuickSort(T *start, T *end, int min_size);
};

template <class T>
T* Sorting<T>::Partition(T* start, T* end) {
    // TODO: return the pointer which points to the pivot after rearrange the array.
    T pivot = start[0];
    int left = 1;
    int right = end - start - 1;
    while(true) {
        while (left <= right && start[left] < pivot) left++;
        while (left <= right && start[right] > pivot) right--;
        if (left > right) break;
        swap(start[left], start[right]);
        left++;
        right--;
    }
    swap(start[right], start[0]);
    //cout << right << " ";
    return start + right;
}

template <class T>
void Sorting<T>::insertionSort(T *start, T *end)
{
    int size = end - start;
    int curr = 1;
    while (curr < size) {
        T temp = start[curr];
        int walker = curr - 1;
        while (walker >= 0 && temp < start[walker]) {
            start[walker + 1] = start[walker];
            walker--;
        }
        start[walker + 1] = temp;
        curr++;
    }
}

template <class T>
void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size)
{
    int low = 0;
    int size = end - start;
    if (low < size) {
        if (size < min_size) {
            cout << "Insertion sort: ";
            printArray(start, end);
            insertionSort(start, end);
            //break;
        }
        else {
            cout << "Quick sort: ";
            printArray(start, end);
            T* pivot = Partition(start, end);
            hybridQuickSort(start, pivot, min_size);
            hybridQuickSort(pivot + 1, end, min_size);
        }
    }
} 

int main()
{
    int array[] = {30, 7, 20, 0, -13, 1, 19, 72};
    int min_size = 3;
    Sorting<int>::hybridQuickSort(&array[0], &array[8], min_size);
    return 0;
}