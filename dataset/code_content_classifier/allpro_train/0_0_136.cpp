#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    long long count = 0;
    for(int i = 0; i < n; i++) {
        int max_height = heights[i];
        for(int j = i + 1; j < n; j++) {
            max_height = max(max_height, heights[j]);
            int bitwise_or = heights[i] | heights[j];

            bool valid = true;
            for(int k = i + 1; k < j; k++) {
                if((heights[k] | bitwise_or) <= max_height) {
                    valid = false;
                    break;
                }
            }

            if(valid) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}