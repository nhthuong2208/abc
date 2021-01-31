#include <iostream>
#include <sstream>
#include <string>

using namespace std;

template <class K, class D, int M> // K: key, D: data, M: degree of BTree
class BTree {
    /// Convention: Left sub-tree < Root's key <= Right sub-tree

public:
    class Entry;
    class Node;

private:
    Node *root;

public:
    BTree() : root(0) {};
    ~BTree() {}

    ///////////////////////////////////////////////////
    ///             CLASS `Entry`                   ///
    ///////////////////////////////////////////////////
public:
    class Entry {
    private:
        K key;
        D data;
        Node *rightPtr;

        friend class BTree<K, D, M>;

    public:
        Entry(K key = K{}, D value = D{}) : key(key), data(value), rightPtr(0) {}
        ~Entry() {}

        string toString() {
            stringstream ss;
            ss << "<"
               << this->key << ","
               << this->data
               << ">";
            return ss.str();
        }

    };

    ///////////////////////////////////////////////////
    ///             CLASS `Node`                    ///
    ///////////////////////////////////////////////////
public:
    class Node {
    private:
        Node *firstPtr;
        int numEntries;
        Entry entries[M - 1];

        friend class BTree<K, D, M>;

    public:
        Node() : firstPtr(0), numEntries(0) {};
        ~Node() { }

        bool isFull() {
            return (numEntries >= M - 1);
        }

        /// BEGIN STUDENT CODE
        string toString() {
            stringstream ss;
            // Fill your code here
            ss << "[";
            ss << "(" <<  numEntries << ")";
            for (int i = 0; i < numEntries; i++) {
                ss << entries[i].toString();
            }
            ss << "]";
            return ss.str();
        }
        /// END STUDENT CODE
    };

    /////////////////////////////////////////////////////////////
    ///         CLASS `BTree`: method run sample test         ///
    /////////////////////////////////////////////////////////////
    void testPrintNode(K* keys, D* data, int size) {
        Node node;

        for (int idx = 0; idx < size; idx++) {
            node.entries[idx].key = keys[idx];
            node.entries[idx].data = data[idx];
        }
        node.numEntries = size;
        cout << node.toString() << endl;
    }

        /////////////////////////////////////////////////////////////
    ///         CLASS `BTree`: method implementation          ///
    /////////////////////////////////////////////////////////////
public:
    /// BEGIN STUDENT CODE
    /// ==========================================================
    /// toStringPreOrder()
    string toStringPre(Node* root) {
        stringstream ss;
        int count = 0;
        Node* p = root->firstPtr;
        while (count <= root->numEntries) {
            if (p) {
                toStringPre(p);
            }
            count += 1;
            if (count <= root->numEntries) {
                ss << p->toString(root->entries[count].data);
                p = root->entries[count].rightPtr;
            }
        }
        return ss.str();
    }
    string toStringPreOrder() {
        return toStringPre(root);
    }
    
    /// END STUDENT CODE
};


int main()
{
    

}