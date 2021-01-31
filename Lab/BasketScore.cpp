#include <iostream>
#include <stack>

using namespace std;

int baseballScore(string ops){
/*TODO*/
    stack<int> result;
    int x, a, b, c, d;
    int sum = 0;
    for (int i = 0; i < (int)(ops.length()); i++) {
        if (ops[i] >= '1' && ops[i] <= '9') {
            result.push(ops[i] - 48);
            continue;
        }
        switch (ops[i]) {
            case 'D':
                if (result.size() > 0) {
                    x = result.top();
                    result.pop();
                    d = x*2;
                    result.push(x);
                    result.push(d);
                }
                break;
            case 'C':
                if (result.size() > 0) result.pop();
                break;
            case '+':
                if (result.size() > 0) {
                    a = result.top();
                    result.pop();
                    if (result.size() > 0) {
                    b = result.top();
                    result.pop();
                    c = a + b;
                    result.push(b);
                    result.push(a);
                    result.push(c);
                    }
                }
                break;
        }
        
    }
    int size = result.size();
    for (int j = 0; j < size; j++) {
            sum += result.top();
            result.pop();
    }
    return sum;
}

int main()
{
    cout << baseballScore("524CD9++");
    return 0;
}