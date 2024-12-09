#include <iostream>
#include <vector>
#include <stack>
#include <random>

using namespace std;

struct Edge {
    int to;
    int cost;
};

int main() {
    double p;
    int N;
    cin >> p;
    cin >> N;

    vector<vector<Edge>> tree(N+1);
    
    for (int i = 0; i < N-1; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        tree[x].push_back({y, c});
        tree[y].push_back({x, c});
    }

    double answer = 0.0;
    stack<int> s;
    s.push(1);

    random_device rd;  
    mt19937 gen(rd()); 
    uniform_real_distribution<> dis(0.0, 1.0);

    while (!s.empty()) {
        int x = s.top();
        s.pop();

        for (const Edge& e : tree[x]) {
            if (dis(gen) < p) {
                s.push(e.to);
                answer += e.cost;
            }
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << answer << endl;

    return 0;
}