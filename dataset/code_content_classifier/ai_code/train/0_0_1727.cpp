#include <iostream>
#include <vector>

using namespace std;

struct Word {
    int letters;
    int modifies;
    int cost;
};

int main() {
    int N;
    cin >> N;
    
    vector<Word> words(N);
    
    for (int i = 0; i < N; i++) {
        int letters, modifies;
        cin >> letters >> modifies;
        words[i].letters = letters;
        words[i].modifies = modifies;
    }
    
    int totalCost = 0;
    
    for (int i = 0; i < N; i++) {
        int currCost = 0;
        int j = i;
        while (words[j].modifies != -1) {
            currCost += words[j].letters;
            currCost += abs(words[j].modifies - j);
            j = words[j].modifies;
        }
        
        totalCost += currCost;
    }
    
    cout << totalCost << endl;
    
    return 0;
}