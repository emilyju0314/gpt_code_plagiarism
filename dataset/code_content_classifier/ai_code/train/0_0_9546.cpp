#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = 1;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            result = (result * abs(a[i] - a[j])) % m;
        }
    }

    cout << result << endl;

    return 0;
}