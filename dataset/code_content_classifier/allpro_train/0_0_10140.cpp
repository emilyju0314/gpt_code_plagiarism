#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Function to calculate the gcd of two numbers
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> multisets(n+1);
    unordered_map<int, int> count;

    for (int i = 0; i < q; i++) {
        int type, x, y, z;
        cin >> type >> x >> y;
        if (type == 1) {
            multisets[x] = {y};
        } else if (type == 2) {
            cin >> z;
            multisets[x].clear();
            for (int num : multisets[y]) {
                multisets[x].push_back(num);
                count[num]++;
            }
            for (int num : multisets[z]) {
                multisets[x].push_back(num);
                count[num]++;
            }
        } else if (type == 3) {
            cin >> z;
            count.clear();
            for (int num : multisets[y]) {
                for (int num2 : multisets[z]) {
                    int g = gcd(num, num2);
                    multisets[x].push_back(g);
                    count[g]++;
                }
            }
        } else {
            int v;
            cin >> v;
            int answer = count[v] % 2;
            cout << answer;
        }
    }

    return 0;
}