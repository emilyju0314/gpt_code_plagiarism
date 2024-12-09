#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d, a, b;
    cin >> n >> d;
    cin >> a >> b;
    
    vector<pair<int, int>> clients;
    
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        clients.push_back(make_pair(x, y));
    }
    
    vector<int> serve_clients;
    int max_clients = 0;
    
    for (int i = 0; i < n; i++) {
        if (clients[i].first * a + clients[i].second * b <= d) {
            serve_clients.push_back(i+1);
        }
    }
    
    max_clients = serve_clients.size();

    cout << max_clients << endl;
    for (int i = 0; i < serve_clients.size(); i++) {
        cout << serve_clients[i] << " ";
    }
    
    return 0;
}