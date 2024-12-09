#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> groups(n - k + 1);
    for (int i = 0; i < n - k + 1; i++) {
        cin >> groups[i];
    }
    
    vector<string> names(n);

    for (int i = 0; i < n; i++) {
        names[i] = "A";
    }
    
    for (int i = 1; i < n - k + 1; i++) {
        if (groups[i] == "NO") {
            names[i + k - 1] = names[i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << names[i] << " ";
    }

    return 0;
}