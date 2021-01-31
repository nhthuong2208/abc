#include <iostream>
#include <sstream>
using namespace std;

// template <class T>
// class SLinkedList {
// public:
//     class Node; // Forward declaration
// protected:
//     Node* head;
//     Node* tail;
//     int count;
// public:
//     SLinkedList()
//     {
//         count = 0;
//         head = NULL;
//         tail = NULL;
//     }
//     ~SLinkedList()
//     {

//     }
//     void    add(const T& e);
//     void    add(int index, const T& e);
//     int     size();
//     string toString()
//     {
//         stringstream ss;
//         ss << "[";
//         Node* ptr = this->head;
//         while (ptr != NULL) {
//             ss << ", " << ptr->data;
//             ptr = ptr->next;
//         }
//         ss << "]";
//         return ss.str();
//     }
// public:
//     class Node {
//     private:
//         T data;
//         Node* next;
//         friend class SLinkedList<T>;
//     public:
//         Node() {
//             next = 0;
//         }
//         Node(Node* next) {
//             this->next = next;
//         }
//         Node(T data, Node* next) {
//             this->data = data;
//             this->next = next;
//         }
//     };
// };




// template<class T>
// int SLinkedList<T>::size() {
//     /* Return the length (size) of list */ 
//     return this->count;
// }

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
    class Iterator;
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList(): head(NULL), tail(NULL), count(0) {};
    ~SLinkedList() { };
    void    add(const T& e);
    void    add(int index, const T& e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T& e);
    int     indexOf(const T& item);
    bool    contains(const T& item);
    void    clear();
    T       removeAt(int index);
    bool    removeItem(const T& item);
    string toString()
     {
         stringstream ss;
         ss << "[";
         Node* ptr = this->head;
         while (ptr != NULL) {
             ss << ", " << ptr->data;
             ptr = ptr->next;
         }
         ss << "]";
         return ss.str();
     }
    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;
    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    class Iterator
    {
    private:
        SLinkedList<T> *pList;
        Node *current;
        int index; // corresponding with current node
    public:
        Iterator() {}
        Iterator(SLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        void remove();
        T &operator*();
        bool operator!=(const Iterator &iterator);
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};


template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    Node* temp = this->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    Node* temp = this->head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    temp->data = e;
}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    return this->count == 0 ? true : false;
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node* temp = this->head;
    int res = 0;
    while (temp != NULL) {
        if (temp->data == item) break;
        res++;
        temp = temp->next;
    }
    if (res < count) return res;
    else return -1;
}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    return indexOf(item) == -1 ? false : true;
}
template <class T>
T SLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
    if (index >= count) throw out_of_range("the index is out of range!");
    else if (index == 0) {
        Node* temp = this->head;
        Node* tmp = this->head;
        this->head = temp->next;
        delete(temp);
        this->count--;
        return tmp->data;
    }
    else if (index == count - 1) {
        Node* temp = this->head;
        Node* tmp = this->tail;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        this->tail = temp;
        temp->next = NULL;
        this->count--;
        return tmp->data;
    }
    else {
        Node* temp = this->head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* tmp = temp->next;
        temp->next = temp->next->next;
        this->count--;
        return tmp->data;
    }
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    if (contains(item)) {
        removeAt(indexOf(item));
        return true;
    }
    else return false;
}

template<class T>
void SLinkedList<T>::clear(){
    /* Remove all elements in list */
    this->count = 0;
    this->tail = NULL;
    Node* temp = this->head;
    while (temp != NULL) {
        Node* res = temp;
        temp = res->next;
        delete(res);
    }
    this->head = NULL;
}
template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    if (count == 0) {
        Node* temp = new Node(e, NULL);
        this->head = temp;
        this->tail = temp;
    }
    else {
        Node* temp = new Node(e, NULL);
        this->tail->next = temp;
        this->tail = temp;
    }
    this->count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */ 
    if (index > count) throw out_of_range("the index is out of range!");
    else if (index == count) {
        add(e);
    }
    else if (index == 0) {
        Node* temp = new Node(e, this->head);
        this->head = temp;
        this->count++;
    }
    else {
        Node* temp = this->head;
        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        Node* tmp = new Node(e, temp->next);
        temp->next = tmp;
        this->count++;
    }
}

