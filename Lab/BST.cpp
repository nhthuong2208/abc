#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template<class T>
class BinarySearchTree
{
public:
    class Node;

private:
    Node* root;

public:
    BinarySearchTree() : root(NULL) {}
    ~BinarySearchTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        T value;
        Node* pLeft, * pRight;
        friend class BinarySearchTree<T>;

    public:
        Node(T value) : value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };
    Node* addRec(Node* root, T value) {
        if (root == NULL) {
            Node* temp = new Node(value);
            return temp;
        }
        if (root->value >= value) root->pLeft = addRec(root->pLeft, value);
        else if (root->value < value) root->pRight = addRec(root->pRight, value);
        return root;
    }
    void add(T value) {
        root = addRec(root, value);
    }

    // STUDENT ANSWER BEGIN
    T minLeaf(Node* root) {
        if (!root->pLeft) return root->value;
        
        // find min in binary tree
        /*int res = root->value;
        int leftres = minLeaf(root->pLeft);
        int rightres = minLeaf(root->pRight);

        if (rightres < res) res = rightres;
        if (leftres < res) res = leftres;*/

        return minLeaf(root->pLeft);
    }
    T maxLeaf(Node* root) {
        if (!root->pRight) return root->value;
        
        /*int res = root->value;
        int leftres = maxLeaf(root->pLeft);
        int rightres = maxLeaf(root->pRight);

        if (leftres > res) res = leftres;
        if (rightres > res) res = rightres;*/

        return maxLeaf(root->pRight);
    }
    T getMin() {
    //TODO: return the minimum values of nodes in the tree.
        return minLeaf(root);
    }

    T getMax() {
        //TODO: return the maximum values of nodes in the tree.
        return maxLeaf(root);
    }
    
    
    void Delete(Node* &root, T value) {
        if (root) {
            if (root->value == value) {
                if (root->pLeft && root->pRight) {
                    Node* p = root->pRight;
                    while (p->pLeft) p = p->pLeft;
                    root->value = p->value;
                    Delete(root->pRight, p->value);
                }
                else if (root->pLeft) {
                    Node* p = root;
                    root = root->pLeft;
                    delete p;
                }
                else if (root->pRight) {
                    Node* p = root;
                    root = root->pRight;
                    delete p;
                }
                else {
                    delete root;
                    root = nullptr;
                }
            }
            else if (root->value > value) {
                Delete(root->pLeft, value);
            }
            else {
                Delete(root->pRight, value);
            }
        }
    }

    void deleteNode(T value){
        //TODO
        Delete(root, value);
    }
    string inOrderRec(Node* root) {
        stringstream ss;
        if (root != nullptr) {
            ss << inOrderRec(root->pLeft);
            ss << root->value << " ";
            ss << inOrderRec(root->pRight);
        }
        return ss.str();
    }
    
    string inOrder(){
        return inOrderRec(this->root);
    }
    bool findNode(Node* root, T i) {
        while (root) {
            if (root->value == i) return true;
            if (root->value >= i) root = root->pLeft;
            else root = root->pRight;
        }
        return false;
    }
    bool find(T i) {
    // TODO: return true if value i is in the tree; otherwise, return false.
        return findNode(root, i);
    }
    T Sum(Node* root, T l, T r) {
        int res = 0;
        if (!root) return 0;
        if (root->value >= l && root->value <= r) {
            res += root->value;
        }
        return res + Sum(root->pLeft, l, r) + Sum(root->pRight, l, r);
    }
    T sum(T l, T r) {
        // TODO: return the sum of all element in the tree has value in range [l,r].
        return Sum(root, l, r);
    }
    // STUDENT ANSWER END
};

int main()
{
    BinarySearchTree<int> bst;
bst.add(9);
bst.add(2);
bst.add(10);
bst.deleteNode(9);
cout << bst.inOrder();
    return 0;
}
