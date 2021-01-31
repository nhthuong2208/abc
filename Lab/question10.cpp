#include <iostream>
#include <math.h>
using namespace std;

void ascendingSort(int a[], int n) {
    /*
     * STUDENT ANSWER
     * TODO: sort array in ascending order. 
     */
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void descendingSort(int a[], int n) {
    /*
     * STUDENT ANSWER
     * TODO: sort array in descending order. 
     */
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

void mySort(int a[], int n, void (*sort)(int[], int)) {
	/*
     * STUDENT ANSWER
     * TODO: sort array based on sort algorithm of function sort. 
     */
    if (sort == &ascendingSort) ascendingSort(a, n);
    else descendingSort(a, n);
}


int main() {
    int n = 10;
int a[10] = { 4, 6, 1, 3, 4, 7, 8, 9, 10, 0 };
void (*sortAlgorithm)(int[], int) = ascendingSort;
    mySort(a, n, sortAlgorithm);
    for (int i = 0; i < n; ++i) {
	printf("%d ", a[i]);
    }
	
    return 0;
}