#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    double x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double calcDistance(vector<vector<Point>>& rooms, int currentRoom, int startRoom, vector<bool>& visited) {
    visited[currentRoom] = true;
    int n = rooms.size();
    double totalDistance = 0;
    
    int closestRoom = -1;
    double minDist = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && i != currentRoom) {
            double dist = distance(rooms[currentRoom][0], rooms[i][0]);
            if (dist < minDist) {
                minDist = dist;
                closestRoom = i;
            }
        }
    }
    
    if (closestRoom != -1) {
        totalDistance += minDist;
        totalDistance += calcDistance(rooms, closestRoom, startRoom, visited);
    } else {
        totalDistance += distance(rooms[currentRoom][0], rooms[startRoom][0]);
    }
    
    return totalDistance;
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<Point>> rooms(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        
        for (int j = 0; j <= p; j++) {
            Point point;
            cin >> point.x >> point.y;
            rooms[i].push_back(point);
        }
    }
    
    vector<bool> visited(n, false);
    
    double minDistance = calcDistance(rooms, m-1, m-1, visited);
    
    cout << minDistance << endl;
    
    return 0;
}