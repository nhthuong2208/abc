#include <sstream>
#include <string>
#include <iostream>
#include <type_traits>
using namespace std;

#ifndef ILIST_H
#define ILIST_H

template <class T>
class IList
{
public:
    virtual void add(const T& element) = 0;
    virtual void add(int index, const T& element) = 0;
    virtual T removeAt(int index) = 0;
    virtual bool removeItem(const T& item) = 0;
    virtual bool empty() = 0;
    virtual int size() = 0;
    virtual void clear() = 0;
    virtual T get(int index) = 0;
    virtual void set(int index, const T& element) = 0;
    virtual int indexOf(const T& item) = 0;
    virtual bool contains(const T& item) = 0;
    virtual string toString() = 0;
};

#endif

// STUDENT ANSWER
#ifndef FRAGMENT_LINKED_LIST
#define FRAGMENT_LINKED_LIST
template <class T>
class FragmentLinkedList : IList<T>
{
public:
    class Node;
    class Iterator;

protected:
    Node **fragmentPointers;
    int fragmentMaxSize;
    int count;

public:
    FragmentLinkedList(int fragmentMaxSize = 5)
    {
        this->count = 0;
        this->fragmentMaxSize = fragmentMaxSize;
        this->fragmentPointers = new Node *[2];
        this->fragmentPointers[0] = NULL;
        this->fragmentPointers[1] = NULL;
    }
    virtual ~FragmentLinkedList()
    {
        this->count = 0;
        this->fragmentMaxSize = 0;
        delete[] fragmentPointers;
    }
    virtual void create(int index) {
		Node** newfragmentPointers = new Node*[int(count / fragmentMaxSize) + 2];
        if (index == count) {
            newfragmentPointers[0] = fragmentPointers[0];
            for (int i = 1; i < int(count / fragmentMaxSize) + 1; i++) {
                newfragmentPointers[i] = fragmentPointers[i];
            }
            //newfragmentPointers[count / fragmentMaxSize] = fragmentPointers[count / fragmentMaxSize]->next;
            newfragmentPointers[int(count / fragmentMaxSize) + 1] = fragmentPointers[int(count / fragmentMaxSize) + 1];
        }
        else if (index == 0 || int(index / fragmentMaxSize) == 0) {
            newfragmentPointers[0] = fragmentPointers[0];
            if (count % fragmentMaxSize == 0) {
                for (int i = 1; i < int(count / fragmentMaxSize); i++) {
                    newfragmentPointers[i] = fragmentPointers[i]->prev;
                }
                newfragmentPointers[int(count / fragmentMaxSize)] = fragmentPointers[int(count / fragmentMaxSize)];
                newfragmentPointers[int(count / fragmentMaxSize) + 1] = fragmentPointers[int(count / fragmentMaxSize)];
            }
            else {
                for (int i = 1; i < int(count / fragmentMaxSize) + 1; i++) {
                    newfragmentPointers[i] = fragmentPointers[i]->prev;
                }
                newfragmentPointers[int(count / fragmentMaxSize) + 1] = fragmentPointers[int(count / fragmentMaxSize) + 1];
            }
        }
        else {
            for (int i = 0; i < int(index / fragmentMaxSize) + 1; i++) {
                newfragmentPointers[i] = fragmentPointers[i];
            }
            if (count % fragmentMaxSize == 0) {
                for (int i = int(index / fragmentMaxSize) + 1; i < int(count / fragmentMaxSize); i++) {
                    newfragmentPointers[i] = fragmentPointers[i]->prev;
                }
                newfragmentPointers[int(count / fragmentMaxSize)] = fragmentPointers[int(count / fragmentMaxSize)];
                newfragmentPointers[int(count / fragmentMaxSize) + 1] = fragmentPointers[int(count / fragmentMaxSize)];
            }
            else {
                for (int i = int(index / fragmentMaxSize) + 1; i < int(count / fragmentMaxSize) + 1; i++) {
                    newfragmentPointers[i] = fragmentPointers[i]->prev;
                }
                newfragmentPointers[int(count / fragmentMaxSize) + 1] = fragmentPointers[int(count / fragmentMaxSize) + 1];
            }
        }
		this->fragmentPointers = newfragmentPointers;
	}
    virtual void add(const T& element)
    {
        Node* temp;
        if (count % fragmentMaxSize != 0) {
            temp = this->fragmentPointers[int(count / fragmentMaxSize) + 1];
        }
        else {
            temp = this->fragmentPointers[int(count / fragmentMaxSize)];
        }
        if (temp == NULL) {
            temp = new Node(element, NULL, NULL);
            this->fragmentPointers[0] = temp;
            this->fragmentPointers[int(count / fragmentMaxSize) + 1] = temp;
        }
        else {
            temp->next = new Node(element, NULL, temp);
            if (this->count % this->fragmentMaxSize == 0) {
                this->fragmentPointers[int(count / fragmentMaxSize)] = temp->next;
                this->fragmentPointers[int(count / fragmentMaxSize) + 1] = temp->next;
                create(count);
            }
            else {
                this->fragmentPointers[int(count / fragmentMaxSize) + 1] = temp->next;
            }
        }
        this->count++;
    }
    virtual void add(int index, const T& element)
    {
        if (index < 0 || index > count) throw std::out_of_range("Segmentation fault!");
        else if (index == count) {
            add(element);
        }
        else if (index == 0) {
            Node* temp = new Node(element, fragmentPointers[0], NULL);
            fragmentPointers[0]->prev = temp;
            fragmentPointers[0] = temp;
            if (this->count % this->fragmentMaxSize == 0) {
                fragmentPointers[int(count / fragmentMaxSize) + 1] = fragmentPointers[int(count / fragmentMaxSize)];
            }
            create(index);
            this->count++;
        }
        else if (index % fragmentMaxSize == 0) {
            Node* temp = new Node(element, fragmentPointers[int(index / fragmentMaxSize)], fragmentPointers[int(index / fragmentMaxSize)]->prev);
            fragmentPointers[int(index / fragmentMaxSize)]->prev->next = temp;
            fragmentPointers[int(index / fragmentMaxSize)]->prev = temp;
            fragmentPointers[int(index / fragmentMaxSize)] = fragmentPointers[int(index / fragmentMaxSize)]->prev;
            create(index);
            this->count++;
        }
        else {
            Node* temp = this->fragmentPointers[int(index / fragmentMaxSize)];
            for (int i = 0; i < index % fragmentMaxSize - 1; i++) {
                temp = temp->next;
            }
            Node* tmp = new Node(element, temp->next, temp);
            temp->next = tmp;
            temp->next->prev = tmp;
            create(index);
            this->count++;
        }
    }
    virtual T removeAt(int index)
    {
        if (index < 0 || index >= count) throw std::out_of_range("Segmentation fault!");
        else if (index == 0) {
            Node* temp = this->fragmentPointers[0];
            T res = temp->data;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            else this->fragmentPointers[int(count / fragmentMaxSize) + 1] = NULL;
            this->fragmentPointers[0] = temp->next;
            if (count % fragmentMaxSize == 1) {
                fragmentPointers[int(count / fragmentMaxSize) + 1] = NULL;
            }
            if (count % fragmentMaxSize == 0 || count % fragmentMaxSize == 1) {
                for (int i = 1; i < int(count / fragmentMaxSize); i++) {
                    fragmentPointers[i] = fragmentPointers[i]->next;
                }
            }
            else {
                for (int i = 1; i < int(count / fragmentMaxSize) + 1; i++) {
                    fragmentPointers[i] = fragmentPointers[i]->next;
                }
            }
            this->count--;
            return res;
        }
        else if (index == count - 1) {
            if (count % fragmentMaxSize == 0) {
                Node* temp = this->fragmentPointers[int(count / fragmentMaxSize)];
                T res = temp->data;
                if (temp->prev != NULL) {
                    temp->prev->next = temp->next;
                }
                else this->fragmentPointers[0] = NULL;
                this->fragmentPointers[int(count / fragmentMaxSize)] = temp->prev;
                this->count--;
                return res;
            }
            else {
                Node* temp = this->fragmentPointers[int(count / fragmentMaxSize) + 1];
                T res = temp->data;
                if (temp->prev != NULL) {
                    temp->prev->next = temp->next;
                }
                else this->fragmentPointers[0] = NULL;
                if (count % fragmentMaxSize == 1) {
                    this->fragmentPointers[int(count / fragmentMaxSize)] = this->fragmentPointers[int(count / fragmentMaxSize)]->prev;
                    this->fragmentPointers[int(count / fragmentMaxSize) + 1] = NULL;
                }
                else {
                    this->fragmentPointers[int(count / fragmentMaxSize) + 1] = temp->prev;
                }
                this->count--;
                return res;
            }
        }
        else {
            Node* temp = this->fragmentPointers[int(index / fragmentMaxSize)];
            for (int i = 0; i < index % fragmentMaxSize; i++) {
                if (temp->next != NULL) {
                    temp = temp->next;
                }
            }
            T res = temp->data;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            if (temp->prev != NULL) {
                temp->prev->next = temp->next;
            }
            if (index % fragmentMaxSize == 0) {
                this->fragmentPointers[int(index / fragmentMaxSize)] = temp->next;
            }
            if (count % fragmentMaxSize == 1) {
                this->fragmentPointers[int(count / fragmentMaxSize)] = this->fragmentPointers[int(count / fragmentMaxSize)]->prev;
                this->fragmentPointers[int(count / fragmentMaxSize) + 1] = NULL;
                for (int i = int(index / fragmentMaxSize) + 1; i < int(count / fragmentMaxSize) + 1; i++) {
                    fragmentPointers[i] = fragmentPointers[i]->next;
                }
            }
            else {
                if (count % fragmentMaxSize == 0) {
                    for (int i = int(index / fragmentMaxSize) + 1; i < int(count / fragmentMaxSize); i++) {
                        fragmentPointers[i] = fragmentPointers[i]->next;
                    }
                }
                else {
                    for (int i = int(index / fragmentMaxSize) + 1; i < int(count / fragmentMaxSize) + 1; i++) {
                        fragmentPointers[i] = fragmentPointers[i]->next;
                    }
                }
            }
            this->count--;
            return res;
        }
    }
    virtual bool removeItem(const T& item)
    {
        int index = indexOf(item);
        if (index == -1) return false;
        else {
            removeAt(index);
            return true;
        }
    }
    virtual bool empty()
    {
        if (this->count == 0) return true;
        else return false;
    }
    virtual int size()
    {
        return this->count;
    }
    virtual void clear()
    {
        Node* temp = *fragmentPointers;
        while (temp != NULL) {
            Node* res = temp->next;
            delete temp;
            temp = res;
        }
        count = 0;
    }
    virtual T get(int index)
    {
        if (index >= count || index < 0) throw std::out_of_range("Segmentation fault!");
        else {
            Node* temp = this->fragmentPointers[index / fragmentMaxSize];
            for (int i = 0; i < index % fragmentMaxSize; i++) {
                temp = temp->next;
            }
            return temp->data;
        }
    }
    virtual void set(int index, const T& element)
    {
        if (index >= count || index < 0) throw std::out_of_range("Segmentation fault!");
        else {
            Node* temp = this->fragmentPointers[index / fragmentMaxSize];
            for (int i = 0; i < index % fragmentMaxSize; i++) {
                temp = temp->next;
            }
            temp->data = element;
        }
    }
    virtual int indexOf(const T& item)
    {
        int res = 0;
        Node* temp = this->fragmentPointers[0];
        while (temp != NULL) {
            if (temp->data == item) break;
            res++;
            temp = temp->next;
        }
        if (res < count) return res;
        else return -1;
    }
    virtual bool contains(const T& item)
    {
        if (indexOf(item) == -1) return false;
        return true;
    }
    virtual string toString();
    Iterator begin(int index = 0)
    {
        Iterator result = Iterator(index, this, true);
        return result;
    }
    Iterator end(int index = -1)
    {
        if (index == -1) {
            Iterator result = Iterator(this, false);
            return result;
        }
        else {
            Iterator result = Iterator(index, this, false);
            return result;
        }
    }

public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *prev;
        friend class FragmentLinkedList<T>;

