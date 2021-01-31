#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"
template<class T>
class Heap {
protected:
    T* elements;
    int capacity;
    int count;
public:
    Heap()
    {
        this->capacity = 10;
        this->count = 0;
        this->elements = new T[capacity];
    }
    ~Heap()
    {
        delete[]elements;
    }
    void push(T item);
    int getItem(T item);
    void remove(T item);
    void clear();
    
    bool isEmpty();
    bool contains(T item);
    T peek();
    bool pop();
    int size();
    
    void printHeap()
    {
        cout << "Max Heap [ ";
        for (int i = 0; i < count; i++)
            cout << elements[i] << " ";
        cout << "]\n";
    }
private:
    void ensureCapacity(int minCapacity);
    void reheapUp(int position);
    void reheapDown(int position);
};

template<class T>
int Heap<T>::size(){
    if (count >= 0) return this->count;
    return -1;
}

template<class T>
bool Heap<T>::isEmpty(){
    return (this->count == 0) ? true : false;
}

template<class T>
T Heap<T>::peek(){
    if (elements) return elements[0];
    return -1;
}

template<class T>
bool Heap<T>::contains(T item){
    if (elements == NULL) return false;
    for (int i = 0; i < capacity; i++) {
        if (elements[i] == item) return true;
    }
    return false;
}

template<class T>
bool Heap<T>::pop(){
    if (elements == NULL) return false;

    elements[0] = elements[count - 1];
    count = count - 1;
    reheapDown(0);
    return true;
}

template<class T>
void Heap<T>::push(T item){
    ensureCapacity(count);
    elements[count] = item;
    count += 1;
    reheapUp(count - 1);
}

template<class T>
void Heap<T>::ensureCapacity(int minCapacity){
    if (minCapacity == capacity) {
        capacity += 1;
        T* newelement = new T[capacity];
        for (int i = 0; i < count; i++) {
            newelement[i] = elements[i];
        }
        delete elements;
        this->elements = newelement;
    }
}

template<class T>
void Heap<T>::reheapUp(int position){
    if (position > 0) {
        int parent = (position - 1) / 2;
        if (elements[position] > elements[parent]) {
            swap(elements[position], elements[parent]);
            reheapUp(parent);
        }
    }
}

template<class T>
void Heap<T>::reheapDown(int position) {
    int leftChild = position * 2 + 1;
    int rightChild = position * 2 + 2;
    int largeChild;
    if (leftChild <= count) {
        if (rightChild <= count && (elements[rightChild] > elements[leftChild])) {
            largeChild = rightChild;
        }
        else {
            largeChild = leftChild;
        }
        if (elements[largeChild] > elements[position]) {
            swap(elements[largeChild], elements[position]);
            reheapDown(largeChild);
        }
    }
}

void reheapDown(int maxHeap[], int numberOfElements, int index)
{
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;
    int largeChild;
    if (leftChild <= numberOfElements) {
        if (rightChild <= numberOfElements && (maxHeap[rightChild] > maxHeap[leftChild])) {
            largeChild = rightChild;
        }
        else {
            largeChild = leftChild;
        }
        if (maxHeap[largeChild] > maxHeap[index]) {
            swap(maxHeap[largeChild], maxHeap[index]);
            reheapDown(maxHeap, numberOfElements, largeChild);
        }
    }
}

void reheapUp(int maxHeap[], int numberOfElements, int index)
{
    if (index > 0) {
        int parent = (index - 1) / 2;
        if (maxHeap[index] > maxHeap[parent]) {
            swap(maxHeap[index], maxHeap[parent]);
            reheapUp(maxHeap, numberOfElements, parent);
        }
    }
}

template<class T>
int Heap<T>::getItem(T item) {
    // TODO: return the index of item in heap
    if (!elements) return -1;
    int res = -1;
    for (int i = 0; i < count; i++) {
        if (elements[i] == item) {
            res = i;
            break;
        }
    }
    return res;
}

template<class T>
void Heap<T>::remove(T item) {
    // TODO: remove the element with value equal to item
    if (elements) {
        int a = getItem(item);
        if (a != -1) {
            elements[a] = elements[count - 1];
            count = count - 1;
            reheapDown(a);
        }
    }
}

template<class T>
void Heap<T>::clear() {
    // TODO: delete all elements in heap
    if (elements) {
        delete[] elements;
        count = 0;
    }
}


void heapsort(int arr[], int count) {
    int position = count / 2 - 1;
    while (position >= 0) {
        reheapDown(arr, count - 1, position);
        position -= 1;
    }
    int last = count - 1;
    while (last > 0) {
        swap(arr[0], arr[last]);
        last -= 1;
        reheapDown(arr, last - 1, 0);
    }
}

int main()
{
    
int arr[] = { 13, 19, 20, 7, 15, 12, 16, 10, 8, 9, 3, 6, 18, 2, 14, 1, 17, 4, 11, 5 };
heapsort(arr, 20);
for (int i = 0; i < 20; i++) {
    cout << arr[i] << " ";
}
}