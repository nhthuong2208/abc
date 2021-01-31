#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
using namespace std;

template <class K, class V>
class BKUTree {
public:
    class AVLTree;
    class SplayTree;

    class Entry {
    public:
        K key;
        V value;

        Entry(K key, V value) : key(key), value(value) {}
    };

public:
    AVLTree* avl;
    SplayTree* splay;
    queue<K> keys;
    int maxNumOfKeys;

public:
    BKUTree(int maxNumOfKeys = 5) {
        this->maxNumOfKeys = maxNumOfKeys;
        avl = new AVLTree();
        splay = new SplayTree();
    }
    ~BKUTree() { this-> clear(); }

    void checkNode(vector<K> &nodeAVL, vector<K> &nodeSPLAY) {
    if (avl == NULL) return;
    checkTrueNode(nodeAVL, nodeSPLAY, avl->root);
}
void checkTrueNode(vector<K> &nodeAVL, vector<K> &nodeSPLAY, typename AVLTree::Node *f) {
    if (!f)  return;
    typename SplayTree::Node *r = f->corr;
    if (r->entry->key != f->entry->key) {
        nodeAVL.push_back(f->entry->key);
        nodeSPLAY.push_back(r->entry->key);
    }
    checkTrueNode(nodeAVL, nodeSPLAY, f->left);
    checkTrueNode(nodeAVL, nodeSPLAY, f->right);
}

    void printQueue(){
        queue<K> s = keys;
        while(s.size() != 0){
            cout << s.front() << " ";
            s.pop();
        }
        cout << endl;
    }

    void add(K key, V value) {
        if ((int)(keys.size()) < maxNumOfKeys) {
            keys.push(key);
        }
        else {
            keys.pop();
            keys.push(key);
        }
        Entry* temp = new Entry(key, value);
        avl->add(temp);
        splay->add(temp);
        typename AVLTree::Node* newAVL = avl->find(key, avl->root);
        typename SplayTree::Node* newSplay = splay->find(key, splay->root);
        newAVL->corr = newSplay;
        newSplay->corr = newAVL;
    }
    
    void remove(K key) {
        bool x = false;
        queue<K> temp;
        // check key ? in queue
        while (!keys.empty()) {
            if (key == keys.front()) {
                keys.pop();
            }
            else {
                temp.push(keys.front());
                keys.pop();
            }
        }
        while(!temp.empty()) {
            keys.push(temp.front());
            temp.pop();
        }
        
        splay->remove(key);
        avl->remove(key);
        
        if ((int)(keys.size()) < maxNumOfKeys) keys.push(splay->root->entry->key);
        else {
            keys.pop();
            keys.push(splay->root->entry->key);
        }
    }

    V search(K key, vector<K>& traversedList) {
        if (key == splay->root->entry->key) {           // key can tim nam tai root cua splaytree
            return splay->root->entry->value;
        }    

        bool checkKey = false;
        queue<K> temp;
        while (!keys.empty()) {
            if (key == keys.front()) checkKey = true;

            temp.push(keys.front());
            keys.pop();
        }
        while (!temp.empty()) {
            keys.push(temp.front());
            temp.pop();
        }
        if (checkKey == true) {
            typename SplayTree::Node* rootSplay = splay->root;
            while (rootSplay) {
                if (rootSplay->entry->key == key) break;
                traversedList.push_back(rootSplay->entry->key);
                if (rootSplay->left && key < rootSplay->entry->key) rootSplay = rootSplay->left;
                else if (rootSplay->right && key > rootSplay->entry->key) {
                    rootSplay = rootSplay->right;
                }
                else break;
            }
            splay->splay(rootSplay, 1);
            if (rootSplay->parent == NULL) splay->root = rootSplay;
            if (rootSplay->entry->key == key) {
                if ((int)(keys.size()) < maxNumOfKeys) {
                    keys.push(rootSplay->entry->key);
                }
                else {
                    keys.pop();
                    keys.push(rootSplay->entry->key);
                }
                return rootSplay->entry->value;
            }
            else throw "Not found"; 
        }
        else {
            typename SplayTree::Node* currSplay = splay->root;
            typename AVLTree::Node* temp = currSplay->corr;
            typename AVLTree::Node* temp1 = temp;
            typename AVLTree::Node* findNode;
            bool found = false;
            while (temp) {
                if (temp->entry->key == key) {
                    findNode = temp;
                    found = true;
                    break;
                }
                traversedList.push_back(temp->entry->key);
                if (temp->left && key < temp->entry->key) temp = temp->left;
                else if (temp->right && key > temp->entry->key){
                    temp = temp->right;
                }
                else break;
            }
            if (!found) {
                typename AVLTree::Node* avlnode = avl->root;
                while (avlnode) {
                    if (avlnode->entry == temp1->entry) throw "Not found";

                    if (avlnode->entry->key == key) {
                        findNode = avlnode;
                        break;
                    }
                    traversedList.push_back(avlnode->entry->key);
                    if (avlnode->left && key < avlnode->entry->key) avlnode = avlnode->left;
                    else if (avlnode->right && key > avlnode->entry->key){
                        avlnode = avlnode->right;
                    }
                    else throw "Not found"; 
                }
            }

            typename SplayTree::Node* foundNode = findNode->corr;
            splay->splay(foundNode, 1);
            if (foundNode->parent == NULL) splay->root = foundNode;
            if ((int)(keys.size()) < maxNumOfKeys) {
                keys.push(foundNode->entry->key);
            }
            else {
                keys.pop();
                keys.push(foundNode->entry->key);
            }
            return findNode->entry->value;
        }
    }

