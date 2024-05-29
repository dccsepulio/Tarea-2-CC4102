#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <unordered_map>

using namespace std;

typedef pair<int, int> iPair;

class Graph {
    int V; 
    vector<vector<iPair>> adj;
    
public:
    Graph(int V);
    void addEdge(int u, int v, double w);
    void dijkstraHeap(int src, vector<double> &dist, vector<int> &prev);
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v, double w) {
    adj[u].emplace_back(v, w);
    adj[v].emplace_back(u, w);
}

void Graph::dijkstraHeap(int src, vector<double> &dist, vector<int> &prev) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    dist.assign(V, numeric_limits<double>::infinity());
    prev.assign(V, -1);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto &[v, weight] : adj[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
                prev[v] = u;
            }
        }
    }
}
