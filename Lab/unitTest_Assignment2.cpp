// #include <iostream>
// #include <queue>
// #include <vector>
// #include<cmath>
// #include<fstream>
// #include"BKUTree.cpp"
// using namespace std;
// void printKey(int key, int value) {
//      cout << key <<"  ";
// } 
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
//  {   
//      cout<<"TEST 1:"<<endl;
//     BKUTree<int, int> *tree = new BKUTree<int, int>();
//     int arr[] = {10, 20, 30, 40, 50, 25, 15, 100};
//     for (int i = 0; i < 8; i++)
//     {
//         tree->add(arr[i], arr[i]);
//     }
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
   
//     cout << "Search 40 on BKUTree:" << endl;
//     vector<int> traversedList;
//     cout << "Found value: " << tree->search(40, traversedList) << endl;
//     printTraversedList(traversedList);
//     cout << "Splay tree structure after searching:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
//     //True
//     cout << "traverseNLR on AVL tree:" << endl;
//     tree->traverseNLROnAVL(printKey);
//     cout << "\n\n---------------------------------------\n\n";
//     cout << "traverseNLR on Splay tree:" << endl;
//     tree->traverseNLROnSplay(printKey);
//     cout << "\n\n---------------------------------------\n\n";

//     tree->remove(100);
//     cout << "After deleting key 100:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
    
//     tree->remove(40);
//     cout << "After deleting key 40:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
    
//      tree->remove(20);
//     cout << "After deleting key 20:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
    
//     tree->remove(30);
//     cout << "After deleting key 30:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";

//     tree->remove(25);
//     cout << "After deleting key 25:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";

//     tree->clear();
//     cout << "After clear():" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
//     //test2
//     cout<<"TEST 2:"<<endl;
//     tree = new BKUTree<int, int>();
//     int arr1[] = {1, 3, 5, 7, 9, 2, 4};
//     for (int i = 0; i < 7; i++)
//     {
//         tree->add(arr1[i], i);
//     }
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
   
//     cout << "Search 1 on BKUTree:" << endl;
//     traversedList.clear();
//     cout << "Found value: " << tree->search(1, traversedList) << endl;
//     printTraversedList(traversedList);
//     cout << "Splay tree structure after searching:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
   
//     cout << "traverseNLR on AVL tree:" << endl;
//     tree->traverseNLROnAVL(printKey);
//     cout << "\n\n---------------------------------------\n\n";
//     cout << "traverseNLR on Splay tree:" << endl;
//     tree->traverseNLROnSplay(printKey);
//     cout << "\n\n---------------------------------------\n\n";
//     //cout << tree->avl->search(0) << endl;

//     tree->remove(4);
//     cout << "After deleting key 4:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
     
//      tree->add(12,9);

//     tree->remove(3);
//     cout << "After deleting key 3:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
    
//     cout << "Search 5 on BKUTree:" << endl;
//     traversedList.clear();
//     cout << "Found value: " << tree->search(5, traversedList) << endl;
//     printTraversedList(traversedList);
//     cout << "Splay tree structure after searching:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";

//      tree->remove(1);
//     cout << "After deleting key 1:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
    
//     tree->remove(12);
//     cout << "After deleting key 12:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";

//     tree->remove(2);
//     cout << "After deleting key 2:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
//     //test3
//     cout<<"TEST 3:"<<endl;
//     tree = new BKUTree<int, int>(8);
//     int arr2[] = {65,76,33,24,90,14,18,75,70,93,44,100,41,62,59,74,6,10,56,1};
//     for (int i = 0; i < 20; i++)
//     {
//         tree->add(arr2[i], i);
//     }
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
   
//     cout << "Search 14 on BKUTree:" << endl;
//     traversedList.clear();
//     cout << "Found value: " << tree->search(14, traversedList) << endl;
//     printTraversedList(traversedList);
//     cout << "Splay tree structure after searching:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
   
//     cout << "traverseNLR on AVL tree:" << endl;
//     tree->traverseNLROnAVL(printKey);
//     cout << "\n\n---------------------------------------\n\n";
//     cout << "traverseNLR on Splay tree:" << endl;
//     tree->traverseNLROnSplay(printKey);
//     cout << "\n\n---------------------------------------\n\n";
//     //cout << tree->avl->search(0) << endl;

//     tree->remove(56);
//     cout << "After deleting key 56:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
     
//     tree->add(12,9);
//     tree->remove(12);

//     tree->remove(24);
//     cout << "After deleting key 24:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
    
