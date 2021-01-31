#include <iostream>
#include <sstream>
using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList()
    {
      this->head = nullptr;
      this->tail = nullptr;
      this->count = 0;
    }
    ~SLinkedList(){};
    void add(T e)
    {
        Node *pNew = new Node(e);

        if (this->count == 0)
        {
            this->head = this->tail = pNew;
        }
        else
        {
            this->tail->next = pNew;
            this->tail = pNew;
        }

        this->count++;
    }
    int size()
    {
        return this->count;
    }
    void printList()
    {
        stringstream ss;
        ss << "[";
        Node *ptr = head;
        while (ptr != tail)
        {
            ss << ptr->data << ",";
            ptr = ptr->next;
        }

        if (count > 0)
            ss << ptr->data << "]";
        else
            ss << "]";
        cout << ss.str() << endl;
    }
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
    };
    void bubbleSort() {
        // int current = this->size() - 1;
        // bool flag = false;
        // while (current > 0 && flag == false) {
        //     int walker = 0;
        //     flag = true;
        //     Node* res = head;
        //     while (walker <= current) {
        //         Node* temp = this->head;
        //         if (walker >1) {
        //         for (int i = 0; i < walker - 1; i++) {
        //             temp = temp->next;
        //         }
        //         }
        //         if (temp->data > temp->next->data) {
        //             flag = false;
        //             int tmp = temp->data;
        //             temp->data = temp->next->data;
        //             temp->next->data = tmp;
        //         }
        //         walker++;
        //     }
        //     printList();
        //     current--;
        // }
        int current = size();
        while (--current) {
            Node* temp = head;
            for (int i = 0; i < current; i++) {
                if (temp->data > temp->next->data) {
                    int tmp = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = tmp;
                }
                temp = temp->next;
            }
            printList();
        }
        
    }
};
int main()
{
    int arr[] = {9, 2, 8, 4, 1};
SLinkedList<int> list;
for(int i = 0; i <int(sizeof(arr))/4;i++)
    list.add(arr[i]);
list.bubbleSort();
    return 0;
}