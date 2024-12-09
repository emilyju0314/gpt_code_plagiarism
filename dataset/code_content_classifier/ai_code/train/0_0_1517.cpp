#include <iostream>
#include <vector>
#define MOD 1000000007

using namespace std;

int n, x;
vector<int> d;

long long countNodes(int parent, int dist) {
    long long ans = 1;
    for(int i = 0; i < n; i++) {
        if(parent == -1 || i != parent) {
            if(dist + d[i] <= x) {
                ans = (ans + 1 + countNodes(i, dist + d[i])) % MOD;
            }
        }
    }
    return ans;
}

int main() {
    cin >> n >> x;
    d.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }

    long long result = countNodes(-1, 0) % MOD;
    cout << result << endl;

    return 0;
}