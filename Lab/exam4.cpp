#include <iostream>

#include <fstream>

#include <string>

#include <cmath>

#include <vector>

#include <algorithm>

#include <stack>

#include <queue>


#include <map>

using namespace std;

int flag(int n, int m,vector<int> A, vector<int> B){
    //TODO
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int curr = A[0];
    int res = n;
    for (int i = 1; i < n; i++) {
        if (A[i] == curr) res--;
        else curr = A[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (B[i] == A[j]) {
                res--;
                break;
            }
        }
    }
    return res;


}

int main()
{
    int n=45;
int m=1;
vector<int> A({32,134,131,44,194,254,63,209,140,181,29,108,94,153,165,117,159,2,33,31,133,229,255,47,144,74,120,15,88,0,111,30,137,143,156,75,44,110,233,226,40,118,28,165,8});
vector<int> B({151});
cout << flag(n, m,A,B);
    return 0;
}