#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> heights(N - 1, 1);
    for (int i = 0; i < M; i++) {
        int a;
        cin >> a;
        heights[a - 1] = max(heights[a - 1], heights[a] + 1);
    }

    int max_height = 1;
    for (int h : heights) {
        max_height = max(max_height, h);
    }

    cout << max_height << endl;

    return 0;
}