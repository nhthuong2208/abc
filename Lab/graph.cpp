#include <iostream>
#include <list>
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

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};

class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v)
    {
        // v is a vertex we start BFS
        Adjacency *res = new Adjacency(V);
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
        list<int> queue;

        visited[v] = true;
        queue.push_back(v);
        
        while (!queue.empty()) {
            v = queue.front();
            res->push(v);
            queue.pop_front();
            int size = adj[v].getSize();
            for (int i = 0; i < size; i++) {
                if (!visited[adj[v].getElement(i)]) {
                    visited[adj[v].getElement(i)] = true;
                    queue.push_back(adj[v].getElement(i));  
                }
            }
        }
        return res;
	}
    
    void DFSUtil(int v, Adjacency* &res, bool visited[]) {
        
        visited[v] = true;
        res->push(v);
        int size = adj[v].getSize();
        for (int i = 0; i < size; i++) {
            if (visited[adj[v].getElement(i)] == false) DFSUtil(adj[v].getElement(i), res, visited);
        }
    }
    Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
        Adjacency *res = new Adjacency(V);
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        } 
        DFSUtil(v, res, visited);
        return res;
	}

    void topoUtil(int v, bool visited[], list<int> &stack) {
        visited[v] = true;

        int size = adj[v].getSize();
        for (int i = 0; i < size; i++) {
            if (visited[adj[v].getElement(i)] == false) topoUtil(adj[v].getElement(i), visited, stack);
        }

        stack.push_back(v);
    }

    void topologicalSort(){
        //TODO
        list<int> stack;
        bool *visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
        for (int i = 0; i < V; i++) {
            if (visited[i] == false) topoUtil(i, visited, stack);
        }

        while (!stack.empty()) {
            cout << stack.back() << " ";
            stack.pop_back();
        }
    }
};

class DirectedGraph 
{ 
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], bool *rs) {
        if (visited[v] == false) {
            visited[v] = true;
            rs[v] = true;

            list<int>::iterator i;
            for (i = adj[v].begin(); i != adj[v].end(); i++) {
                if (!visited[*i] && isCyclicUtil(*i, visited, rs)) return true;
                else if (rs[*i]) return true;
            }
        }
        rs[v] = false;
        return false;
    }
public: 
	DirectedGraph(){
        V = 0;
        adj = NULL;
    }
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = new list<int>[V];
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}

	bool isCyclic()
    {
        bool *visited = new bool[V];
        bool *stack = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
            stack[i] = false;
        }
        for (int i = 0; i < V; i++) {
            if (isCyclicUtil(i, visited, stack)) return true;
        }

        return false;
    }
}; 

// void minPath(list<int>& list, int** graph, int src, int dst) {

// }

// int Dijkstra(int** graph, int src, int dst) {
// 	// TODO: return the length of shortest path from src to dst.
//     if(src == dst) return 0;
//     int dist[6] = {-1, -1, -1, -1, -1, -1};
//     bool check[6] = {0, 0, 0, 0, 0, 0};
//     int min = graph[src][0];
//     int next = src;
//     dist[src] = 0;
//     check[next] = 1;
//     for(int i = 0; i < 6; i++){
//         int n = next;
//         for(int j = 0; j < 6; j++){
//             if(check[j] == 0){
//                 if(dist[j] == -1) min = dist[n] + graph[n][j];
//                 else min = dist[j];
//                 next = j;
//                 j = 6;
//             }
//         }
//         for(int j = 0; j < 6; j++){
//             if(check[j] == 0){
//                 if(dist[j] == -1 && graph[n][j] != 0) dist[j] = dist[n] + graph[n][j];
//                 else if(dist[j] > 0 && graph[n][j] != 0){
//                     if(dist[n] + graph[n][j] < dist[j]) dist[j] = dist[n] + graph[n][j];
//                 }
//                 if(dist[j] != -1 && dist[j] < min){
//                     min = dist[j];
//                     next = j;
//                 }
//             }
//         }   
//         check[next] = 1;
//     }
//     return dist[dst];
// }


// struct DisjointSets 
// { 
//     int *parent, *rnk; 
//     int n; 
  
//     DisjointSets(int n) 
//     {  
//         this->n = n; 
//         parent = new int[n+1]; 
//         rnk = new int[n+1]; 
  
//         for (int i = 0; i <= n; i++) 
//         { 
//             rnk[i] = 0; 
  
//             parent[i] = i; 
//         } 
//     } 
  
//     int find(int u) 
//     { 
//         if (u != parent[u]) 
//             parent[u] = find(parent[u]); 
//         return parent[u]; 
//     } 
  
//     void merge(int x, int y) 
//     { 
//         x = find(x), y = find(y); 
  
//         if (rnk[x] > rnk[y]) 
//             parent[y] = x; 
//         else
//             parent[x] = y; 
  
//         if (rnk[x] == rnk[y]) 
//             rnk[y]++; 
//     } 
// }; 

// struct Graph
// {
//     int V, E;
//     vector< pair<int, pair<int, int>> > edges;
//     // Constructor 
//     Graph(int V, int E)
//     {
//         this->V = V;
//         this->E = E;
//     }

//     void addEdge(int u, int v, int w)
//     {
//         edges.push_back({ w, {u, v} });
//     }
    
//     //YOUR CODE HERE
//     int kruskalMST() {
//     // TODO: return weight of the minimum spanning tree.
//     int mst_wt = 0; // Initialize result 
  
//     // Sort edges in increasing order on basis of cost 
//     sort(edges.begin(), edges.end()); 
  
//     // Create disjoint sets 
//     DisjointSets ds(V); 
  
//     // Iterate through all sorted edges 
//     vector< pair<int, pair<int, int>> >::iterator it; 
//     for (it=edges.begin(); it!=edges.end(); it++) 
//     { 
//         int u = it->second.first; 
//         int v = it->second.second; 
  
//         int set_u = ds.find(u); 
//         int set_v = ds.find(v); 
  
//         // Check if the selected edge is creating 
//         // a cycle or not (Cycle is created if u 
//         // and v belong to same set) 
//         if (set_u != set_v) 
//         { 
  
//             // Update MST weight 
//             mst_wt += it->first; 
  
//             // Merge two sets 
//             ds.merge(set_u, set_v); 
//         } 
//     } 
  
//     return mst_wt; 
// }
// };

int main()
{
    int V = 8, visited = 0;

Graph g(V);
Adjacency *arr;
int edge[][2] = {{0,1}, {0,2}, {0,3}, {0,4}, {1,2}, {2,5}, {2,6}, {4,6}, {6,7}};
for(int i = 0; i < 9; i++)
{
	g.addEdge(edge[i][0], edge[i][1]);
}

// g.printGraph();
// cout << endl;
arr = g.DFS(visited);
arr->printArray();
delete arr;
    return 0;
}