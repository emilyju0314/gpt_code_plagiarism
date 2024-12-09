#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int res = 0;
    heights.push_back(0);
    
    for (int i = 0; i < heights.size(); i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()];
            st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            res = max(res, h * w);
        }
        st.push(i);
    }
    
    return res;
}

int main() {
    int H, W;
    cin >> H >> W;
    
    vector<vector<int>> matrix(H, vector<int>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int res = 0;
    vector<int> height(W, 0);
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (matrix[i][j] == 1) {
                height[j] = 0;
            } else {
                height[j]++;
            }
        }
        res = max(res, largestRectangleArea(height));
    }
    
    cout << res << endl;
    
    return 0;
}