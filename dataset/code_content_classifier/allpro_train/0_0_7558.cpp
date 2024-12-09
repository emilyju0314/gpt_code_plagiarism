#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isAM(string time) {
    return time.find("a.m.") != string::npos;
}

bool isPM(string time) {
    return time.find("p.m.") != string::npos;
}

int main() {
    int n;
    cin >> n;
    
    vector<string> recordings;
    
    for(int i = 0; i < n; i++) {
        string time;
        cin.ignore();
        getline(cin, time);
        recordings.push_back(time);
    }
    
    sort(recordings.begin(), recordings.end());
    
    int days = 1;
    for(int i = 1; i < n; i++) {
        if(isAM(recordings[i-1]) && isPM(recordings[i])) {
            days++;
        } else if(!isAM(recordings[i-1]) && !isPM(recordings[i])) {
            days++;
        }
    }
    
    cout << days << endl;
    
    return 0;
}