#include <iostream>
#include <vector>

using namespace std;

struct Segment {
    int left, right;
};

double calculateArea(int n, int h, int f, vector<Segment>& segments) {
    double totalArea = 2 * f * f;
    
    for (int i = 0; i < n; i++) {
        double area = 0;
        if (segments[i].right < -f || segments[i].left > f) {
            area = segments[i].right - segments[i].left;
        } else if (segments[i].left >= -f && segments[i].right <= f) {
            continue;
        } else {
            double d = (f * f - h * h) / (2 * f);
            if (segments[i].left >= -f && segments[i].right <= f) {
                area = segments[i].right - segments[i].left;
            } else if (segments[i].left < -f && segments[i].right <= f) {
                area = segments[i].right - f - segments[i].left;
            } else if (segments[i].left >= -f && segments[i].right > f) {
                area = segments[i].right - (-f) - segments[i].left;
            }
            area += d * 2;
        }
        totalArea -= area;
    }
    
    return totalArea;
}

int main() {
    int n, h, f;
    cin >> n >> h >> f;
    
    vector<Segment> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].left >> segments[i].right;
    }
    
    double result = calculateArea(n, h, f, segments);
    cout << fixed << result << endl;
    
    return 0;
}