#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, s;
    cin >> n >> s;

    if (s < 2 * n - 1 || s > n * (n + 1) / 2) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;
    
    vector<int> parent(n + 1);
    int remaining = s - n;
    
    for (int i = 2; i <= n; i++) {
        parent[i] = 1;
        remaining--;
    }
    
    for (int i = 2; i <= n && remaining > 0; i++) {
        int add = min(n - i, remaining);
        parent[i + add] = i;
        remaining -= add;
    }
    
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << " ";
    }
    
    return 0;
}