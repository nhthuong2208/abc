#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <math.h>

using namespace std;

string SpecialString(int n, int k) {
	// TODO: return a string satisfying conditions.
	string result = "";
	for (int i = 0; i < n; i++) {
		if ((i + 1) % 3 == 1) { result += 'a'; }
		else if ((i + 1) % 3 == 2) { result += 'b'; }
		else { result += 'c'; }
	}
	return result;
}

int countStop(int totalDistance, int maxDistanceFullTank, vector<int> stopPoint) {
	int curr_refill = 0;
	int result = 0;
	int limit = maxDistanceFullTank;
	int size = stopPoint.size();
	while (limit < totalDistance) {
		if (curr_refill >= size || stopPoint[curr_refill] > limit) return -1;

		while (curr_refill < size - 1 && stopPoint[curr_refill + 1] <= limit) curr_refill += 1;

		result += 1;
		limit = stopPoint[curr_refill] + maxDistanceFullTank;
		curr_refill += 1;
	}
	return result;
}

int sum(int x) {
	string a = to_string(x);
	int size = a.size();
	int res = 0;
	for (int i = 0; i < size; i++) {
		res += a[i] - '0';
	}
	return res;
}

int uniqueNumber(int x) {
	// TODO: return the smallest number satisfying conditions, otherwise return -1.
	if (x > 45) return -1;			// worst case is 123456789 which sum is 45

	if (0 <= x && x <= 9) return x;
	
	int a = 123456789;
	int res = 0;
	while (a > 0) {
		int last = a % 10;
		res = res*10 + last;
		int check = sum(res);
		if (check > x) {
			res = res / 10;
		}
		if (check == x) {
			string outString = to_string(res);
			outString = string(outString.rbegin(), outString.rend());
			res = stoi(outString);
			return res;
		}
		a /= 10;
	}
}


long long largestNumber(list<int> listNumber)
{
	
	if (listNumber.size() == 0) return 0;
	listNumber.sort();
	int a = *(listNumber.begin());
	listNumber.pop_front();
	return a + 10 * largestNumber(listNumber);
}

long long int sumOfOnes (long long int n, long long int l, long long int r){
    
}

int main()
{
	int arr[] = {9,6,3,4,3,6,4};
	list<int> listNumber;
	for(unsigned int i = 0; i < sizeof(arr)/sizeof(arr[0]);i++)
		listNumber.push_back(arr[i]);
	cout << largestNumber(listNumber);
}