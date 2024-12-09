#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double euclideanDistance(Point a, Point b) {
    return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main() {
    int n, k;
    cin >> n >> k;

    Point central = {0, 0};
    priority_queue<double> pq;
    double totalSum = 0.0;

    for(int i=0; i<n; i++) {
        Point base;
        cin >> base.x >> base.y;
        
        double dist = euclideanDistance(base, central);
        totalSum += dist;
        pq.push(dist);
    }

    double maxSum = 0.0;
    int remainingBases = n;

    for(int i=0; i<k; i++) {
        double dist = pq.top();
        pq.pop();
        
        remainingBases--;
        totalSum -= 2*dist; // Removing both incoming and outgoing distance to the removed base

        double sum = totalSum + remainingBases*pq.top();
        maxSum = max(maxSum, sum);
    }

    cout << fixed;
    cout.precision(8);
    cout << maxSum << endl;

    return 0;
}