    public:
        Node()
        {
            next = 0;
            prev = 0;
        }
        Node(Node *next, Node *prev)
        {
            this->next = next;
            this->prev = prev;
        }
        Node(T data, Node *next, Node *prev)
        {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    class Iterator
    {
    private:
        FragmentLinkedList<T> *pList;
        Node *pNode;
        int index;

    public:
        Iterator(FragmentLinkedList<T> *pList = 0, bool begin = true)
        {
            this->pList = pList;
            if (begin) {
                if (pList != NULL) {
                    this->pNode = pList->fragmentPointers[0];
                    this->index = 0;
                }
                else {
                    this->pNode = NULL;
                    this->index = -1;
                }
            }
            else {
                this->pNode = NULL;
                if (pList != NULL) this->index = pList->size();
                else this->index = 0;
            }
        }
        Iterator(int fragmentIndex, FragmentLinkedList<T> *pList = 0, bool begin = true)
        {
            this->pList = pList;
            if (begin) {
                this->index = pList->fragmentMaxSize * fragmentIndex;
                this->pNode = pList->fragmentPointers[fragmentIndex];
            }
            else{
                this->index = pList->fragmentMaxSize * fragmentIndex;
                this->pNode = pList->fragmentPointers[fragmentIndex];
                for (int i = 0; (i < pList->fragmentMaxSize - 1) && (pNode->next != NULL); i++) {
                    pNode = pNode->next;
                    index++;
                }
                if (pNode->next != NULL) index++;
                pNode = pNode->next;
            }
        }
        Iterator &operator=(const Iterator &iterator)
        {
            this->pNode = iterator.pNode;
            this->index = iterator.index;
            this->pList = iterator.pList;
            return (*this);
        }
        T &operator*()
        {
            if (this->pNode == NULL) throw std::out_of_range("Segmentation fault!");
            return this->pNode->data;
        }
        bool operator!=(const Iterator &iterator)
        {
            if (pList == iterator.pList && index == iterator.index && pNode == iterator.pNode) return false;
            return true;
        }
        void remove()
        {
            if (this->pNode == NULL) throw std::out_of_range("Segmentation fault!");
            else if (this->index == 0) {
                this->pNode = NULL;
                this->pList->removeAt(0);
                this->index = -1;
            }
            else {
                this->pNode = this->pNode->prev;
                this->pList->removeAt(index);
                this->index--;
            }
        }
        void set(const T& element)
        {
            if (this->pNode == NULL) throw std::out_of_range("Segmentation fault!");
            this->pNode->data = element;
        }
        Iterator &operator++()
        {
            if (index > pList->count - 1) throw std::out_of_range("Segmentation fault!");
            else if (index == -1) {
                this->pNode = pList->fragmentPointers[0];
                this->index++;
            }
            else {
                if (this->pNode != NULL) {
                    this->pNode = this->pNode->next;
                }
                this->index++;
            }
            return (*this);
        }
        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }
    };
};

