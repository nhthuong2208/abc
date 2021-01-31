#include <iostream>
#include <sstream>

using namespace std;

void bubbleSort(string &x) {
    int size = x.length();
    if (size == 0) return;
    while (--size) {
        for (int i = 0; i < size; i++) {
            if (x[i] - 'a' > x[i + 1] - 'a') {
                int temp = x[i];
                x[i] = x[i + 1];
                x[i + 1] = temp;
            }
        }
    }
}

bool isPermutation (string a, string b) {
    //TODO
    bubbleSort(a);
    bubbleSort(b);
    cout << a << endl;
    cout << b;
    if (a == b || (a.length() == 0 && b.length() == 0)) return true;
    else return false;
}

int main()
{
    string a = "";
    string b="";
    cout << isPermutation(a, b);
    
    return 0;
}