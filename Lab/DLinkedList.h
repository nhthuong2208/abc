#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
    class Iterator;
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList()
    {
        head = tail = NULL;
        count = 0;
    }
    ~DLinkedList()
    {

    }
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
    string toString()
    {
        stringstream ss;
    ss << "[";
    Node *ptr = this->head;

    if (this->count == 0)
        ss << "]";

    // TODO
    else {
        ss << ptr->data;
        ptr = ptr->next;
        while (ptr != NULL) {
            ss << ", " << ptr->data;
            ptr= ptr->next;
        }
        ss << "]";
    }
    return ss.str();
    }
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
    
};

template <class T>
void DLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    Node* temp = new Node;
    temp->data = e;
    if (this->tail == NULL) {
        tail = temp;
        head = temp;
        temp->next = NULL;
        temp->previous = NULL;
    }
    else {
        this->tail->next = temp;
        temp->previous = this->tail;
        temp->next = NULL;
        this->tail = temp;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    Node* temp = new Node;
    temp->data = e;
    if (index > count) throw std::out_of_range("Segmentation fault!");
    else if (index == count) {
        add(e);
    }
    else if (index == 0) {
        temp->next = this->head;
        temp->previous = NULL;
        this->head->previous = temp;
        this->head = temp;
        count++;
    }
    else {
        Node* tmp = this->head;
        for (int i = 0; i < index - 1; i++) {
            tmp = tmp->next;
        }
        temp->next = tmp->next;
        temp->previous = tmp;
        tmp->next->previous = temp;
        tmp->next = temp;
        count++;
    }
}

template<class T>
int DLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    return count;
}

template<class T>
T DLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    Node* temp = this->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
void DLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    Node* temp = this->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    temp->data = e;
}

template<class T>
bool DLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return count == 0;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node* temp = this->head;
    int res = 0;
    while (temp != NULL) {
        if (temp->data == item) break;
        ++res;
        temp = temp->next;
    }
    if (res == count) return -1;
    else return res;
}

template<class T>
bool DLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    if (indexOf(item) == -1) return false;
    else return true;
}

template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index >= count || index < 0) throw std::out_of_range("Segmentation fault!");
    else if (index == 0) {
        Node* temp = this->head;
        T res = this->head->data;
        if (temp->next != NULL) {
            temp->next->previous = temp->previous;
        }
        else tail = NULL;
        head = temp->next;
        delete(temp);
        count--;
        return res;
    }
    else if (index == count - 1) {
        Node* temp = tail;
        T res = tail->data;
        if (temp->previous != NULL) {
            temp->previous->next = temp->next;
        }
        else head = NULL;
        tail = temp->previous;
        delete(temp);
        count--;
        return res;
    }
    else {
        Node* temp = head;
        for (int i = 0; i < index; i++) {
            if (temp != NULL) {
                temp = temp->next;
            }
        }
        T res = temp->data;
        if (temp->previous != NULL) {
            temp->previous->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->previous = temp->previous;
        }
        delete(temp);
        count--;
        return res;
    }
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if (contains(item)) {
        removeAt(indexOf(item));
        return true;
    }
    else return false;
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
    Node* ptr = head;
    while (ptr != NULL) {
        Node* temp = ptr;
        ptr = temp->next;
        delete(temp);
    }
    count = 0;
    head = tail = NULL;
}

/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin) 
{
    this->pList = pList;
    if (begin) {
        if (pList != NULL) {
            this->current = pList->head;
            this->index = 0;
        }
        else {
            this->current = NULL;
            this->index = -1;
        }
    }
    else {
        this->current = NULL;
        if (pList != NULL) this->index = pList->size();
        else this->index = 0;
    }
}

template <class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
}

template <class T> 
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (this->current == NULL) throw std::out_of_range("Segmentation fault!");
    else this->pList->set(index, e);
}

template<class T>
T& DLinkedList<T>::Iterator::operator*() 
{
    if (this->current == NULL) throw std::out_of_range("Segmentation fault!");
    else return this->current->data;
}

template<class T>
void DLinkedList<T>::Iterator::remove() 
{
    /*
    * TODO: delete Node in pList which Node* current point to. 
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
    */
    if (this->current == NULL) throw std::out_of_range("Segmentation fault!");
    else if (index == 0) {
        this->current = NULL;
        this->pList->removeAt(0);
        this->index = -1;
    }
    else {
        this->pList->removeAt(index);
        this->current = this->current->previous;
        this->index--;
    }
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator) 
{
    if (current == iterator.current && pList == iterator.pList && index == iterator.index) return false;
    return true;
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() 
{
    if (index > pList->count - 1) throw std::out_of_range("Segmentation fault!");
    else if (index == -1) {
        this->current = pList->head;
        this->index++;
    }
    else {
        if (current != NULL) {
            this->current = this->current->next;
        }
        this->index++;
    }
    return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) 
{
    Iterator iterator = *this;
    ++*this;
    return iterator;
}