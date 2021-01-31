#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static T* Partition(T* start, T* end) ;

    static void sortSegment(T* start, T* end, int segment_idx, int cur_segment_total)
    {
        int size = end - start;
        int step = cur_segment_total;
        int idxMin = segment_idx;
        for (int i = segment_idx; i < size - step; i += step) {
            idxMin = i;
            for (int j = i + step; j < size; j += step) {
                if (start[j] < start[idxMin]) idxMin = j;
            }
            T temp = start[i];
            start[i] = start[idxMin];
            start[idxMin] = temp;
        }
    }
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
    /* Function to print an array for mergesort */
    // static void printArray(T *start, T *end)
    // {
    //     long size = end - start + 1;
    //     for (int i = 0; i < size - 1; i++)
    //         cout << start[i] << ", ";
    //     cout << start[size - 1];
    //     cout << endl;
    // }

    static void ShellSort(T* start, T* end, int* num_segment_list, int num_phases)
    {
        for (int i = num_phases - 1; i >= 0; i--) {
            cout << num_segment_list[i] << " segment: ";
            for (int j = 0; j < num_segment_list[i]; j++) {
                sortSegment(start, end, j, num_segment_list[i]);
            }
            printArray(start, end);
        }
    }

    static void selectionSort(T *start, T *end);

    static void oddEvenSort(T *start, T *end);

    static void QuickSort(T* start, T* end) ;

    static void merge(T* left, T* middle, T* right){
        /*TODO*/
        int a, b, c;
        int n1 = middle - left;
        int n2 = right - middle - 1;
        T* Left = new T(n1);
        T* Right = new T(n2);
        for (a = 0; a < n1; a++) {
            Left[a] = left[a];
        }
        for (b = 0; b < n2; b++) {
            Right[b] = middle[b + 1];
        }
        a = 0; b = 0; c = 0;
        while (a < n1 && b < n2) {
            if (Left[a] <= Right[b]) {
                left[c] = Left[a];
                a++;
            }
            else {
                left[c] = Right[b];
                b++;
            }
            c++;
        }
        while (a < n1) {
            left[c] = Left[a];
            a++;
            c++;
        }
        while (b < n2) {
            left[c] = Right[b];
            b++;
            c++;
        }
        Sorting::printArray(left, right);
    }
    static void mergeSort(T* start, T* end) {
       /*TODO*/
       int l = 0;
       int r = end - start;
       int m = l + r / 2;
       if (l < r) {
           mergeSort(&start[l], &start[m]);
           mergeSort(&start[m + 1], &start[r]);
           merge(&start[l], &start[m], &start[r]);
       }
    }

    static void insertionSort(T *start, T *end);

    static void hybridQuickSort(T *start, T *end, int min_size);
};

template <class T>
void Sorting<T>::selectionSort(T *start, T *end)
{
    int curr = 0;
    int size = end - start;
    while(curr < size - 1) {
        int smallest = curr;
        int walker = curr + 1;
        while (walker < size) {
            if (start[walker] < start[smallest]) smallest = walker;
            walker++;
        }
        T temp = start[curr];
        start[curr] = start[smallest];
        start[smallest] = temp;
        curr++;
        printArray(start, end);
    }
}

template <class T>
void Sorting<T>::oddEvenSort(T *start, T *end)
{
    int size = end - start;
    bool isSorted = false;
    while (!isSorted) {
        isSorted = true;
        for (int i = 0; i <= size - 2; i = i + 2) {
            if (start[i] > start[i + 1]) {
                swap(start[i], start[i + 1]);
                isSorted = false;
            }
        }
        for (int i = 1; i <= size - 2; i = i + 2) {
            if (start[i] > start[i + 1]) {
                swap(start[i], start[i + 1]);
                isSorted = false;
            }
        }
        printArray(start, end);
    }
}

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
void Sorting<T>::QuickSort(T* start, T* end) {
    // TODO
    // In this question, you must print out the index of pivot in subarray after everytime calling method Partition.
    int low = 0;
    int high = end - start;
    if (low < high) {
        T* partition = Partition(start, end);
        QuickSort(start, partition);
        QuickSort(partition + 1, end);
    }
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
    int size = end - start;
    T* l = start + 0;
    T* r = start + size - 1;
    while (l < r + 1) {
        if (size < min_size) {
            cout << "Insertion sort: ";
            printArray(start, end);
            insertionSort(start, end);
            break;
        }
        else {
            T* pivot = Partition(start, end);
            if (pivot - l < r - pivot) {
                cout << "Quick sort: ";
                printArray(start, end);
                hybridQuickSort(start, pivot - 1, min_size);
                l = pivot + 1;
            }
            else {
                cout << "Quick sort: ";
                printArray(start, end);
                hybridQuickSort(pivot + 1, end, min_size);
                r = pivot - 1;
            }
        }
    }
} 
int main()
{
    int array[] = { 3, 5, 7, 10 ,12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19 };
    cout << "Index of pivots: ";
    Sorting<int>::QuickSort(&array[0], &array[20]);
    cout << "\n";
    cout << "Array after sorting: ";
    for (int i : array) cout << i << " ";
    return 0;
}