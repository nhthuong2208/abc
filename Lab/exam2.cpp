#include <iostream>
#include <math.h>
#include <list>
#include <algorithm>

using namespace std;

class Node
{
    int data;
    Node* left;
    Node* right;
public:
    Node(): data(0), left(nullptr), right(nullptr){}

    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    int getData()
    {
        return this->data;
    }

    void setData(int data)
    {
        this->data = data;
    }

    Node* getLeft()
    {
        return this->left;
    }

    void setLeft(Node* left)
    {
        this->left = left;
    }

     Node* getRight()
    {
        return this->right;
    }

    void setRight(Node* right)
    {
        this->right = right;
    }
};

int minleaf(Node* root) {
    int res = root->getData();
    int leftres = 10000, rightres = 10000;
    if (root->getLeft()) leftres = minleaf(root->getLeft());
    if (root->getRight()) rightres = minleaf(root->getRight());

    if (rightres < res) res = rightres;
    if (leftres < res) res = leftres;
    return res;
}

int maxleaf(Node* root) {
    int res = root->getData();
    int leftres = 0, rightres = 0;
    if (root->getLeft()) leftres = maxleaf(root->getLeft());
    if (root->getRight()) rightres = maxleaf(root->getRight());

    if (leftres > res) res = leftres;
    if (rightres > res) res = rightres;
    return res;
}
int findS(Node* root)
{
    Node* p = root;
    return maxleaf(p) - minleaf(root);
}

int main()
{
    Node* node1 = new Node(5, nullptr, nullptr);
Node* node2 = new Node(2, nullptr, nullptr);
Node* root = new Node(7, node1, node2);
cout << findS(root);
    return 0;
}