#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    int n, m, a, d;
    cin >> n >> m >> a >> d;

    vector<long long> clients(m);
    for(int i = 0; i < m; i++) {
        cin >> clients[i];
    }

    sort(clients.begin(), clients.end());

    long long doorOpenings = 0;
    long long doorClosingTime = 0;
    long long employeesArrivalTime = 1;

    for(int i = 0; i < m; i++) {
        long long clientArrivalTime = clients[i];
        if(clientArrivalTime >= employeesArrivalTime && clientArrivalTime - employeesArrivalTime < a + doorClosingTime) {
            employeesArrivalTime = clientArrivalTime + a;
        } else {
            doorOpenings++;
            long long closingElapsedTime = max(employeesArrivalTime, doorClosingTime) - doorClosingTime;
            doorClosingTime += closingElapsedTime - closingElapsedTime % d + d;
            employeesArrivalTime = employeesArrivalTime + a;
        }
    }

    cout << doorOpenings;

    return 0;
}