#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

vector<string> findMinimumLanguages(int N, int M) {
    unordered_set<string> allLanguages;
    vector<unordered_set<string>> studentLanguages(M);
    
    for (int i = 0; i < N; i++) {
        string language;
        cin >> language;
        allLanguages.insert(language);
    }
    
    for (int i = 0; i < M; i++) {
        int Ki;
        cin >> Ki;
        for (int j = 0; j < Ki; j++) {
            string language;
            cin >> language;
            studentLanguages[i].insert(language);
        }
    }
    
    unordered_set<string> commonLanguages;
    for (string language : allLanguages) {
        bool isCommonLanguage = true;
        for (int i = 0; i < M; i++) {
            if (studentLanguages[i].find(language) == studentLanguages[i].end()) {
                isCommonLanguage = false;
                break;
            }
        }
        if (isCommonLanguage) {
            commonLanguages.insert(language);
        }
    }
    
    vector<string> result;
    if (commonLanguages.size() <= 5) {
        for (string language : commonLanguages) {
            result.push_back(language);
        }
        sort(result.begin(), result.end());
    } else {
        result.push_back("Impossible");
    }
    
    return result;
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }
        
        vector<string> minimumLanguages = findMinimumLanguages(N, M);
        
        if (minimumLanguages[0] == "Impossible") {
            cout << "Impossible" << endl;
        } else {
            cout << minimumLanguages.size() << endl;
            for (string language : minimumLanguages) {
                cout << language << endl;
            }
        }
        
        cout << endl;
    }
    
    return 0;
}