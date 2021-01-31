#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>

using namespace std;

int foldShift(long long key, int addressSize)
{
    string numStr = to_string(key);
    int lenStr = numStr.length();
    int res = 0;

    for (int i = 0; i < lenStr; i++) {
        int subStrSize;

        if ((i + addressSize) >= lenStr) { subStrSize = lenStr - i; } // neu con le ki tu
        else { subStrSize = addressSize; }

        string result = numStr.substr(i, subStrSize);
        res += atoi(result.c_str());

        i += (subStrSize - 1);
    }

    string resStr = to_string(res);
    int lenRes = resStr.length();
    if (lenRes > addressSize) {
        string str = resStr.substr(lenRes - addressSize, lenRes);
        res = atoi(str.c_str());
    }

    return res;
}

int rotation(long long key, int addressSize)
{
    string str = "";
    string numStr = to_string(key);
    int lenStr = numStr.length();
    str += numStr[lenStr - 1];
    string temp = numStr.substr(0, lenStr - 1);
    str += temp;
    int res = 0;

    for (int i = 0; i < lenStr; i++) {
        int subStrSize;

        if ((i + addressSize) >= lenStr) { subStrSize = lenStr - i; } // neu con le ki tu
        else { subStrSize = addressSize; }

        string result = str.substr(i, subStrSize);
        res += atoi(result.c_str());
        i += (subStrSize - 1);
    }

    string resStr = to_string(res);
    int lenRes = resStr.length();
    if (lenRes > addressSize) {
        string Str = resStr.substr(lenRes - addressSize, lenRes);
        res = atoi(Str.c_str());
    }

    return res;
}

long int midSquare(long int seed)
{
    long int num = seed * seed;
    num /= 100;
    return num % 1000;
}
long int moduloDivision(long int seed, long int mod)
{
    long int i;
    bool x = false;
    for (i = mod; i < mod + 20; i++) {
        for (int j = 2; j < i; j++) {
            if (i % j == 0) { x = false; break; }
            x = true;
        }
        if (x == true) break;
    }
    return (seed % i);
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{
    string str = to_string(seed);
    string res = "";
    for (int i = 0; i < size; i++) {
        res += str[extractDigits[i]];
    }
    int result = atoi(res.c_str());
    return result;
}

bool findPairs(int arr[], int n, pair<int,int>& pair1, pair<int, int>& pair2)
{
   // TODO: If there are two pairs satisfy the condition, assign their values to pair1, pair2 and return true. Otherwise, return false.
    sort(arr, arr + n);
    pair<int, int> temp[n * n];
    int a = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            temp[a].first = arr[i];
            temp[a].second = arr[j];
            a++; 
        }
    }
    for (int i = 0; i < a - 1; i++) {
        int sum = temp[i].first + temp[i].second;
        for (int j = i + 1; j < a; j++) {
            if ((temp[j].first + temp[j].second) == sum) {
                pair1 = temp[i];
                pair2 = temp[j];
                return true;
            }
        }
    }

    return false;
}
int main()
{
    cout << moduloDivision(121267, 300);
}