    void traverseNLROnAVL(void (*func)(K key, V value)) {
        avl->traverseNLR(func);
    }

    void traverseNLROnSplay(void (*func)(K key, V value)) {
        splay->traverseNLR(func);
    }

    void clear() {
        avl->clear();
        splay->clear();
        while (!keys.empty()) {
            keys.pop();
        }
    }

    class SplayTree {
    public:
        class Node {
            Entry* entry;
            Node* left;
            Node* right;
            Node* parent;
            typename AVLTree::Node* corr;
            friend class SplayTree;
            friend class AVLTree;
            friend class BKUTree;

            Node(Entry* entry = NULL, Node* left = NULL, Node* right = NULL) {
                this->entry = entry;
                this->left = left;
                this->right = right;
                this->corr = NULL;
                this->parent = NULL;
            }
        };

    public:
        Node* root;

        SplayTree(): root(NULL) {};
        ~SplayTree() { this->clear(); };
        void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}
        int getHeightRec(Node *node)
    {
        if (node == NULL) return 0;
        int leftHeight = getHeightRec(node->left);
        int rightHeight = getHeightRec(node->right);

        return ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
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
                cout << temp->entry->key;
                q.push(temp->left);
                q.push(temp->right);
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
            Node* x = pR->left;
            Node* y = pR->parent;
            Node* z = x->right;
            if (y != NULL) {
                if (y->left != NULL && y->left == pR) y->left = x;
                else y->right = x;
            }
            if (z != NULL) {
                z->parent = pR;
            }
            pR->left = z;
            x->parent = y;
            x->right = pR;
            pR->parent = x;
        }

        void rotL(Node* &pR){
            Node* x = pR->right;
            Node* y = pR->parent;
            Node* z = x->left;
            if (y != NULL) {
                if (y->left != NULL && y->left == pR) y->left = x;
                else y->right = x;
            }
            if (z != NULL) z->parent = pR;
            pR->right = z;
            x->left = pR;
            x->parent = y;
            pR->parent = x;
        }

        void leftZigZac(Node* &pR) {
            Node* temp = pR->left;
            rotL(temp);
            rotR(pR);
        }

        void rightZigZac(Node* &pR) {
            Node* temp = pR->right;
            rotR(temp);
            rotL(pR);
        }

        void ZigZig(Node* &pR) {        // rightRollerCoaster
            Node* temp = pR->left;
            rotR(pR);
            rotR(temp);
        }

        void ZacZac(Node* &pR) {
            Node* temp = pR->right;
            rotL(pR);
            rotL(temp);
        }

