#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> euler_tour(2*n-1);
    for(int i = 0; i < 2*n-1; i++) {
        cin >> euler_tour[i];
    }

    vector<int> degree(n+1);
    vector<int> tour;
    stack<int> path;
    for(int i = 0; i < 2*n-1; i++) {
        if(euler_tour[i] == 0) {
            if(path.empty()) {
                cout << "no" << endl;
                return 0;
            }

            tour.push_back(path.top());
            path.pop();
        } else {
            if(!path.empty()) {
                degree[euler_tour[i]]++;
                degree[path.top()]++;
                tour.push_back(path.top());
            }
            path.push(euler_tour[i]);
        }
    }

    cout << "yes" << endl;
    for(int i : tour) {
        cout << i << " ";
    }

    return 0;
}