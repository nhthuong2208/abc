
#ifndef STACK_H
#define STACK_H
#include "DLinkedList.h"
template<class T>
class Stack {
protected:
    DLinkedList<T> list;
public:
    Stack() {}
    void push(T item) {
        list.add(item);
    }
    T pop() {
        return list.removeAt(list.size() - 1);
    }
    T top() {
        return list.get(list.size() - 1);
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
bool isValidParentheses (string s){
    /*TODO*/
    Stack<char> res;
    for (int i = 0; i < (int)(s.length()); i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') res.push(s[i]);
        if (s[i] == ']' && res.top() == '[') res.pop();
        if (s[i] == '}' && res.top() == '{') res.pop();
        if (s[i] == ')' && res.top() == '(') res.pop();
    } 
    if (res.empty()) return true;
    else return false;
}


int main()
{
   cout << isValidParentheses("[({})]");
    return 0;
}