        void splay(Node* &pR, int check) {
            if (pR->parent == NULL) return;
            Node* x = pR->parent;
            if (x->parent == NULL) {
                if (x->left != NULL && x->left == pR) rotR(x);
                else rotL(x);
            }
            else {
                Node* y = x->parent;
                if (y->left != NULL && y->left == x) {
                    if (x->left != NULL && x->left == pR) ZigZig(y);
                    else leftZigZac(y);
                }
                else {
                    if (x->right != NULL && x->right == pR) ZacZac(y);
                    else rightZigZac(y);
                }
            }
            if (check == 0) {
                splay(pR, check);
            }
            else return;
        }

        Node* insert(Entry* entry, Node* &pR) {
            if (pR && entry->key == pR->entry->key) throw "Duplicate key";

            if (pR == NULL) {
                pR = new Node(entry);
                return pR;
            }
            else {
                if (pR->entry->key > entry->key) {
                    if (pR->left == NULL) {
                        Node* temp = new Node(entry);
                        pR->left = temp;
                        temp->parent = pR;
                        return temp;
                    }
                    else return insert(entry, pR->left);
                }
                else {
                    if (pR->right == NULL) {
                        Node* temp = new Node(entry);
                        pR->right = temp;
                        temp->parent = pR;
                        return temp;
                    }
                    else return insert(entry, pR->right);
                }
            }
        }

        Node* find(K key, Node* &pR) {
            if (pR->entry->key == key) return pR;
            else if (key < pR->entry->key) {
                if (pR->left == NULL) return pR;
                else return find(key, pR->left);
            }
            else {
                if (pR->right == NULL) return pR;
                else return find(key, pR->right);
            }
        }

        bool find(K key) {
            Node* x = find(key, this->root);
            if (x->entry->key != key) return false;
            splay(x, 0);
            this->root = x;
            if (root->entry->key == key) return true;
            else return false;
        }

        void traverse(void (*func)(K key, V value), Node* pR) {
            if (pR == NULL) return;
            func(pR->entry->key, pR->entry->value);
            traverse(func, pR->left);
            traverse(func, pR->right);
        }

        void free(Node* &pR) {
            if (pR == NULL) return;
            free(pR->left);
            free(pR->right);
            delete(pR);
            pR = NULL;
        }

        void add(K key, V value) {
            add(new Entry(key, value));
        }

        void add(Entry* entry) {
            Node* x = insert(entry, this->root);
            splay(x, 0);
            this->root = x;
        }

        void remove(K key) {
            if (find(key) == false) throw "Not found";
            Node* x;
            if (root->left) x = root->left;
            else {
                if (root->right) {
                    x = root->right;
                    x->parent = NULL;
                    this->root = x;
                }
                else {
                    delete root;
                    this->root = NULL;
                }
                return;
            }
            x->parent = NULL;
            //** Neu cay con ben phai ko co thi dem cay ben trai len luon **//
            if (root->right == NULL) {
                this->root = x;
                return;
            }

            if (x->right != NULL) {
                Node* y = x->right;
                while (y->right != NULL) y = y->right;
                splay(y, 0);
                y->right = root->right;
                if (root->right != NULL) root->right->parent = y;
                this->root = y;
            }
            else {
                x->right = root->right;
                if (root->right != NULL) root->right->parent = x;
                this->root = x;
            }
        }

        V search(K key) {
            if (find(key) == true) return root->entry->value;
            else throw "Not found";
        }

        void traverseNLR(void (*func)(K key, V value)) {
            traverse(func, this->root);
        }

