#include <iostream>
using namespace std;

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    cout.flush();
    int dist;
    cin >> dist;
    return dist;
}

int main() {
    int x1, y1, x2, y2;

    // Find the smallest x coordinate
    int lo = 1, hi = 10^9;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int dist = query(mid, 1);
        if (dist != -1) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    x1 = lo;

    // Find the smallest y coordinate
    lo = 1, hi = 10^9;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int dist = query(1, mid);
        if (dist != -1) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    y1 = lo;

    // Find the largest x coordinate
    lo = x1 + 1, hi = 10^9;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int dist = query(mid, 10^9);
        if (dist != -1) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    x2 = lo - 1;

    // Find the largest y coordinate
    lo = y1 + 1, hi = 10^9;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int dist = query(10^9, mid);
        if (dist != -1) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    y2 = lo - 1;

    // Output the result
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cout.flush();

    return 0;
}