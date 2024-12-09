#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    long long totalRectangles = 0;
    vector<pair<long long, long long>> rectangles;

    for (int i = 0; i < n; i++) {
        long long a, b, c;
        cin >> a >> b >> c;
        totalRectangles += c;
        rectangles.push_back({a, b});
    }

    long long count = 0;
    for (pair<long long, long long> rect : rectangles) {
        long long a = rect.first;
        long long b = rect.second;
        long long possible = totalRectangles / a;

        if (totalRectangles % a == 0) {
            if (find(rectangles.begin(), rectangles.end(), make_pair(a, possible)) != rectangles.end()) {
                count++;
            }
        }
        
        if (a != b) {
            possible = totalRectangles / b;
            if (totalRectangles % b == 0) {
                if (find(rectangles.begin(), rectangles.end(), make_pair(b, possible)) != rectangles.end()) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}