#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    heights.push_back(0);
    int max_area = 0;
    
    for(int i = 0; i < heights.size(); i++) {
        while(!s.empty() && heights[i] < heights[s.top()]) {
            int h = heights[s.top()];
            s.pop();
            int left = s.empty() ? -1 : s.top();
            max_area = max(max_area, h * (i - left - 1));
        }
        s.push(i);
    }
    
    return max_area;
}

int main() {
    int N;
    cin >> N;
    
    vector<int> heights(N);
    for(int i = 0; i < N; i++) {
        cin >> heights[i];
    }
    
    cout << largestRectangleArea(heights) << endl;
    
    return 0;
}