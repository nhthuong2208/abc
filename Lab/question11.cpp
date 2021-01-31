#include <iostream>
#include <string.h>

using namespace std;
// question 11
/*void printArray(int n)
{
    if (n < 0) return;
    printArray(n - 1);
    if (n >= 0) {
        if (n == 0) cout << n;
        else cout << " " << n;
    }
}*/

// question 12
/*int strLen(char* str)
{
    if (*str == '\0') return 0;
    else return 1 + strLen(str + 1);
}*/

// question 13
/*int findGCD(int a, int b)
{
    if (b == 0) return a;
    return findGCD(b, a % b);
}


// question 14
int findLCM(int a, int b) 
{
    return (a * b) / findGCD(a, b);   
}*/

// question 15
/*bool match(char* text, char* pattern)
{
    if (*text == '\0' && *pattern != '\0') return false;

    if (*pattern == '\0') return true;

    if (*text == *pattern) return match(text + 1, pattern + 1);

    return false;
}
bool containsPattern(char* text, char* pattern)
{
    if (*text == '\0') return false;

    if (*text == *pattern) {
        if (match(text, pattern)) return true;
        else return containsPattern(text + 1, pattern);
    }

    return containsPattern(text + 1, pattern);
}*/

// question 16
/*void printPattern(int n)
{
    if (n > 0) cout << n << ", ";
    else cout << n;
    if (n <= 0) return;
    printPattern(n - 5);
    cout << ", " << n;
}*/

// question 17
/*int decimalToBinary(int decimal_number)
{
    if (decimal_number == 0) return 0;
    else return decimal_number % 2 + 10 * (decimalToBinary(decimal_number / 2));
}*/

// question 18
/*void printHailstone(int number)
{
    if (number != 1) cout << number << " ";
    else cout << number;
    if (number == 1) return;
    if (number % 2 == 0) printHailstone(number / 2);
    else printHailstone(number * 3 + 1);
}*/

// question 19
/*int myArrayToInt(char *str, int n)
{
    if (n == 1) return *str - '0';
    return (10*myArrayToInt(str, n - 1) + str[n-1] - '0');
}*/

// question 20
/*bool isPa(string str, int i, int j)
{

    if (i == j) return true;

    if ((str[i] != str[j]) && str[i] != ' ' && str[j] != ' ') return false;

    if (i < j + 1) {
        return isPa(str, i + 1, j - 1);
    }
    return true;
}
bool isPalindrome(string str) 
{ 

    int n = str.length();

    if (n == 0) return true;

    return isPa(str, 0, n - 1);
}*/

//question 21
/*int findMax(int* arr, int length)
{
    /*  
     * STUDENT ANSWER
    
    if (length == 1) return arr[0];
    int a = findMax(arr + 1, length - 1);
    return *arr > a ? *arr : a; 
}*/

// question 22
// 


class BST
{
    int data;
    BST *left, *right;
  
    public:
    BST();
    BST(int);
    BST* Insert(BST *, int);
      
    // Inorder traversal.
    void Inorder(BST *);
};

BST :: BST(){
    data = 0;
    left = right = NULL;
} 
  
BST :: BST(int value) { 
    this->data = value;
    left = right = NULL;
} 
 
BST* BST :: Insert(BST *root, int value) { 
   if (root == NULL) {
       BST* a = new BST(value);
       root = a;
   } 
   else {
       if (value < root->value) root->left = Insert(root->left, value);
       else root->right = Insert(root->right, value);
   }
   return root;
} 
  

void BST :: Inorder(BST *root) { 
    if (root == NULL) return;
    Inorder(root->left);
    cout << root->data << endl;
    Inorder(root->right);
}
int main() 
{
    
    return 0;
}