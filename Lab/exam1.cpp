#include <iostream>
#include <math.h>
#include <list>
#include <algorithm>

using namespace std;

class Node
{
    int data;
    Node* next;
public:
    Node(): data(0), next(nullptr){}

    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

    Node* getNext()
    {
        return this->next;
    }

    void setNext(Node* next)
    {
        this->next = next;
    }
    
};
void reduceDuplicate(Node* root)
    {
        Node* temp = root;
        int curr = temp->getData();
        Node* temp1 = temp;
        while(temp->getNext()) {
            temp = temp->getNext();
            if (temp->getData() == curr) {
                temp1->setNext(temp->getNext());
            }
            else {
                curr = temp->getData();
                temp1 = temp;
            }
        }
    }
int main()
{
    Node* node1 = new Node(1, nullptr);
    Node* node2 = new Node(1, node1);
    Node* node3 = new Node(0, node2);
    // Node* node4 = new Node(4, node3);
    // Node* node5 = new Node(3, node4);
    // Node* node6 = new Node(2, node5);
    // Node* node7 = new Node(2, node6);
    // Node* node8 = new Node(2, node7);
    // Node* node9 = new Node(1, node8);
    reduceDuplicate(node3);
    while (node3) {
        cout << node3->getData() << " ";
        node3 = node3->getNext();
    }
    return 0;
}