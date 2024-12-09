#include <iostream>
#include <vector>
#include <algorithm>

bool canMeet(std::vector<int>& x, std::vector<int>& v, double t) {
    double leftmost = x[0] - t * v[0];
    double rightmost = x[0] + t * v[0];
    for (int i = 1; i < x.size(); i++) {
        leftmost = std::max(leftmost, x[i] - t * v[i]);
        rightmost = std::min(rightmost, x[i] + t * v[i]);
    }
    return leftmost <= rightmost;
}

double minTimeToMeet(int n, std::vector<int>& x, std::vector<int>& v) {
    double left = 0, right = 1e9;
    for (int i = 0; i < 100; i++) {
        double mid = (left + right) / 2;
        if (canMeet(x, v, mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }
    return right;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> x(n);
    std::vector<int> v(n);
    
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    
    double minTime = minTimeToMeet(n, x, v);
    std::cout << minTime << std::endl;
    
    return 0;
}