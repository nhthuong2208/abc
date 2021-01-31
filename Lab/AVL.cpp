#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
#define SEPARATOR "#<ab@17943918#@>#"

enum BalanceValue
{
    LH = -1,
    EH = 0,
    RH = 1
};

void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}

template<class T>
class AVLTree
{
public:
    class Node;
private:
    Node *root;
protected:
    int getHeightRec(Node *node)
    {
        if (node == NULL) return 0;
        int leftHeight = getHeightRec(node->pLeft);
        int rightHeight = getHeightRec(node->pRight);

        return ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}

    void inOrder (Node* root) {
        if (root) {
            inOrder(root->pLeft);
            cout << root->data << " ";
            inOrder(root->pRight);
        }
    }

    void printInorder(){
        //TODO
        inOrder(root);
    }

    T Search (Node* root, const T &value) {
        if (root->data == value) return root->data;
        if (root->pLeft && root->pRight) {
            if (value < root->data) return Search(root->pLeft, value);
            else return Search(root->pRight, value);
        }
        throw "Not fount";
    }
    T search(const T &value){
        //TODO
        return Search(root, value);
    }
    int getHeight()
    {
        return this->getHeightRec(this->root);
    }

    void printTreeStructure()
    {
        int height = this->getHeight();
        if (this->root == NULL)
        {
            cout << "NULL\n";
            return;
        }
        queue<Node *> q;
        q.push(root);
        Node *temp;
        int count = 0;
        int maxNode = 1;
        int level = 0;
        int space = pow(2, height);
        printNSpace(space / 2);
        while (!q.empty())
        {
            temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << " ";
                q.push(NULL);
                q.push(NULL);
            }
            else
            {
                cout << temp->data;
                q.push(temp->pLeft);
                q.push(temp->pRight);
            }
            printNSpace(space);
            count++;
            if (count == maxNode)
            {
                cout << endl;
                count = 0;
                maxNode *= 2;
                level++;
                space /= 2;
                printNSpace(space / 2);
            }
            if (level == height)
                return;
        }
    }
    void rotR(Node* &pR){
        Node* p = pR;
        pR = pR->pLeft;
        p->pLeft = pR->pRight;
        pR->pRight = p;
    }
    void rotL(Node* &pR){
        Node* temp = pR;
        pR = pR->pRight;
        temp->pRight = pR->pLeft;
        pR->pLeft = temp;
    }
    void rotLR(Node* &pR){
        rotL(pR->pLeft);
        rotR(pR);
    }
    void rotRL(Node*&pR){
        rotR(pR->pRight);
        rotL(pR);
    }
    bool balanceLeft(Node* &pR){
        if (pR->balance == EH) {
            pR->balance = LH;
            return true; // cay cao len
        }
        else if (pR->balance == RH) {
            pR->balance = EH;
            return false;
        }
        else {
            if (pR->pLeft->balance == LH) { // L-L
                rotR(pR);
                pR->balance = pR->pRight->balance = EH;
                return false;
            }
            else if (pR->pLeft->balance == RH) {
                rotLR(pR);
                if (pR->balance == EH) {
                    pR->pLeft->balance = pR->pRight->balance = EH;
                }
                else if (pR->balance == LH) {
                    pR->balance = pR->pLeft->balance = EH;
                    pR->pRight->balance = RH;
                }
                else {
                    pR->balance = pR->pRight->balance = EH;
                    pR->pLeft->balance = LH;
                }
                return false;
            }
            else if (pR->pLeft->balance == EH) {
                rotR(pR);
                pR->balance = RH;
                pR->pRight->balance = LH;
                return true;
            }
        }
        return false;
    }
    bool balanceRight(Node* &pR){
        if(pR->balance == EH){
            pR->balance = RH;
            return true;
        }
        else if(pR->balance == LH){
            pR->balance = EH;
            return false;
        }
        else{
            if(pR->pRight->balance == RH){
                //R-R case
                rotL(pR);
                pR->balance = pR->pLeft->balance = EH;
                return false;
            }
            else if(pR->pRight->balance == EH){
                rotL(pR);
                pR->balance = LH;
                pR->pLeft->balance = RH;
                return true;
            }
            rotRL(pR);
            if(pR->balance == EH) {
                pR->pRight->balance = pR->pLeft->balance = EH;
            }
            else if(pR->balance == RH){
                pR->balance = pR->pRight->balance = EH;
                pR->pLeft->balance = LH;
            }
            else{
                pR->balance = pR->pLeft->balance = EH;
                pR->pRight->balance = RH;
            }
            return false;
        }
    }
    bool insert(const T&a,Node*&pR){
        if (pR == NULL) {
            pR = new Node(a);
            return true;
        }
        else {
            if (a < pR->data) {
                if (insert(a, pR->pLeft)) return balanceLeft(pR);
                else return false;
            } 
            else {
                if (insert(a, pR->pRight)) return balanceRight(pR);
                else return false;
            }
        }
    }
    bool remove(const T&a,Node*&pR){
        bool removeLeft = true;
        bool ret;       // ret = true if remove success
        if (pR != NULL) {
            if (pR->data == a) {
                if (pR->pLeft && pR->pRight) {
                    Node* p = pR->pLeft;
                    while (p->pRight) p = p->pRight;
                    pR->data = p->data;
                    removeLeft = true;
                    ret = remove(p->data, pR->pLeft);
                }
                else if (pR->pLeft) {
                    Node* p = pR;
                    pR = pR->pLeft;
                    delete p;
                    return true;
                }
                else if (pR->pRight) {
                    Node* p = pR;
                    pR = pR->pRight;
                    delete p;
                    return true;
                }
                else {
                    delete pR;
                    pR = nullptr;
                    return true;
                }
            }
            else if (a < pR->data) {
                removeLeft = true;
                ret = remove(a, pR->pLeft);
            }
            else {
                removeLeft = false;
                ret = remove(a, pR->pRight);
            }
            if (ret == true) {
                if (removeLeft == true) return !balanceRight(pR);
                else return !balanceLeft(pR);
            }
        }
        return false;
    }
    void insert(const T &value)
    {
        insert(value,this->root);
    }
    void remove(const T &value)
    {
        remove(value,this->root);
    }
    // void PrintInorder(Node*root){
    //     Node*p=root;
    //     if(p){
    //         PrintInorder(p->pLeft);
    //         cout<<p->data<<" ";
    //         PrintInorder(p->pRight);
    //     }
    // }
    // void printInorder(){
    //    PrintInorder(this->root);
    // }
    // bool search(const T &value){
    //     Node*p=root;
    //     while(p&&p->data!=value){
    //         if(p->data>value) p=p->pLeft;
    //         else p=p->pRight;
    //     }
    //     if(p==nullptr) return false;
    //     else return true;
    // }
    class Node
    {
    private:
        T data;
        Node *pLeft, *pRight;
        BalanceValue balance;
        friend class AVLTree<T>;

    public:
        Node(T value) : data(value), pLeft(NULL), pRight(NULL), balance(EH) {}
        ~Node() {}
    };
};
int main(){
    AVLTree<int> avl;
    int arr[] = {10,52,98,32,68,92,40,13,42,63,99,100,64,65};
    for (int i = 0; i < 14; i++){
        avl.insert(arr[i]);
    }

    cout << avl.search(10) << endl;
    avl.remove(92);
    avl.remove(32);
    avl.remove(40);
    avl.remove(13);
    avl.remove(52);
    avl.remove(40);
    avl.remove(98);
    avl.remove(100);
    avl.printTreeStructure();
}


