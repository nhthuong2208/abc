#include <sstream>
#include <iostream>

using namespace std;
template <class T>
class Sorting {
private:
    static void printArray(T* start, T* end)
    {
        int  size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << " ";
        cout << start[size - 1];
        cout << endl;
    }

    static void merge(T* start, T* middle, T* end)
    {
        int a, b, c;
        int n1 = (middle - start + 1);
        int n2 = (end - middle > 0 ) ? (end - middle) : 0;
        int Left[n1] = {0};
        int Right[n2] = {0};
        for (a = 0; a < n1; a++) {
            Left[a] = start[a];
        }
        for (b = 0; b < n2; b++) {
            Right[b] = middle[b + 1];
        }
        a = 0; b = 0; c = 0;
        while (a < n1 && b < n2) {
            if (Left[a] <= Right[b]) {
                start[c] = Left[a];
                a++;
            }
            else {
                start[c] = Right[b];
                b++;
            }
            c++;
        }
        while (a < n1) {
            start[c] = Left[a];
            a++;
            c++;
        }
        while (b < n2) {
            start[c] = Right[b];
            b++;
            c++;
        }
    }
public:
    static void InsertionSort(T* start, T* end)
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
    static void TimSort(T* start, T* end, int min_size)
    {
        int a = 0;
        int Size = end - start;
        if (Size == 0) return;
        for (int i = 0; i < Size; i += min_size) {
            InsertionSort(&start[0 + i], &start[min_size + i]);
        }
        cout << "Insertion Sort: ";
        printArray(start, end);

        for (int size = min_size; size < Size; size = size*2) {
            for (int left = 0; left < Size; left += 2*size) {
                a++;
                int m = left + size - 1;
                int r = ((left + 2*size - 1) > (Size - 1)) ? (Size - 1) : (left + 2*size - 1);
                merge(&start[left], &start[m], &start[r]);
                cout << "Merge " << a << ": ";
                printArray(start, end);
            }
        }
    }
};

int main()
{
    int array[] = {};
    int min_size = 0;
    Sorting<int>::TimSort(&array[0], &array[0], min_size);
    return 0;
}