        void clear() {
            free(this->root);
        }
    };

    class AVLTree {
    public:
        class Node {
            Entry* entry;
            Node* left;
            Node* right;
            int balance;
            typename SplayTree::Node* corr;
            friend class AVLTree;
            friend class SplayTree;
            friend class BKUTree;

            Node(Entry* entry = NULL, Node* left = NULL, Node* right = NULL) {
                this->entry = entry;
                this->left = left;
                this->right = right;
                this->balance = 0;
                this->corr = NULL;
            }
        };

    public:
        Node* root;

        AVLTree(): root(NULL) {};
        ~AVLTree() { this->clear(); };
        void printNSpace(int n)
{
    for (int i = 0; i < n - 1; i++)
        cout << " ";
}

void printInteger(int &n)
{
    cout << n << " ";
}
        int getHeightRec(Node *node)
    {
        if (node == NULL) return 0;
        int leftHeight = getHeightRec(node->left);
        int rightHeight = getHeightRec(node->right);

        return ((leftHeight > rightHeight) ? leftHeight : rightHeight) + 1;
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
                cout << temp->entry->key;
                q.push(temp->left);
                q.push(temp->right);
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
        
        /**************************************/
       /**       ROTATE FUNCTION            **/
      /**************************************/

        void rotR(Node* &pR){
            Node* p = pR;
            pR = pR->left;
            p->left = pR->right;
            pR->right = p;
        }

        void rotL(Node* &pR){
            Node* temp = pR;
            pR = pR->right;
            temp->right = pR->left;
            pR->left = temp;
        }

        void rotLR(Node* &pR){
            rotL(pR->left);
            rotR(pR);
        }

        void rotRL(Node* &pR){
            rotR(pR->right);
            rotL(pR);
        }

        /**************************************/
       /**       BALANCE FUNCTION           **/
      /**************************************/

        bool balanceLeft(Node* &pR){
            if (pR->balance == 0) {
                pR->balance = -1;
                return true; // cay cao len
            }
            else if (pR->balance == 1) {
                pR->balance = 0;
                return false;
            }
            else {
                if (pR->left->balance == -1) { // L-L
                    rotR(pR);
                    pR->balance = pR->right->balance = 0;
                    return false;
                }
                else if (pR->left->balance == 1) {
                    rotLR(pR);
                    if (pR->balance == 0) {
                        pR->left->balance = pR->right->balance = 0;
                    }
                    else if (pR->balance == -1) {
                        pR->balance = pR->left->balance = 0;
                        pR->right->balance = 1;
                    }
                    else {
                        pR->balance = pR->right->balance = 0;
                        pR->left->balance = -1;
                    }
                    return false;
                }
                else if (pR->left->balance == 0) {
                    rotR(pR);
                    pR->balance = 1;
                    pR->right->balance = -1;
                    return true;
                }
            }
            return false;
        }

        bool balanceRight(Node* &pR){
            if(pR->balance == 0){
                pR->balance = 1;
                return true;
            }
            else if(pR->balance == -1){
                pR->balance = 0;
                return false;
            }
            else{
                if(pR->right->balance == 1){
                    //R-R case
                    rotL(pR);
                    pR->balance = pR->left->balance = 0;
                    return false;
                }
                else if(pR->right->balance == 0){
                    rotL(pR);
                    pR->balance = -1;
                    pR->left->balance = 1;
                    return true;
                }
                rotRL(pR);
                if(pR->balance == 0) {
                    pR->right->balance = pR->left->balance = 0;
                }
                else if(pR->balance == 1){
                    pR->balance = pR->right->balance = 0;
                    pR->left->balance = 1;
                }
                else{
                    pR->balance = pR->left->balance = 0;
                    pR->right->balance = 1;
                }
                return false;
            }
        }

        /**************************************/
       /**   ADD, REMOVE, SEARCH FUNCTION   **/
      /**************************************/

        bool insert(Entry* entry, Node*& pR){
            if (pR && entry->key == pR->entry->key) throw "Duplicate key";

            if (pR == NULL) {
                pR = new Node(entry);
                return true;
            }
            else {
                if (entry->key < pR->entry->key) {
                    if (insert(entry, pR->left)) return balanceLeft(pR);
                    else return false;
                } 
                else {
                    if (insert(entry, pR->right)) return balanceRight(pR);
                    else return false;
                }
            }
        }

        bool remove(K key, Node*& pR){
            bool removeLeft = true;
            bool ret;       // ret = true if remove success
            if (pR != NULL) {
                if (pR->entry->key == key) {
                    if (pR->left && pR->right) {
                        Node* p = pR->left;
                        while (p->right) p = p->right;
                        pR->entry = p->entry;
                        if (p->corr) p->corr->corr = pR;
                        pR->corr = p->corr;
                        removeLeft = true;
                        ret = remove(p->entry->key, pR->left);
                    }
                    else if (pR->left) {
                        Node* p = pR;
                        pR = pR->left;
                        delete p;
                        return true;
                    }
                    else if (pR->right) {
                        Node* p = pR;
                        pR = pR->right;
                        delete p;
                        return true;
                    }
                    else {
                        delete pR;
                        pR = nullptr;
                        return true;
                    }
                }
                else if (key < pR->entry->key) {
                    removeLeft = true;
                    ret = remove(key, pR->left);
                }
                else {
                    removeLeft = false;
                    ret = remove(key, pR->right);
                }
                if (ret == true) {
                    if (removeLeft == true) return !balanceRight(pR);
                    else return !balanceLeft(pR);
                }
            }
            return false;
        }

        V search(K key, Node* pR) {
            if (pR->entry->key == key) return pR->entry->value;

            if (key < pR->entry->key) {
                if (pR->left == NULL) throw "Not found";
                else return search(key, pR->left);
            }
            else {
                if (pR->right == NULL) throw "Not found";
                else return search(key, pR->right);
            }

            throw "Not found";
        }

        Node* find(K key, Node* pR) {
            if (pR->entry->key == key) return pR;

            if (key < pR->entry->key) {
                if (pR->left == NULL) throw "Not found";
                else return find(key, pR->left);
            }
            else {
                if (pR->right == NULL) throw "Not found";
                else return find(key, pR->right);
            }
        }

        void preOrder(void (*func)(K key, V value), Node* pR) {
            if (pR == NULL) return;
            func(pR->entry->key, pR->entry->value);
            preOrder(func, pR->left);
            preOrder(func, pR->right);
        }

        void free(Node* &pR) {
            if (pR == NULL) return;

            free(pR->left);
            free(pR->right);
            delete(pR);
            pR = NULL;
            
        }

        void add(K key, V value) {
            add(new Entry(key, value));
        }

        void add(Entry* entry) {
            insert(entry, this->root);
        }

        void remove(K key) {
            search(key);
            remove(key, this->root);
        }

        V search(K key) {
            return search(key, this->root);
        }

        void traverseNLR(void (*func)(K key, V value)) {
            preOrder(func, this->root);
        }

        void clear() {
            free(this->root);
        }
    };
};
void printKey(int key, int value) {
     cout << key << endl;
}


