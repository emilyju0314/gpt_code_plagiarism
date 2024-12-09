#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    unordered_map<string, int> verdictCount;
    verdictCount["AC"] = 0;
    verdictCount["WA"] = 0;
    verdictCount["TLE"] = 0;
    verdictCount["RE"] = 0;
    
    for (int i = 0; i < N; i++) {
        string verdict;
        cin >> verdict;
        verdictCount[verdict]++;
    }
    
    cout << "AC x " << verdictCount["AC"] << endl;
    cout << "WA x " << verdictCount["WA"] << endl;
    cout << "TLE x " << verdictCount["TLE"] << endl;
    cout << "RE x " << verdictCount["RE"] << endl;
    
    return 0;
}