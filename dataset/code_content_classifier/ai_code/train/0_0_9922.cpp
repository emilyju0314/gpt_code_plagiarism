#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 1;
    int kmax = 0;
    vector<int> positions;

    for (int i = 0; i < n; i++) {
        int cur_lcm = a[i];
        vector<int> cur_positions = {i};
        for (int j = i+1; j < n; j++) {
            int next_lcm = lcm(cur_lcm, a[j]);
            if (next_lcm <= m) {
                cur_lcm = next_lcm;
                cur_positions.push_back(j);
            } 
        }
        if (cur_positions.size() > positions.size()) {
            l = cur_lcm;
            kmax = cur_positions.size();
            positions = cur_positions;
        }
    }

    cout << l << " " << kmax << endl;
    for (int i = 0; i < kmax; i++) {
        cout << positions[i]+1 << " ";
    }

    return 0;
}