template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
    this->pList = pList;
    if (begin) {
        if (pList != NULL) {
            this->current = pList->head;
        }
        else this->current = NULL;
    }
    else {
        this->current = NULL;
        if (this->pList != NULL) this->index = pList->size();
        else this->index = 0;
    }
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
    this->current = iterator.current;
    this->index = iterator.index;
    this->pList = iterator.pList;
    return *this;
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
    if (this->current == NULL) throw out_of_range("Segmentation fault!");
    else {
        Node* temp = this->current;
        Node* curr = this->pList->head;
        int a = 0;
        if (temp == curr) {
            this->current = NULL;
            this->pList->removeAt(0);
        }
        else {
            while (curr->next != NULL && temp != curr->next) {
                curr = curr->next;
                a++;
            }
            if (curr->next == temp) {
                this->current = curr;
                this->pList->removeAt(a + 1);
            }
        }    
    }
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (this->current == NULL) throw out_of_range("Segmentation fault!");
    else this->current->data = e;
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if (this->current == NULL) throw out_of_range("Segmentation fault!");
    else return this->current->data;
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns true if two iterators points the same node and index
    */
    return iterator.current != this->current;
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if (this->current == this->pList->tail) throw out_of_range("Segmentation fault!");
    else if (this->current == NULL) this->current = this->pList->head;
    else {
        this->current = this->current->next;
    }
    return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    Iterator iterator = *this;
    if (this->current == NULL) this->current = this->pList->head;
    else this->current = this->current->next;
    return iterator;
}
int main()
{
    SLinkedList<int> list;
    
int size = 10;
for(int idx=0; idx < size; idx++){
    list.add(idx);
}
        
SLinkedList<int>::Iterator it;
int expvalue = 0;
for(SLinkedList<int>::Iterator it = list.begin(); it != list.end(); it++){
    if(*it == expvalue);
    expvalue += 1;
    cout << *it << " ";
}
for(SLinkedList<int>::Iterator it = list.begin(); it != list.end(); it++){
    if(*it == expvalue);
    expvalue += 1;
    it.remove();
    cout << *it << " ";
    break;
}
    return 0;
}





template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
    this->pList = pList;
    if(begin == true) {
        if(pList){
            current = pList->head;
            index = 0;
        }
        else{
            current = 0;
            index = -1;
        }
    }
    else {
        current = 0;
        if(pList) index = pList->size();
        else index = 0;
    }
}
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
    this->pList = iterator.pList;
    this->index = iterator.index;
    this->current = iterator.current;
    return *this;
}
template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
    if(!current) {
        throw std::out_of_range("Segmentation fault!");
    }
    else{
        if(index == 0){
        current = 0;
        index = -1;
        this->pList->removeAt(0);
    }
    else{
        int a = index - 1;
        Node*p = this->pList->head;
        while(a--){
            p = p->next;
        }
        this->pList->removeAt(index);
        current = p;
        index--;
    }
    }
}
template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if(!current) {throw std::out_of_range("Segmentation fault!");}
    this->pList->set(index, e);
}
template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
    if(!current) {throw std::out_of_range("Segmentation fault!");}
    return current->data;
}
template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns true if two iterators points the same node and index
    */
    if (current == iterator.current && index == iterator.index && pList == iterator.pList)
    {return false;}
    return true;
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    if(index == -1){
        index++;
        current = pList->head;
    }
    else if(index <= pList->count - 1){
        index++;
        if(current) current = current->next;
    }
    else throw std::out_of_range("Segmentation fault!");
    return *this;
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
    Iterator* a = this;
    if(index == -1){
        index++;
        current = pList->head;
    }
    else if(index <= pList->count - 1){
        index++;
        if(current) current = current->next;
    }
    else throw std::out_of_range("Segmentation fault!");
    return *a;
}

//////////////////////////////////////////////
class Polynomial;
class Term {
private:
    double coeff;   
    int exp;
    friend class Polynomial;
public:
    Term(double coeff = 0.0, int exp = 0) {
        this->coeff = coeff;
        this->exp = exp;
    }
    bool operator==(const Term& rhs) const {
        return this->coeff == rhs.coeff && this->exp == rhs.exp;
    }
    friend ostream & operator<<(ostream &os, const Term& term) {
        cout << endl;
        cout << "Term: " << "(" << term.coeff << " " << term.exp << ")";
        return os;
    }
};
class Polynomial {
private:
    SLinkedList<Term>* terms;
public:
    Polynomial() {
        this->terms = new SLinkedList<Term>();
    }
    ~Polynomial() {
        this->terms->clear();
    }
    void insertTerm(const Term& term);
    void insertTerm(double coeff, int exp);
    void print() {
        SLinkedList<Term>::Iterator it;
        cout << "[";
        for (it = this->terms->begin(); it != this->terms->end(); it++) {
            cout << (*it);
        }
        cout << endl << "]";
    }
};
void Polynomial::insertTerm(const Term& term) {
    // STUDENT ANSWER
    if(term.coeff == 0.0) return;
    if(this->terms->empty()) {
      this->terms->add(term);
      return;
    }
    SLinkedList<Term>::Iterator p = this->terms->begin();
    int cnt = 0;
    while((*p).exp > term.exp) {
      if(cnt == this->terms->size() - 1) {
        cnt++;
        break;
      }
      p++;
      cnt++;
    }
    if((*p).exp == term.exp){
        (*p).coeff += term.coeff;
        if((*p).coeff == 0) p.remove();
    }
    else{
        this->terms->add(cnt, term);
    }
}
void Polynomial::insertTerm(double coeff, int exp) {
    // STUDENT ANSWER
    if(coeff == 0.0) return;
    Term t;
    t.coeff = coeff;
    t.exp = exp;
    if(this->terms->empty()) {
      this->terms->add(t);
      return;
    }
    SLinkedList<Term>::Iterator p = this->terms->begin();
    int cnt = 0;
    while((*p).exp > exp) {
      if(cnt == this->terms->size() - 1) {
        cnt++;
        break;
      }
      p++;
      cnt++;
    }
    if((*p).exp == exp){
        (*p).coeff += coeff;
        if((*p).coeff == 0) p.remove();
    }
    else{
        this->terms->add(cnt, t);
    }
}