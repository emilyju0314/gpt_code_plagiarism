#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n, a, b;
        cin >> n >> a >> b;
        
        string s;
        cin >> s;

        vector<int> heights; // Stores the height of the pipeline at each position
        int cost = 0;

        // Calculate the cost of pipeline at each position
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') {
                heights.push_back(1);
            } else {
                if(s[i-1] == '1') {
                    heights.push_back(2);
                } else {
                    heights.push_back(1);
                    cost += a; // Cost of lifting the pipeline to height 2
                }
            }
        }
        heights.push_back(1); // Last position is always at height 1

        // Calculate the total cost of pillars
        int num_pillars = 1; // Start and end pillars
        for(int i = 1; i < heights.size(); i++) {
            if(heights[i] != heights[i-1]) {
                cost += (heights[i] == 2 ? b : a);
                num_pillars++;
            }
        }
        cost += num_pillars * b; // Cost of the pillars

        cout << cost << endl;
    }

    return 0;
}