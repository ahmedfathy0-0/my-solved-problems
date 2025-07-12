#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// Define M_PI if not available
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

struct Fighter {
    int x, y;        // Position
    int a, r;        // a: center of FOV (angle), r: range (half-width)
};

struct Node {
    Fighter A;
    vector<int> B;  
    int id;            
};

bool kahn(vector<Node>& nodes, vector<int>& order) {
    vector<int> in_degree(nodes.size(), 0);
    for (const auto& node : nodes) {
        for (const auto& neighbor_id : node.B) {
            in_degree[neighbor_id]++;
        }
    }

    vector<int> queue;
    for (size_t i = 0; i < nodes.size(); i++) {  // Changed int to size_t
        if (in_degree[i] == 0) {
            queue.push_back(i);
        }
    }

    while (!queue.empty()) {
        int current = queue.back();
        queue.pop_back();
        order.push_back(current);

        for (const auto& neighbor_id : nodes[current].B) {
            in_degree[neighbor_id]--;
            if (in_degree[neighbor_id] == 0) {
                queue.push_back(neighbor_id);
            }
        }
    }

    return order.size() == nodes.size();
}

const double EPS = 1e-9;

// Normalize angle to [0, 360)
double normalize_angle(double angle) {
    while (angle < 0) angle += 360;
    while (angle >= 360) angle -= 360;
    return angle;
}

// Check if angle x is in the interval [start, end], accounting for wrap-around
bool in_fov(double x, double start, double end) {
    if (start <= end)
        return start - EPS <= x && x <= end + EPS;
    else
        return x >= start - EPS || x <= end + EPS;
}

// Return true if A can see B
bool canSee(const Fighter& A, const Fighter& B) {
    // Compute angle from A to B
    double dx = B.x - A.x;
    double dy = B.y - A.y;

    double angle_to_B = atan2(dy, dx) * 180.0 / M_PI;  // in degrees
    angle_to_B = normalize_angle(angle_to_B);

    // FOV of A
    double fov_start = normalize_angle(A.a - A.r);
    double fov_end   = normalize_angle(A.a + A.r);

    return in_fov(angle_to_B, fov_start, fov_end);
}

int main(){
    int n;
    cin>>n;
    vector<Node> nodes(n);
    vector<int> order;
    for(int i = 0; i < n; i++) {
       Fighter A;
       cin >> A.x >> A.y >> A.a >> A.r;
       nodes[i].A = A;
       nodes[i].id = i;
    }
    for(int i = 0; i < n; i++) {
       for(int j = 0; j < n; j++) {
           if(i != j && canSee(nodes[i].A, nodes[j].A)) {
               nodes[i].B.push_back(j);
           }
       }
    }
    if(kahn(nodes, order)) {
        for(int i = 0; i < n; i++) {
            cout << nodes[order[i]].id + 1 << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
