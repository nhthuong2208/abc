#include <iostream>
#include <stack>

using namespace std;

bool isValidParentheses (string s)
{
    stack<char> res;
    char x;
    for (int i = 0; i < (int)(s.length()); i++) {
        if (s[i] == '[' || s[i] == '{' || s[i] == '(') res.push(s[i]);
        // if (s[i] == ']' && res.top() == '[') res.pop();
        // if (s[i] == '}' && res.top() == '{') res.pop();
        // if (s[i] == ')' && res.top() == '(') res.pop();
        switch (s[i]) { 
        case ')': 
            x = res.top(); 
            res.pop(); 
            if (x == '{' || x == '[') 
                return false; 
            break; 
  
        case '}': 
            x = res.top(); 
            res.pop(); 
            if (x == '(' || x == '[') 
                return false; 
            break; 
  
        case ']': 
            x = res.top(); 
            res.pop(); 
            if (x == '(' || x == '{') 
                return false; 
            break; 
        } 
    } 
    return (res.empty());
}
int main()
{
    cout << isValidParentheses("");
    return 0;
}