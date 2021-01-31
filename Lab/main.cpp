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
        if (node == NULL)
            return 0;
        int lh = this->getHeightRec(node->pLeft);
        int rh = this->getHeightRec(node->pRight);
        return (lh > rh ? lh : rh) + 1;
    }
public:
    AVLTree() : root(nullptr) {}
    ~AVLTree(){}
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
    int difference(Node* t) {
      return getHeightRec(t->pLeft) - getHeightRec(t->pRight);
    }
    Node* rr_rotat(Node* parent) {
      Node* t;
      t = parent->pRight;
      parent->pRight = t->pLeft;
      t->pLeft = parent;
      return t;
    }
    Node* ll_rotat(Node* &parent) {
      Node* t;
      t = parent->pLeft;
      parent->pLeft = t->pRight;
      t->pRight = parent;
      return t;
    }
    Node* lr_rotat(Node* &parent) {
      Node* t;
      t = parent->pLeft;
      parent->pLeft = rr_rotat(t);
      return ll_rotat(parent);
    }
    Node* rl_rotat(Node* &parent) {
      Node* t;
      t = parent->pRight;
      parent->pRight = ll_rotat(t);
      return rr_rotat(parent);
    }
    Node* balance(Node* &t) {
      int b = difference(t);
      if (b > 1) {
        if (difference(t->pLeft) > 0)
         t = ll_rotat(t);
        else
         t = lr_rotat(t);
      } 
      else if (b < -1) {
        if (difference(t->pRight) > 0)
         t = rl_rotat(t);
        else
         t = rr_rotat(t);
      }
      return t;
    }
    Node* insert(Node* &r, const T &value) {
      if (r == NULL) {
        r = new Node(value);
        return r;
      }
      else if (value < r->data) {
        r->pLeft = insert(r->pLeft, value);
        r = balance(r);
      }
      else {
        r->pRight = insert(r->pRight, value);
        r = balance(r);
      } 
      return r;
    }
    void insert(const T &value)
    {
        //TODO
        insert(this->root, value);
    }
    Node* remove(Node* &r, const T &value) {
      if(!r) {
        return r;
      }
      if(value < r->data){
        r->pLeft = remove(r->pLeft, value);
      }
      else if(value > r->data){
        r->pRight = remove(r->pRight, value);
      }
      else{
        if(!r->pLeft || !r->pRight){
          if(!r->pLeft && !r->pRight){
            Node* t = r;
            delete t;
            r = NULL;
            return r;
          }
          if(!r->pLeft){
            Node* t = r;
            r = r->pRight;
            delete t;
            r = balance(r);
            return r;
          }
          if(!r->pRight){
            Node* t = r;
            r = r->pLeft;
            delete t;
            r = balance(r);
            return r;
          }
        }
        else{
          // Node* t = minRight(r->pRight);
          // r->data = t->data;
          // r->pRight = remove(r->pRight, value);
          Node* maxleft = r->pLeft;
          if(maxleft->pRight){
            maxleft = maxleft->pRight;
          }
          r->data = maxleft->data;
          r->pLeft = remove(r->pLeft, maxleft->data);
        }
      }
      if(!r) return r;
      r = balance(r);
      return r;

    }
    void remove(const T &value)
    {
        //TODO
        remove(this->root, value);
    }
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
int arr[] = {10,52,98,32,68,92,40,13,42,63, 99, 100, 64, 66};
for (int i = 0; i < 14; i++){
	avl.insert(arr[i]);
}
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


// int max(int a, int b)
//     {
//         return (a > b) ? a : b;
//     }
    
//     Node* rightRotate(Node* y)
//     {
//         Node* x = y->pLeft;
//         Node* T2 = x->pRight;
//         x->pRight = y;
//         y->pLeft = T2;
//         return x;
//     }
    
//     Node* leftRotate(Node* x)
//     {
//         Node* y = x->pRight;
//         Node* T2 = y->pLeft;
//         y->pLeft = x;
//         x->pRight = T2;
//         return y;
//     }
    
//     int getBalance(Node* N)
//     {
//         if (N == NULL)
//             return 0;
//         return getHeightRec(N->pLeft) - getHeightRec(N->pRight);
//     }
//     Node* maxValueNode(Node* node)
//     {
//         Node* current = node;

//         /* loop down to find the leftmost leaf */
//         while (current->pRight != NULL)
//             current = current->pRight;

//         return current;
//     }

//     Node* deleteNode(Node* root, int key)
//     {

//         // STEP 1: PERFORM STANDARD BST DELETE  
//         if (root == NULL)
//             return root;

//         // If the key to be deleted is smaller  
//         // than the root's key, then it lies 
//         // in left subtree  
//         if (key < root->data)
//             root->pLeft = deleteNode(root->pLeft, key);

//         // If the key to be deleted is greater  
//         // than the root's key, then it lies  
//         // in right subtree  
//         else if (key > root->data)
//             root->pRight = deleteNode(root->pRight, key);

//         // if key is same as root's key, then  
//         // This is the node to be deleted  
//         else
//         {
//             // node with only one child or no child  
//             if ((root->pLeft == NULL) || (root->pRight == NULL))
//             {
//                 Node* temp = root->pLeft ? root->pLeft : root->pRight;

//                 // No child case  
//                 if (temp == NULL)
//                 {
//                     temp = root;
//                     root = NULL;
//                 }
//                 else // One child case  
//                     *root = *temp; // Copy the contents of  
//                                    // the non-empty child  
//                 free(temp);
//             }
//             else
//             {
//                 // node with two children: Get the inorder  
//                 // successor (smallest in the right subtree)  
//                 Node* temp = maxValueNode(root->pLeft);

//                 // Copy the inorder successor's  
//                 // data to this node  
//                 root->data = temp->data;

//                 // Delete the inorder successor  
//                 root->pLeft = deleteNode(root->pLeft, temp->data);
//             }
//         }

//         // If the tree had only one node 
//         // then return  
//         if (root == NULL)
//             return root;

//         // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE  

//         // STEP 3: GET THE BALANCE FACTOR OF  
//         // THIS NODE (to check whether this  
//         // node became unbalanced)  
//         int balance = getBalance(root);

//         // If this node becomes unbalanced,  
//         // then there are 4 cases  

//         // Left Left Case  
//         if (balance > 1 && getBalance(root->pLeft) >= 0)
//             return rightRotate(root);

//         // Left Right Case  
//         if (balance > 1 && getBalance(root->pLeft) < 0)
//         {
//             root->pLeft = leftRotate(root->pLeft);
//             return rightRotate(root);
//         }

//         // Right Right Case  
//         if (balance < -1 && getBalance(root->pRight) <= 0)
//             return leftRotate(root);

//         // Right Left Case  
//         if (balance < -1 && getBalance(root->pRight) > 0)
//         {
//             root->pRight = rightRotate(root->pRight);
//             return leftRotate(root);
//         }

//         return root;
//     }

//     void remove(const T& value) 
//     {
//         //TODO
//         this->root = deleteNode(this->root, value);
//     }