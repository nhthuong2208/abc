#include <iostream>
#include <math.h>
#include <list>
#include <algorithm>
#include <queue>

using namespace std;

class PrinterQueue
{
    // your attributes
private:
    int pri;
    string msg;
    PrinterQueue* next;
    PrinterQueue* head;
    int count;

public:
    // your methods
    PrinterQueue() {
        pri = 0;
        msg = "";
        next = nullptr;
        head = nullptr;
        count = 0;
    }
    PrinterQueue(int priotity, string fileName) {
        this->pri = priotity;
        this->msg = fileName;
        next = NULL;
    }
    ~PrinterQueue() {}
    void addNewRequest(int priority, string fileName)
    {
        // your code here
        PrinterQueue* temp = new PrinterQueue(priority, fileName);
        if (head == NULL) {
            head = temp;
        }
        else {
            head->next = temp;
        }
        count++;
    }

    void check() {
        int curr = count;
        while(--curr) {
            PrinterQueue* temp = head;
            for (int i = 0; i < curr; i++) {
                if (temp->next) {
                if (temp->pri < temp->next->pri) {
                    int tmp = temp->pri;
                    temp->pri = temp->next->pri;
                    temp->next->pri = tmp;
                }
                }
                temp = temp->next;
            }
        }
    }
    void print()
    {
        // your code here
        // After some logic code, you have to print fileName with endline 
        check();
        PrinterQueue* temp = head;
        while(temp) {
            cout << temp->msg << endl;
            
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "No file to print" << endl;
        }
    }

};

int main()
{
    PrinterQueue* myPrinterQueue = new PrinterQueue();
myPrinterQueue->addNewRequest(1, "hello.pdf");
myPrinterQueue->addNewRequest(2, "goodbye.pdf");
myPrinterQueue->addNewRequest(2, "goodnight.pdf");
myPrinterQueue->print();
myPrinterQueue->print();
myPrinterQueue->print();
    return 0;
}