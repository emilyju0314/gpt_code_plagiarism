#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findMaxLength(vector<int>& heights, int t_idx, int new_height){
    int max_len = 1;
    for(int i = t_idx-1; i >= 0; i--){
        if(heights[i] < new_height){
            max_len = max(max_len, 1 + findMaxLength(heights, i, heights[i]));
        }
    }
    return max_len;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> heights(n);
    for(int i = 0; i < n; i++){
        cin >> heights[i];
    }

    for(int i = 0; i < m; i++){
        int ai, bi;
        cin >> ai >> bi;
        heights[ai-1] = bi;

        int max_length = 0;
        for(int j = 0; j < n; j++){
            max_length = max(max_length, findMaxLength(heights, j, heights[j]));
        }
        cout << max_length << endl;
    }

    return 0;
}