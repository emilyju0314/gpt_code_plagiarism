#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Robot {
    int x, l;
};

bool cmp(const Robot &a, const Robot &b) {
    return a.x < b.x;
}

int main() {
    int n;
    cin >> n;
    
    vector<Robot> robots(n);
    for (int i = 0; i < n; i++) {
        cin >> robots[i].x >> robots[i].l;
    }
    
    sort(robots.begin(), robots.end(), cmp);
    
    int count = 1;
    int curr_end = robots[0].x + robots[0].l;
    
    for (int i = 1; i < n; i++) {
        if (robots[i].x - robots[i].l >= curr_end) {
            count++;
            curr_end = robots[i].x + robots[i].l;
        }
    }
    
    cout << count << endl;
    
    return 0;
}