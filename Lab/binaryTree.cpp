#include<iostream>
#include<string>
#include <sstream>
#include <queue>
using namespace std;

template<class K, class V>
class BinaryTree
{
public:
    class Node;

private:
    Node *root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree()
    {
        // You have to delete all Nodes in BinaryTree. However in this task, you can ignore it.
    }

    class Node
    {
    private:
        K key;
        V value;
        Node *pLeft, *pRight;
        friend class BinaryTree<K, V>;

    public:
        Node(K key, V value) : key(key), value(value), pLeft(NULL), pRight(NULL) {}
        ~Node() {}
    };

    void addNode(string posFromRoot, K key, V value)
    {
        if(posFromRoot == "")
        {
            this->root = new Node(key, value);
            return;
        }

        Node* walker = this->root;
        int l = posFromRoot.length();
        for (int i = 0; i < l-1; i++)
        {
            if (!walker)
                return;
            if (posFromRoot[i] == 'L')
                walker = walker->pLeft;
            if (posFromRoot[i] == 'R')
                walker = walker->pRight;
        }
        if(posFromRoot[l-1] == 'L')
            walker->pLeft = new Node(key, value);
        if(posFromRoot[l-1] == 'R')
            walker->pRight = new Node(key, value);
    }

    // STUDENT ANSWER BEGIN
    // You can define other functions here to help you.
    int count(Node* root) {
        if (root->pLeft != NULL && root->pRight != NULL) {
            return 1 + count(root->pLeft) + count(root->pRight);
        }
        else return 0;
    }
    int countTwoChildrenNode()
    {
        return count(root);
    }
    int sum(Node* root) {
        if (!root) return 0;
        if (root->pLeft == NULL && root->pRight == NULL) {
            return root->value;
        }
        return sum(root->pLeft) + sum(root->pRight);
    }
    int sumOfLeafs(int &a){
    //TODO
        return sum(root);
    }  
    int getheight(Node* root) {
        if (!root) return 0;
        else {
            int leftH = getheight(root->pLeft);
            int rightH = getheight(root->pRight);

            return (leftH > rightH) ? (1 + leftH) : (1 + rightH);
        }
    }
    int getHeight() {
    // TODO: return height of the binary tree.
        return getheight(root);
    }
    string Pre(Node* root) {
        if (!root) return "";
        
            int a = root->value;
            stringstream ss;
            ss << a;
            cout << ss.str() << " ";
            Pre(root->pLeft);
            Pre(root->pRight);
        return "";
    }
    string preOrder() {
        // TODO: return the sequence of values of nodes in pre-order.
        return Pre(root);
    }
    string In(Node* root) {
        if (!root) return "";
        
            
            In(root->pLeft);
            int a = root->value;
            stringstream ss;
            ss << a;
            cout << ss.str() << " ";
            In(root->pRight);
         return "";
    }
    string inOrder() {
        // TODO: return the sequence of values of nodes in in-order.
        return In(root);
    }
    string Post(Node* root) {
        if (!root) return "";
            
            Post(root->pLeft);
            
            Post(root->pRight);
            int a = root->value;
            stringstream ss;
            ss << a;
            cout << ss.str() << " ";
        
        return "";
    }
    string postOrder() {
        // TODO: return the sequence of values of nodes in post-order.
        return Post(root);
    }

    void bBFS(Node* root) {
        queue<Node*> Q;
        bool x = false;
        if (root) Q.push(root);
        while (!Q.empty()) {
            Node* p = Q.front();
            Q.pop();
            if (p->pLeft) Q.push(p->pLeft);
            if (p->pRight) Q.push(p->pRight);
            if (!x) {
                cout << p->value;
                x = true;
            }
            else cout << " " << p->value;
        }

    }
    void BFS() {
        bBFS(root);
    }
    bool checkBST(Node* root) {
        if (!root) return true;
        if (root->pLeft != NULL && root->pLeft->value >= root->value) return false;
        if (root->pRight != NULL && root->pRight->value < root->value) return false;
        if (!checkBST(root->pLeft) || !checkBST(root->pRight)) return false;
        return true;
    }
    bool isBST() {
    // TODO: return true if a tree is a BST; otherwise, return false.
        return checkBST(root);
    }
    // STUDENT ANSWER END
};

int main()
{

    BinaryTree<int, int> binaryTree;
binaryTree.addNode("",2, 4); // Add to root
binaryTree.addNode("L",3, 6); // Add to root's left node
binaryTree.addNode("R",5, 9); // Add to root's right node
binaryTree.BFS();
}