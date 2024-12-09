#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double findWidth(vector<int> stones, double room_width) {
    if (stones.empty()) {
        return 0.0;
    }
    
    double max_width = -1.0;
    for (int i = 0; i < stones.size(); i++) {
        vector<int> left, right;
        
        for (int j = 0; j < stones.size(); j++) {
            if (j < i) {
                left.push_back(stones[j]);
            } else if (j > i) {
                right.push_back(stones[j]);
            }
        }
        
        double left_total = 0, right_total = 0;
        for (int j = 0; j < left.size(); j++) {
            left_total += left[j];
        }
        for (int j = 0; j < right.size(); j++) {
            right_total += right[j];
        }
        
        if (left_total * (right.size()) == right_total * (left.size())) {
            double width = (left_total + right_total) / stones[i];
            if (width < room_width) {
                max_width = max(max_width, width);
            }
        }
    }
    
    return max_width;
}

int main() {
    int datasets;
    cin >> datasets;
    
    for (int i = 0; i < datasets; i++) {
        double room_width;
        int num_stones;
        cin >> room_width >> num_stones;
        
        vector<int> stones(num_stones);
        for (int j = 0; j < num_stones; j++) {
            cin >> stones[j];
        }
        
        double result = findWidth(stones, room_width);
        
        if (result == -1.0) {
            cout << "-1" << endl;
        } else {
            cout << fixed << setprecision(15) << result << endl;
        }
    }
    
    return 0;
}