template <class T>
string FragmentLinkedList<T>::toString()
{
    stringstream ss;
    ss << "[";
    Node *ptr = this->fragmentPointers[0];

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
    // END: TODO

    return ss.str();
}

#endif
// END: STUDENT ANSWER

int main()
{
    // FragmentLinkedList<int> test;

    // int j = 0;
    // for (int i = 0; i < 20; i++) {
    //     test.add(i, i);
    // }
    // cout << test.toString() << endl;

    // int option;
    // int index, element;
    // int check = 1;
    // while (check) {
    //     cout << "1. to add tail        2. to add          3. to remove index        4. to remove item        5. clear data\n";
    //     cout << "6. to get index       7. to set index    8. to check index of element        9. to check contains\n";
    //     cin >> option;
    //     switch (option) {
    //     case 1:
    //         cout << "Input the element: ";
    //         cin >> element;
    //         test.add(element);
    //         break;
    //     case 2:
    //         cout << "Input the index and element: ";
    //         cin >> index >> element;
    //         test.add(index, element);
    //         break;
    //     case 3:
    //         cout << "Input the index: ";
    //         cin >> index;
    //         cout << test.removeAt(index) << endl;
    //         break;
    //     case 4:
    //         cout << "Input the element: ";
    //         cin >> element;
    //         cout << "Remove complete: " << test.removeItem(element) << endl;
    //         break;
    //     case 5:
    //         test.clear();
    //         break;
    //     case 6:
    //         cout << "Input the index: ";
    //         cin >> index;
    //         cout << "The element at index: " << test.get(index) << endl;
    //         break;
    //     case 7:
    //         cout << "Input the index and element: ";
    //         cin >> index >> element;
    //         test.set(index, element);
    //         break;
    //     case 8:
    //         cout << "Input the element: ";
    //         cin >> element;
    //         cout << "The index of element: " << test.indexOf(element) << endl;
    //         break;
    //     case 9:
    //         cout << "Input the element: ";
    //         cin >> element;
    //         cout << "The list has the element: " << test.contains(element) << endl;
    //         break;
    //     default:
    //         break;
    //     }
    //     cout << test.toString() << endl;
    //     cout << "Continues ?";
    //     cin >> check;
    // }




    // TESTCASE INPUT
    // === Example
    // FragmentLinkedList<int> fList;
    // for(int i = 0; i < 20 ; i++)
    //    fList.add(i, i * i);
    // //fList.add(999);
    // cout << fList.removeItem(121);
    // cout << fList.toString() << endl;
    //fList.set(3, 500);
    //cout << fList.removeAt(20) << endl;
    //cout << fList.toString() << endl;
    //for(FragmentLinkedList<int>::Iterator it = fList.begin(); it != fList.end(); it++)
    //   cout << *it << " ";
    // cout << endl;
    // === END: Example
    // END: TESTCASE INPUT
    FragmentLinkedList<int> test;
    for (int i = 0; i < 20; i++)
        test.add(i, i * i);
    cout << test.toString() << endl;
    for (FragmentLinkedList<int>::Iterator it = test.begin(); it != test.end(); it++)
        cout << *it << " ";
    FragmentLinkedList<int>::Iterator it = test.begin();
    while(it!=test.end()){
        it.remove();
        it++;
    }
    //test.clear();


    // FragmentLinkedList<int>::Iterator it = test.begin();

    // while(it!=test.end()){
        // it.remove();
        // it++;
    // }

    //test.add(7, 999);
    cout << "\n" << test.toString() << endl;
    return 0;
}