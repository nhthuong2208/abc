#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool isBipartite(vector<vector<int>> graph) {

}

vector<int> topologicalSorting(vector<vector<int>> graph) {
    
}
int main()
{
    int G[6][6] = { {0, 1, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0},
                {0, 1, 0, 1, 0, 0},
                {0, 0, 1, 0, 1, 0},
                {0, 0, 0, 1, 0, 1},
                {1, 0, 0, 0, 1, 0} };
    int n = 6;

    vector<vector<int>> graph(n, vector<int>());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (G[i][j]) graph[i].push_back(j);
		}
	}

    isBipartite(graph) ? cout << "Yes" : cout << "No";

    /////////////////////////////////////////////////

    int n = 6;
    int G[6][6] = { {0, 1, 0, 1, 0, 0},
                    {0, 0, 1, 1, 0, 0},
                    {0, 0, 0, 1, 1, 1},
                    {0, 0, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 0, 0} };
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (G[i][j] == 1) graph[i].push_back(j);
        }
    }

    vector<int> res = topologicalSorting(graph);
    if (res.empty()) printf("-1");
    else {
        for (int e : res) printf("%d ", e);
    }

    /////////////////////////////////////////////////

    int n = 6;
    int G[6][6] = { {0, 1, 0, 1, 0, 0},
                    {0, 0, 1, 1, 0, 0},
                    {0, 0, 0, 1, 1, 1},
                    {0, 0, 0, 0, 1, 1},
                    {0, 0, 0, 0, 0, 1},
                    {0, 1, 0, 0, 0, 0} };
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (G[i][j] == 1) graph[i].push_back(j);
        }
    }

    vector<int> res = topologicalSorting(graph);
    if (res.empty()) printf("-1");
    else {
        for (int e : res) printf("%d ", e);
    }
    return 0;
}

// dao an: Yes
// result: 0 1 2 3 4 5 //////////// -1