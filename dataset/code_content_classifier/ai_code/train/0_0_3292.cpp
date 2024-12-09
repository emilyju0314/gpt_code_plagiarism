
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

bool isPalindromePair(string s1, string s2) {
    string concat = s1 + s2;
    unordered_map<char, int> freq;
    for(int i=0; i<concat.length(); i++) {
        freq[concat[i]]++;
    }
    int odd_count = 0;
    for(auto it = freq.begin(); it != freq.end(); ++it) {
        if(it->second % 2 != 0)
            odd_count++;
    }
    if(odd_count > 1)
        return false;
    return true;
}

int main() {
    int N;
    cin >> N;

    vector<string> arr(N);
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            if(isPalindromePair(arr[i], arr[j]))
                count++;
        }
    }

    cout << count << endl;

    return 0;
}