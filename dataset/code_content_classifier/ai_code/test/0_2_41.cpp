#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int colors = 1;
    vector<int> edge_colors;
    
    if (k > 2) {
        colors = 2;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edge_colors.push_back((i + j) % colors + 1);
        }
    }

    cout << colors << "\n";
    for (int i = 0; i < edge_colors.size(); i++) {
        cout << edge_colors[i] << " ";
    }

    return 0;
}