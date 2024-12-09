#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    
    int left = 0, right = 0;
    int max_books = 0;
    int periods = 0;
    
    int min_height = heights[0];
    int max_height = heights[0];
    
    for(int i = 0; i < n; i++) {
        if(heights[i] < min_height) min_height = heights[i];
        if(heights[i] > max_height) max_height = heights[i];
        
        if(max_height - min_height > k) {
            max_books = max(max_books, i - 1 - left + 1);
            periods++;
            
            while(max_height - min_height > k) {
                left++;
                min_height = *min_element(heights.begin() + left, heights.begin() + i + 1);
                max_height = *max_element(heights.begin() + left, heights.begin() + i + 1);
            }
        }
    }
    
    max_books = max(max_books, n - left);
    periods = max(periods, 1);
    
    cout << max_books << " " << periods << endl;
    
    min_height = heights[0];
    max_height = heights[0];
    left = 0;
    
    for(int i = 0; i < n; i++) {
        if(heights[i] < min_height) min_height = heights[i];
        if(heights[i] > max_height) max_height = heights[i];
        
        if(max_height - min_height > k) {
            cout << left + 1 << " " << i << endl;
            left = i;
            min_height = heights[i];
            max_height = heights[i];
        }
    }
    
    if(left != n - 1) {
        cout << left + 1 << " " << n << endl;
    }
    
    return 0;
}