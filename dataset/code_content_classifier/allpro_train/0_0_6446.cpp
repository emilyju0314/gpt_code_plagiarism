#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

const double eps = 1e-9;

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

double P(double d, double R) {
    return exp(-d*d/(2*R*R));
}

double calculateFailProbability(int N, int K, int E, int X0, int Y0, vector<pair<int,int>>& enemyObjects, double R) {
    vector<double> distances;
    for(auto obj : enemyObjects) {
        double d = dist(X0, Y0, obj.first, obj.second);
        distances.push_back(d);
    }
    
    sort(distances.begin(), distances.end());
    
    double failProb = 0.0;
    
    for(int i=K; i<N; i++) {
        double prob = P(distances[i], R);
        failProb = max(failProb, prob);
    }
    
    return failProb;
}

double binarySearch(int N, int K, int E, int X0, int Y0, vector<pair<int,int>>& enemyObjects) {
    double low = 0.0, high = 2000.0;
    
    while(high-low > eps) {
        double mid = low + (high-low)/2.0;
        
        double failProb = calculateFailProbability(N, K, E, X0, Y0, enemyObjects, mid);
        
        if(failProb < (double)E/1000.0) {
            high = mid;
        } else {
            low = mid;
        }
    }
    
    return low;
}

int main() {
    int N, K, E, X0, Y0;
    cin >> N;
    cin >> K >> E;
    cin >> X0 >> Y0;
    
    vector<pair<int,int>> enemyObjects;
    
    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        enemyObjects.push_back({x, y});
    }
    
    double result = binarySearch(N, K, E, X0, Y0, enemyObjects);
    
    cout << fixed << setprecision(20) << result << endl;
    
    return 0;
}