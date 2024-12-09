#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int colors = (k+1)/2;
    cout << colors << endl;

    vector<int> edgeColors;
    int color = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            edgeColors.push_back(color);
            color = (color % colors) + 1;
        }
    }

    for (int i = 0; i < edgeColors.size(); i++) {
        cout << edgeColors[i] << " ";
    }
    
    return 0;
}