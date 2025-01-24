#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct Node  {
    int parent;
    int rank;
    Node(int p, int r) : parent(p), rank(r) {}
    Node() : parent(-1), rank(0) {}
};
void makeset (int x, vector<Node*> &nodes) {
    nodes[x] = new Node(x, 0);
}

void linkset (int x, int y, vector<Node*> &nodes) {
    if (nodes[x]->rank > nodes[y]->rank) {
        nodes[y]->parent = x;
    } else {
        nodes[x]->parent = y;
        if (nodes[x]->rank == nodes[y]->rank) {
            nodes[y]->rank++;
        }
    }
}
int findset (int x, vector<Node*> &nodes) {
    if (x != nodes[x]->parent) {
        nodes[x]->parent = findset(nodes[x]->parent, nodes);
    }
    return nodes[x]->parent;
}
void unionset (int x, int y, vector<Node*> &nodes) {
    linkset(findset(x, nodes), findset(y, nodes), nodes);
}

int main () {
    int n, m,cost;
    cin >> n >> m >>cost;
    vector<Node*> nodes(n);
    for (int i = 0; i < n; i++) {
        makeset(i, nodes);
    }
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    int total = 0;
    for(int i=0;i<m;i++){
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (w < cost && findset(u, nodes) != findset(v, nodes)) {
            unionset(u, v, nodes);
            total += w;
        }
    }
    int setcount=0;
    for(int i=0;i<n;i++){
        if(nodes[i]->parent==i){
            setcount++;
        }
    }
    cout << total+cost*(setcount-1) << " "<<setcount-1;

}
