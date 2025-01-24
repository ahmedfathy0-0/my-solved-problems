#include <iostream>
#include <vector>
#include <stack>

using namespace std;
struct Node {
    int start;
    int end;
    Node(int s, int e) : start(s), end(e) {}
    Node() : start(-1), end(-1) {}
};

void topologicalSort(vector<vector<int>> &adj, vector<Node*> &nodes, stack<int> &s, int u, int &time){
    nodes[u]->start = time++;
    for(int v : adj[u]){
        if(nodes[v]->start == -1){
            topologicalSort(adj, nodes, s, v, time);
        }
    }
    nodes[u]->end = time++;
    s.push(u);
}



int main (){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    vector<Node*> nodes(n);
    for(int i = 0; i < n; i++){
        nodes[i] = new Node();
    }
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        if(u!=-1){
            adj[u].push_back(v);
        }
        if(v!=-1){
            adj[v].push_back(u);
        }
    }
    stack<int> s;
    int time = 0;
    for(int i = 0; i < n; i++){
        if(nodes[i]->start == -1){
            topologicalSort(adj, nodes, s, i, time);
        }
    }

    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
}