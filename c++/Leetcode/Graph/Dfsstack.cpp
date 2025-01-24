#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;

void dfsNonRecursive(const vector<vector<int>>& graph, int start) {
    stack<int> s;                 // Stack to hold the nodes
    unordered_set<int> visited;  // Set to track visited nodes

    // Push the starting node to the stack
    s.push(start);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        // If the node is not visited
        if (visited.find(current) == visited.end()) {
            cout << current << " ";  // Process the node
            visited.insert(current);

            // Add neighbors to the stack
            for (auto it = graph[current].rbegin(); it != graph[current].rend(); ++it) {
                if (visited.find(*it) == visited.end()) {
                    s.push(*it);
                }
            }
        }
    }
}

int main() {
    // Example graph represented as an adjacency list
    vector<vector<int>> graph = {
        {},          // 0 (not used, assuming nodes start from 1)
        {2, 3},      // 1 -> 2, 3
        {4, 5},      // 2 -> 4, 5
        {6},         // 3 -> 6
        {},          // 4
        {6},         // 5 -> 6
        {}           // 6
    };

    cout << "DFS starting from node 1: ";
    dfsNonRecursive(graph, 1);

    return 0;
}
