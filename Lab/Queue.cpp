#ifndef QUEUE_H
#define QUEUE_H
#include "DLinkedList.h"
template<class T>
class Queue {
protected:
    DLinkedList<T> list;
public:
    Queue() {}
    void push(T item) {
        list.add(item);
    }
    T pop() {
        return list.removeAt(0);
    }
    T top() {
        return list.get(0);
    }
    bool empty() {
        return list.empty();
    }
    int size() {
        return list.size();
    }
    void clear() {
        list.clear();
    }
};

#endif