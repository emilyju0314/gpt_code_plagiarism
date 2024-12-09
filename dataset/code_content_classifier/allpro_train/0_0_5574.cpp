#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Node {
    int x, y;
};

double euclideanDist(Node a, Node b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    int n;
    cin >> n;
    
    vector<Node> nodes(n);
    
    for(int i = 0; i < n; i++) {
        cin >> nodes[i].x >> nodes[i].y;
    }
    
    double totalLength = 0;
    double minDist = 1e9;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i != j) {
                totalLength += euclideanDist(nodes[i], nodes[j]);
            }
        }
    }
    
    if(n > 2) {
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                double d = euclideanDist(nodes[i], nodes[j]);
                minDist = min(minDist, d);
            }
        }
        totalLength += (n - 2) * minDist;
    }
    
    if(n <= 2) {
        cout << fixed;
        cout.precision(10);
        cout << totalLength << endl;
    } else {
        if((n - 2) * minDist > euclideanDist(nodes[0], nodes[1]) + euclideanDist(nodes[0], nodes[2]) + euclideanDist(nodes[1], nodes[2])) {
            cout << "-1" << endl;
        } else {
            cout << fixed;
            cout.precision(10);
            cout << totalLength << endl;
        }
    }
    
    return 0;
}