#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Interval {
public:
    int start;
    int end;
    
    Interval(int start = 0, int end = 0) {
        this->start = start;
        this->end = end;
    }
};


int minPark(vector<Interval> lInterval) {
    int *a = new int[lInterval.size()];
    for (int i = 0; i < lInterval.size(); i++) {
        a[i] = lInterval[i].end;
    }
    sort(a, a + lInterval.size());
    int result = 1;
    int check = lInterval[0].end;
    for (int i = 1; i < lInterval.size(); i++) {
        if (lInterval[i].start < check) { result++; }
        else { check = lInterval[i].end; }
    }
    return result;
}

int main()
{
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 5));
    intervals.push_back(Interval(2, 5));
    intervals.push_back(Interval(3, 5));

    cout << minPark(intervals);
    return 0;
}