//     cout << "Search 41 on BKUTree:" << endl;
//     traversedList.clear();
//     cout << "Found value: " << tree->search(41, traversedList) << endl;
//     printTraversedList(traversedList);
//     cout << "Splay tree structure after searching:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
     
//     cout << "traverseNLR on AVL tree:" << endl;
//     tree->traverseNLROnAVL(printKey);
//     cout << "\n\n---------------------------------------\n\n";
//     cout << "traverseNLR on Splay tree:" << endl;
//     tree->traverseNLROnSplay(printKey);
//     cout << "\n\n---------------------------------------\n\n";

//      tree->remove(65);
//     cout << "After deleting key 65:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
    
//     tree->remove(18);
//     tree->remove(93);
//     tree->remove(44);
//     cout << "After deleting key 18,93,44:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
   
//     tree->remove(6);
//     cout << "After deleting key 6:" << endl;
//     cout << "AVL tree structure:" << endl;
//     tree->avl->printTreeStructure();
//     cout << "Splay tree structure:" << endl;
//     tree->splay->printTreeStructure();
//     printQueue(tree->keys);
//     cout << "\n---------------------------------------\n\n";
//     //test 4
//      cout<<"TEST 4:"<<endl;
//      BKUTree<int,int>::AVLTree *p=new BKUTree<int,int>::AVLTree();
//      int arr4[]={10,39,64,22,63,77,5,54,12,60};
//      for(int i=0;i<10;i++){
//         p->add(arr4[i],i);
//      }
//     BKUTree<int,int>::Entry *k=new BKUTree<int,int>::Entry(27,13);
//     p->add(k);
//     //p.add(63);
//      p->remove(5);
//      p->remove(39);
//      p->remove(12);
//      p->remove(60);
//     // p.remove(70);
//     p->printTreeStructure();
//     cout<<"Value is: "<<p->search(22)<<endl;
//     p->traverseNLR(printKey);
//     cout<<endl;
//      p->clear();
//      p->add(45,12);
//      p->traverseNLR(printKey);
//     //test 5
//      cout<<"TEST 5:"<<endl;
//      BKUTree<int,int>::SplayTree *q=new BKUTree<int,int>::SplayTree();
//      int arr5[]={1, 3, 5, 7, 9,2,4};
//      for(int i=0;i<7;i++){
//         q->add(arr5[i],i);
//      }
//      BKUTree<int,int>::Entry *k1=new BKUTree<int,int>::Entry(27,7);
//      q->add(k1);
//     q->remove(2);
//     q->remove(4);
//     q->printTreeStructure();
//     cout<<"Value is: "<<q->search(7)<<endl;
//     q->printTreeStructure();
//     q->traverseNLR(printKey);
//     cout<<endl;
//     q->clear();
//     q->add(45,12);
//     q->traverseNLR(printKey);
// }

#include <iostream>
#include <queue>
#include <list>
#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>
#include <assert.h>

#include "BKUTree.cpp"

using namespace std;

stringstream strList;

// Them 2 method sau vao BKUTree de dung
/*

//==========     TESTER     ==========//
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

*/

template <class K, class V>
void printData(K key, V value) {
    cout << key << " ";
}

string transVector(vector<int> data) {
    stringstream ss;
    for (auto it = data.begin(); it != data.end(); it++) {
        ss << *it;
        ss << ',';
    }
    string re = ss.str();
    re[re.size() - 1] = '\0';
    return re;
}

#define NotAdd "Duplicate key"
#define NotFound "Not found"


