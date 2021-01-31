#include <iostream>
#include <math.h>
using namespace std;

int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int step = sqrt(n);
    int res = 0;
    cout << res << " ";

    if (arr[0] == x) return 0;
    while (arr[step] <= x && step < n)  {
        res = step;
        step += sqrt(n);

        cout << res << " ";
        if (arr[res] == x) return res;
        if (step > n - 1) break;
    }
    cout << step << " ";

    if (arr[res] == x) return res;

    for (int i = res; i < step && i < n; i++) {
        cout << i << " ";
        if (arr[i] == x) return i;
    }

    return -1;
    
}

int binarySearch(int arr[], int left, int right, int x)
{
    if (right - left < 0) return -1;
    int middle = left + (right-left)/2;
    cout << "We traverse on index: " << middle << endl;
    if (arr[middle] == x) return middle;
    else if (arr[middle] > x) return binarySearch(arr, left, middle - 1, x);
    else return binarySearch(arr, middle + 1, right, x);
}

int interpolationSearch(int arr[], int left, int right, int x)
{
    int pos;
    if (left <= right && x >= arr[left] && x <= arr[right]) {
        pos = left + ((x - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        if (pos != -1) cout << "We traverse on index: " << pos << endl;
        if (arr[pos] == x) return pos;
        else if (arr[pos] < x) return interpolationSearch(arr, pos + 1, right, x);
        else return interpolationSearch(arr, left, pos - 1, x);
    }
    return -1;
}

int main()
{
    int arr[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610 };
int x = 55;
int n = sizeof(arr) / sizeof(arr[0]);
int index = jumpSearch(arr, x, n);

if (index != -1) {
    cout << "\nNumber " << x << " is at index " << index;
}
else {
    cout << "\n" << x << " is not in array!";
}
}