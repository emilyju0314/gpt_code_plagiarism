#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> contactLists(n);
    for(int i = 0; i < n; i++) {
        cin >> contactLists[i];
    }

    vector<int> messagesExpected(n);
    for(int i = 0; i < n; i++) {
        cin >> messagesExpected[i];
    }

    vector<int> employeeCounts(n, 0);
    vector<int> employeesToJoin;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(contactLists[j][i] == '1') {
                employeeCounts[i]++;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        if(employeeCounts[i] == messagesExpected[i]) {
            employeesToJoin.push_back(i+1);
        }
    }

    cout << employeesToJoin.size() << endl;
    for(int i = 0; i < employeesToJoin.size(); i++) {
        cout << employeesToJoin[i] << " ";
    }

    return 0;
}