#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> shapes(n);
    for (int i = 0; i < n; i++) {
        cin >> shapes[i];
    }

    vector<int> lastIndex(n+1, -1);
    vector<int> memory(n+1, 0);

    for (int i = 0; i < m; i++) {
        int type, l, r;
        cin >> type >> l >> r;
        
        if (type == 1) {
            shapes[l-1] = r;
            for (int j = 1; j <= n; j++) {
                if (lastIndex[j] != -1) {
                    memory[j] += r - lastIndex[j];
                }
                lastIndex[j] = shapes[j-1] == j ? j : lastIndex[j];
            }
        } else {
            int sum = 0;
            for (int j = 1; j <= n; j++) {
                if (lastIndex[j] != -1 && l <= lastIndex[j] && r >= lastIndex[j]) {
                    sum += r - lastIndex[j];
                }
            }
            cout << sum << endl;
        }
    }

    return 0;
}