// template<class K>
// void printQueue(queue<K> keys){
//     cout<<"Queue now is: ";
//   while(!keys.empty()){
//       cout<<keys.front()<<" ";
//       keys.pop();
//   }
//   cout<<endl;
// }
// template<class K>
// void printTraversedList( vector<K> traversedList){
//     cout<<"Traverse is: ";
//     for(int i=0;i<traversedList.size();i++) cout<<traversedList[i]<<" ";
//     cout<<endl;
// }
// int main()
// {
//     BKUTree<int, int>* tree = new BKUTree<int, int>();
//         int keys[] = {7, 3, 8, 6, 2, 9, 11, 0};
//         for (int i = 0; i < 8; i++) tree->add(keys[i], keys[i]);
//         tree->traverseNLROnAVL(printKey);
//         cout << endl;
//         tree->traverseNLROnSplay(printKey);
//         cout << endl;
//         tree->printQueue();
//         cout << endl;
//         tree->remove(2); // xoa node 2
//         cout << endl;
//         tree->traverseNLROnAVL(printKey);
//         cout << endl;
//         tree->traverseNLROnSplay(printKey);
//         cout << endl;
//         tree->printQueue();
//         cout << endl;
//         vector<int> aaa;
//         tree->search(0, aaa); // search 8
//         tree->traverseNLROnAVL(printKey);
//         cout << endl;
//         tree->traverseNLROnSplay(printKey);
//         cout << endl;
//         tree->printQueue();
//         cout << endl;
//         for(int i = 0; i < aaa.size(); i++){
//             cout<<aaa[i]<<" ";
//         }
//     //tree->remove(3);
//     //tree->remove(5);
//     //tree->remove(5);
//     //tree->traverseNLROnAVL(printKey);
//     //tree->traverseNLROnSplay(printKey);
//     //tree->printqueue();
//     // BKUTree<int, int>::AVLTree* tree = new BKUTree<int, int>::AVLTree();
//     // int keys[] = {1, 3, 5, 7, 9, 2, 4};
//     // for (int i = 0; i < 7; i++) tree->add(keys[i], keys[i]);
//     // tree->remove(1);
//     // tree->remove(3);
//     // tree->remove(5);
//     // tree->remove(7);
//     // tree->remove(8);
//     // tree->remove(2);
//     // tree->remove(4);
//     // tree->traverseNLR(printKey);
//     return 0;
// }