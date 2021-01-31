#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void bfs(vector<vector<int>> graph, int start) {
	queue<int> result;
    int res;
    bool *a = new bool[graph.size()];
    for (int i = 0; i < graph.size(); i++) {
        a[i] = false;
    }
    a[start] = true;
    result.push(start);
    cout << start;
    while (result.empty() == false) {
        res = result.front();
        result.pop();
        int size = graph[res].size();
        for (int i = 0; i < size; i++) {
            if (a[graph[res][i]] == false) {
                a[graph[res][i]] = true;
                result.push(graph[res][i]);
                cout << " " << graph[res][i];
            }
        }
    }
}

int main()
{
    int init_graph[10][10] = {  {0, 1, 1, 0, 1, 0, 1, 0, 1, 0},
				    {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
				    {0, 1, 0, 0, 0, 1, 1, 0, 1, 1},
				    {1, 0, 0, 0, 0, 0, 0, 1, 0, 0},
				    {0, 1, 0, 0, 0, 0, 0, 1, 0, 0},
				    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0},
				    {0, 0, 1, 1, 0, 1, 0, 0, 0, 0},
				    {1, 0, 0, 0, 0, 1, 1, 0, 1, 0},
				    {0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
				    {1, 0, 1, 0, 1, 0, 0, 0, 1, 0} };
	int n = 10;
	vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (init_graph[i][j]) graph[i].push_back(j);
		}
	}

	bfs(graph, 0);
    return 0;
}