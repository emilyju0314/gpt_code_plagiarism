#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, u, v;
        cin >> n >> u >> v;

        int obstacles[n];
        for(int i=0; i<n; i++) {
            cin >> obstacles[i];
        }

        int cost = v;
        for(int i=1; i<n; i++) {
            if(obstacles[i] == obstacles[i-1]) {
                cost = min(cost, 2*v);
            }
            else if(abs(obstacles[i] - obstacles[i-1]) > 1) {
                cost = 0;
                break;
            }
            else {
                cost = min(cost, v);
            }
        }

        if(abs(obstacles[n-1] - obstacles[n-2]) > 1) {
            cost = min(cost, u+v);
        }

        cout << cost << endl;
    }

    return 0;
}