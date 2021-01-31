#include <iostream>
#include <stack>

using namespace std;

string removeDuplicates(string S){
    /*TODO*/
    stack<char> stack;
    char top;
    for (int i = (int)(S.length()) - 1; i >= 0; i--) {
        if (!stack.empty()) {
            top = stack.top();
            if (S[i] == top) stack.pop();
            else stack.push(S[i]);
        }
        else stack.push(S[i]);
    }
    string res = "";
    while (!stack.empty()) {
        res += stack.top();
        stack.pop();
    }
    // string result = "";
    // for (int i = (int)res.length() - 1; i >= 0; i--) {
    //     result += res[i];
    // }
    return res;
}

int main()
{
    cout << removeDuplicates("abbaca") << "\n";
    cout << removeDuplicates("aab");
    return 0;
}