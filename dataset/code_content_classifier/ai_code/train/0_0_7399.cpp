#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, M, T;
    cin >> n >> M >> T;

    vector<string> queries(n);
    for(int i = 0; i < n; i++) {
        cin >> queries[i];
    }

    map<string, int> userIDs;
    vector<int> result;
    int count = 0;
    for(int i = 0; i < n; i++) {
        string query = queries[i];
        bool assigned = false;
        for(auto& entry : userIDs) {
            if(entry.second <= i && i - entry.second < M) {
                userIDs[query] = entry.second;
                result.push_back(entry.second);
                assigned = true;
                break;
            }
        }
        if(!assigned) {
            userIDs[query] = count;
            result.push_back(count);
            count++;
        }
    }

    if(count > M) {
        cout << "No solution" << endl;
    } else {
        cout << count << endl;
        for(auto id : result) {
            cout << id + 1 << endl;
        }
    }

    return 0;
}