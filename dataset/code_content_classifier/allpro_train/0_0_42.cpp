#include <iostream>
#include <string>

using namespace std;

bool solveRebus(string rebus, int n) {
    int sum = 0;
    int count = 0;
    
    for(int i = 0; i < rebus.size(); i++) {
        if(rebus[i] == '?') {
            count++;
        } else if(isspace(rebus[i])) {
            continue;
        } else {
            if(rebus[i] == '+') {
                sum += n / count;
            } else if(rebus[i] == '-') {
                sum -= n / count;
            }
            count = 0;
        }
    }
    
    return sum == n;
}

int main() {
    string rebus;
    getline(cin, rebus);
    
    int n;
    cin >> n;

    if(solveRebus(rebus, n)) {
        cout << "Possible" << endl;
        int num = 1;
        for(int i = 0; i < rebus.size(); i++) {
            if(rebus[i] == '?') {
                cout << num;
                num++;
            } else {
                cout << rebus[i];
            }
        }
    } else {
        cout << "Impossible" << endl;
    }
    
    return 0;
}