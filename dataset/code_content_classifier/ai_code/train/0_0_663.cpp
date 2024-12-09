#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> heights(N);
    for(int i = 0; i < N; i++) {
        cin >> heights[i];
    }

    int prevHeight = 0;
    long long totalHeight = 0;

    for(int i = 0; i < N; i++) {
        totalHeight += max(0, heights[i] - prevHeight);
        prevHeight = max(prevHeight, heights[i]);
    }

    cout << totalHeight << endl;

    return 0;
}