#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<int> ai(n);
    vector<int> bi(m);
    vector<int> li(m);

    for (int i = 0; i < n; i++) {
        cin >> ai[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> bi[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> li[i];
    }

    int min_dist = INT_MAX;
    int left_point = 1;
    int right_point = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            double dist = sqrt(pow(a,2) + pow(ai[i],2)) + sqrt(pow(b-a,2) + pow(bi[j]-ai[i],2)) + li[j];
            if (dist < min_dist) {
                min_dist = dist;
                left_point = i+1;
                right_point = j+1;
            }
        }
    }

    cout << left_point << " " << right_point << endl;

    return 0;
}