int main() {
    // TEST BKU TREE
    BKUTree<int, int> myTree;
    // TEST ADD 1
    {
        int arr[30] = {79, 128, 64, 114, 137, 34, 47, 131, 88, 123, 89, 76, 114, 38, 12, 142, 123, 44, 114, 12, 110, 75, 27, 104, 13, 120, 113, 44, 64, 18};
        cout << "\n=====================TEST ADD 1====-================\n";
        vector<int> fail;
        for(int i = 0; i < 30; i++) {
            try { myTree.add(arr[i], arr[i] * 2);  }
            catch (const char *msg) {
                string data = "Duplicate key";
                bool yes = 1;
                int size = data.size();
                for (int i = 0; i < size; i++)  if (msg[i] != data[i]) { yes = 0;  break;  }
                if (yes == 1)    fail.push_back(arr[i]);
            } 
        }
        stringstream list;
        if (fail.size() != 0) {
            cout << "List fail add :";
            list << "List fail add :";
            for (int i = 0; i < fail.size(); i++)  { cout << " " << fail[i];  list << " ";  list << fail[i]; }
            cout << endl;
        }
        cout << "List key error: 114 123 114 12 44 64\n";
        string finalCheck = list.str();
        string check = "List fail add : 114 123 114 12 44 64";
        for (int i = 0; i < check.size(); i++)    if (finalCheck[i] != check[i])    throw std::out_of_range("FAIL ADD DATA _ SAME KEY INT TREE");
        vector<int> AVL;
        vector<int> SPLAY;
        myTree.checkNode(AVL, SPLAY);
        if (AVL.size() != 0) { for (int i = 0; i < AVL.size(); i++)  cout << AVL[i] << " -- " << SPLAY[i] << endl;  throw std::out_of_range("FAIL ADD 1 _ CORR MISS NODE"); }
        else    cout << "GOOD CORR\n"; // GOOD CORR
    }
    // TEST DELETE 1
    {
        cout << "\n===================TEST DELETE 1===================\n";
        vector<int> fail;
        int arr[15] = {3, 44, 38, 132, 79, 114, 150, 34, 113, 89, 149, 110, 27, 137, 137};
        for (int i = 0; i < 15; i++) {
            try { myTree.remove(arr[i]);  }
            catch (const char *msg) {
                string data = "Not found";
                bool yes = 1;
                int size = data.size();
                for (int i = 0; i < size; i++)  if (msg[i] != data[i]) { yes = 0;  break;  }
                if (yes == 1)    fail.push_back(arr[i]);
            } 
        }
        stringstream list;
        if (fail.size() != 0) {
            cout << "List not found :";
            list << "List not found :";
            for (int i = 0; i < fail.size(); i++)  { cout << " " << fail[i];  list << " ";  list << fail[i]; }
            cout << endl;
        }
        cout << "List not found : 3 132 150 149 137\n";
        string finalCheck = list.str();
        string check = "List not found : 3 132 150 149 137";
        for (int i = 0; i < check.size(); i++)    if (finalCheck[i] != check[i])    throw std::out_of_range("FAIL DELETE DATA _ SAME KEY INT TREE");
        vector<int> AVL;
        vector<int> SPLAY;
        myTree.checkNode(AVL, SPLAY);
        if (AVL.size() != 0) { for (int i = 0; i < AVL.size(); i++)  cout << AVL[i] << " -- " << SPLAY[i] << endl;  throw std::out_of_range("FAIL DELETE 1 _ CORR MISS NODE"); }
        else    cout << "GOOD CORR\n"; // GOOD CORR    
    }
    // TEST ADD 2
    {
        int arr[10] = {6, 42, 34, 99, 145, 19, 116, 7, 15, 24};
        cout << "\n=====================TEST ADD 2=====================\n";
        vector<int> fail;
        for(int i = 0; i < 10; i++) {
            try { myTree.add(arr[i], arr[i] * 2);  }
            catch (const char *msg) {
                string data = "Duplicate key";
                bool yes = 1;
                int size = data.size();
                for (int i = 0; i < size; i++)  if (msg[i] != data[i]) { yes = 0;  break;  }
                if (yes == 1)    fail.push_back(arr[i]);
            } 
        }
        if (fail.size() != 0) {
            cout << "List fail add :";
            for (int i = 0; i < fail.size(); i++)  cout << " " << fail[i]; 
            cout << endl;
        }
        cout << "All key is good\n";
        string check = "List fail add :";
        if (fail.size() != 0)   throw std::out_of_range("FAIL ADD DATA _ HAVE FAIL KEY");
        vector<int> AVL;
        vector<int> SPLAY;
        myTree.checkNode(AVL, SPLAY);
        if (AVL.size() != 0) { for (int i = 0; i < AVL.size(); i++)  cout << AVL[i] << " -- " << SPLAY[i] << endl;  throw std::out_of_range("FAIL ADD 1 _ CORR MISS NODE"); }
        else    cout << "GOOD CORR\n"; // GOOD CORR
    }
    myTree.clear();
    cout << "\n=======================================================\n";
    cout << "================  CLEAR TREE COMPLETE  ================";
    cout << "\n=======================================================\n";
    {
        int arr[30] = {79, 128, 64, 114, 137, 34, 47, 131, 88, 123, 89, 76, 114, 38, 12, 142, 123, 44, 114, 12, 110, 75, 27, 104, 13, 120, 113, 44, 64, 18};
        cout << "\n=====================TEST ADD 1=====================\n";
        vector<int> fail;
        for(int i = 0; i < 30; i++) {
            // myTree.traverseNLROnSplay(&printData);
            // cout<<endl;
            try { myTree.add(arr[i], arr[i] * 2);}
            catch (const char *msg) {
                string data = "Duplicate key";
                bool yes = 1;
                int size = data.size();
                for (int i = 0; i < size; i++)  if (msg[i] != data[i]) { yes = 0;  break;  }
                if (yes == 1)    fail.push_back(arr[i]);
            } 
        }
        cout << endl;
        stringstream list;
        if (fail.size() != 0) {
            cout << "List fail add :";
            list << "List fail add :";
            for (int i = 0; i < fail.size(); i++)  { cout << " " << fail[i];  list << " ";  list << fail[i]; }
            cout << endl;
        }
        cout << "List key error: 114 123 114 12 44 64\n";
        string finalCheck = list.str();
        string check = "List fail add : 114 123 114 12 44 64";
        for (int i = 0; i < check.size(); i++)    if (finalCheck[i] != check[i])    throw std::out_of_range("FAIL ADD DATA _ SAME KEY INT TREE");
        vector<int> AVL;
        vector<int> SPLAY;
        myTree.checkNode(AVL, SPLAY);
        if (AVL.size() != 0) { for (int i = 0; i < AVL.size(); i++)  cout << AVL[i] << " -- " << SPLAY[i] << endl;  throw std::out_of_range("FAIL ADD 1 _ CORR MISS NODE"); }
        else    cout << "GOOD CORR\n"; // GOOD CORR
    }
    // TEST DELETE 1
    {
        cout << "\n===================TEST DELETE 1===================\n";
        vector<int> fail;
        int arr[15] = {3, 44, 38, 132, 79, 114, 150, 34, 113, 89, 149, 110, 27, 137, 137};
        for (int i = 0; i < 15; i++) {
            // myTree.traverseNLROnSplay(&printData);
            // cout<<endl;
            try { myTree.remove(arr[i]);  }
            catch (const char *msg) {
                string data = "Not found";
                bool yes = 1;
                int size = data.size();
                for (int i = 0; i < size; i++)  if (msg[i] != data[i]) { yes = 0;  break;  }
                if (yes == 1)    fail.push_back(arr[i]);
            } 
        }
        stringstream list;
        if (fail.size() != 0) {
            cout << "List not found :";
            list << "List not found :";
            for (int i = 0; i < fail.size(); i++)  { cout << " " << fail[i];  list << " ";  list << fail[i]; }
            cout << endl;
        }
        cout << "List not found : 3 132 150 149 137\n";
        string finalCheck = list.str();
        string check = "List not found : 3 132 150 149 137";
        for (int i = 0; i < check.size(); i++)    if (finalCheck[i] != check[i])    throw std::out_of_range("FAIL DELETE DATA _ SAME KEY INT TREE");
        vector<int> AVL;
        vector<int> SPLAY;
        myTree.checkNode(AVL, SPLAY);
        if (AVL.size() != 0) { for (int i = 0; i < AVL.size(); i++)  cout << AVL[i] << " -- " << SPLAY[i] << endl;  throw std::out_of_range("FAIL DELETE 1 _ CORR MISS NODE"); }
        else    cout << "GOOD CORR\n"; // GOOD CORR    
    }
    // TEST ADD 2
    {
        int arr[10] = {6, 42, 34, 99, 145, 19, 116, 7, 15, 24};
        cout << "\n=====================TEST ADD 2=====================\n";
        vector<int> fail;
        for(int i = 0; i < 10; i++) {
            // myTree.traverseNLROnSplay(&printData);
            // cout<<endl;
            try { myTree.add(arr[i], arr[i] * 2);  }
            catch (const char *msg) {
                string data = "Duplicate key";
                bool yes = 1;
                int size = data.size();
                for (int i = 0; i < size; i++)  if (msg[i] != data[i]) { yes = 0;  break;  }
                if (yes == 1)    fail.push_back(arr[i]);
            } 
        }
        if (fail.size() != 0) {
            cout << "List fail add :";
            for (int i = 0; i < fail.size(); i++)  cout << " " << fail[i]; 
            cout << endl;
        }
        cout << "All key is good\n";
        string check = "List fail add :";
        if (fail.size() != 0)   throw std::out_of_range("FAIL ADD DATA _ HAVE FAIL KEY");
        vector<int> AVL;
        vector<int> SPLAY;
        myTree.checkNode(AVL, SPLAY);
        if (AVL.size() != 0) { for (int i = 0; i < AVL.size(); i++)  cout << AVL[i] << " -- " << SPLAY[i] << endl;  throw std::out_of_range("FAIL ADD 1 _ CORR MISS NODE"); }
        else    cout << "GOOD CORR\n"; // GOOD CORR
    }
    // CHECK INDEX DATA (TU CHECK TRUE FALSE)
    {
        cout << "\n==================CHECK INDEX DATA==================\n";
        cout << endl << "AVL Tree : ";
        myTree.traverseNLROnAVL(&printData);
        cout << "\nAVL Tree : 76 18 12 6 7 13 15 42 24 19 34 64 47 75 128 104 88 99 120 116 123 142 131 145" << endl;

        cout << "\nSplay Tree : ";
        myTree.traverseNLROnSplay(&printData);
        cout << "\nSplay Tree : 24 15 7 6 13 12 18 19 99 34 42 88 75 47 64 76 116 104 142 123 120 131 128 145" << endl;
    }
    // SEARCH DATA
    {
        cout << "\n====================SEARCH DATA====================\n";
        int arr[10] = {18, 150, 49, 78, 67, 110, 104, 40, 75, 82};
        vector<int> fail;
        vector<int> value;
        string checkValue[10];
        {
            checkValue[0] = "Find key : 18, value is : 36\nList key travel : 24 19 76";
            checkValue[1] = "Find key : 150, NOT FOUND\nList key travel : 18 42 64 75 76 128 142 145";
            checkValue[2] = "Find key : 49, NOT FOUND\nList key travel : 18 42 64 47 76 18";
            checkValue[3] = "Find key : 78, NOT FOUND\nList key travel : 18 42 64 75 76 128 104 88";
            checkValue[4] = "Find key : 67, NOT FOUND\nList key travel : 18 42 64 75 76 18";
            checkValue[5] = "Find key : 110, NOT FOUND\nList key travel : 18 42 64 75 76 128 104 120 116";
            checkValue[6] = "Find key : 104, value is : 208\nList key travel : 18 42 64 75 76 128";
            checkValue[7] = "Find key : 40, NOT FOUND\nList key travel : 18 42 24 34 76 18";
            checkValue[8] = "Find key : 75, value is : 150\nList key travel : 18 42 64";
            checkValue[9] = "Find key : 82, NOT FOUND\nList key travel : 18 42 64 75 76 128 104 88";
        }
        for (int i = 0; i < 10; i++) {
            
            value.push_back(-1);
            vector<int> data;
            cout << "\nFind key : " << arr[i];
            try { value[i] = myTree.search(arr[i], data);  }
            catch (const char *msg) {
                string data = "Not found";
                bool yes = 1;
                int size = data.size();
                for (int i = 0; i < size; i++)  if (msg[i] != data[i]) { yes = 0;  break;  }
                if (yes == 1)    fail.push_back(arr[i]);
            }
            if (value[i] != -1)    cout << ", value is : " << value[i] << endl;
            else    cout << ", NOT FOUND\n";
            cout << "List key travel :";
            for (auto it = data.begin(); it != data.end(); it++)  cout << " " << *it;
            cout << "\n\tDATA CHECK:\n";
            cout << checkValue[i];
            cout << endl;
        }
        cout << endl;
        stringstream list;
        if (fail.size() != 0) {
            cout << "List NOT FOUND :";
            list << "List NOT FOUND :";
            for (int i = 0; i < fail.size(); i++)  { cout << " " << fail[i];  list << " ";  list << fail[i]; }
            cout << endl;
        }
        cout << "List NOT FOUND : 150 49 78 67 110 40 82\n";
        string finalCheck = list.str();
        string check = "List NOT FOUND : 150 49 78 67 110 40 82";
        for (int i = 0; i < check.size(); i++)    if (finalCheck[i] != check[i])    throw std::out_of_range("FAIL SEARCH DATA _ SEARCH KEY NOT IN TREE");

        vector<int> AVL;
        vector<int> SPLAY;
        myTree.checkNode(AVL, SPLAY);
        if (AVL.size() != 0) { for (int i = 0; i < AVL.size(); i++)  cout << AVL[i] << " -- " << SPLAY[i] << endl;  throw std::out_of_range("FAIL ADD 1 _ CORR MISS NODE"); }
        else    cout << "GOOD CORR\n"; // GOOD CORR
    }
}