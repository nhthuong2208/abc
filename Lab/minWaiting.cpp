#include <utility>
#include <algorithm>
#include <queue>
using namespace std;
pair<int, int> per[1000];
int minWaitingTime(int n, int arrvalTime[], int completeTime[]) {
    // YOUR CODE HERE
    for (int i = 0; i < n; i++)
    {
        per[i].first = arrvalTime[i];
        per[i].second = completeTime[i];
    }
    sort(per, per + n);
    priority_queue<pair<int, int>> pq;//should use heap
    long long res = 0, time = 0;
    for (int its = 0, i = 0; its < n; its++) {
        if (pq.empty()) {
            pq.push(make_pair(-per[i].second, per[i].first));
            time = max(time, (long long)per[i].first);
            i++;
        }
        for (; i < n && per[i].first <= time; i++)
            pq.push(make_pair(-per[i].second, per[i].first));
        time += -pq.top().first;
        res += time - pq.top().second;
        pq.pop();
    }
    return res;
}